#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"
#include "memory.h"
#include <cstring>
#include <fstream>
#include "Thread.h"
#include <string>

#define MAXSIZE 100

using namespace std;
char ffile[MAXSIZE];

int DebugZero(CPU8080 &theCPU, GTUOS theOS, int DEBUG);
int DebugOne(CPU8080 &theCPU, GTUOS theOS, int DEBUG);
int DebugTwo(CPU8080 &theCPU, GTUOS theOS, int DEBUG);
int DebugThree(CPU8080 &theCPU, GTUOS theOS, int DEBUG, string fileName);
void saveMemory(memory mem, string fileName);


int main (int argc, char**argv){

	if (argc != 3){
		std::cerr << "Usage: prog exeFile debugOption\n";
		exit(1); 
	}

	int DEBUG = atoi(argv[2]);
	int cycle = 0;
	sprintf(ffile, "%s", argv[1]);
	
	memory mem;
	CPU8080 theCPU(&mem);
	GTUOS	theOS(&theCPU, argv[1]);

	theCPU.ReadFileIntoMemoryAt(argv[1], 0x0000);	

	char fileName[MAXSIZE];
	sprintf(fileName, "%s", argv[1]);

	char *token;
	token = strtok(fileName, ".");

	switch(DEBUG){
		case 0:
			cout << "DEBUG MODE 0" << endl << endl;
			cycle = DebugZero(theCPU, theOS, DEBUG);
			break;
		case 1:
			cout << "DEBUG MODE 1" << endl << endl;
			cycle = DebugOne(theCPU, theOS, DEBUG);
			break;
		case 2:
			cout << "DEBUG MODE 2" << endl << endl;
			cycle = DebugTwo(theCPU, theOS, DEBUG);
			break;
		case 3:
			cout << "DEBUG MODE 3" << endl << endl;
			char file[MAXSIZE];
			sprintf(file, "%s_threadInfos.txt", token);//Bunu kontrol et, bu hata verir!
			cycle = DebugThree(theCPU, theOS, DEBUG, file);
			break;
		default:
			cout << "INVALID DEBUG MODE " << endl << endl;
			break;

	}

	char fileMemeory[MAXSIZE];
	sprintf(fileMemeory, "%s.mem", token);
	theOS.saveMemory(fileMemeory, theCPU);
	cout << "Total number of cycles " << cycle << endl;

	return 0;
}


int DebugZero(CPU8080 &theCPU, GTUOS theOS, int DEBUG){
	int cycle = 0;

	do{
		theCPU.Emulate8080p(DEBUG);
		if(theCPU.isSystemCall()){
			theOS.handleCall(theCPU, theOS);
	    	cycle += theOS.calculateCycle(theCPU);
			cout << "Cycles " << cycle << endl;
		}
		if(theCPU.isHalted()){

			theOS.runningThread = theOS.runningThread - 1;
			char* file = theOS.changeProgramforState(theCPU);
			theCPU.ReadFileIntoMemoryAt(theOS.threadTable[theOS.tableIndex]->getFileCom(), 0x0000);

		}

    }while (!theOS.isFinish());

    return cycle;
}


int DebugOne(CPU8080 &theCPU, GTUOS	theOS, int DEBUG){
	int cycle = 0;

	do{
		theCPU.Emulate8080p(DEBUG);
		if(theCPU.isSystemCall()){
			theOS.handleCall(theCPU, theOS);
			cycle += theOS.calculateCycle(theCPU);
			cout << "Cycles " << cycle << endl;
		}

		if(theCPU.isHalted()){
			theOS.runningThread = theOS.runningThread - 1;
			char* file = theOS.changeProgramforState(theCPU);
			theCPU.ReadFileIntoMemoryAt(theOS.threadTable[theOS.tableIndex]->getFileCom(), 0x0000);

		}
		
    }while (!theOS.isFinish());

    return cycle;
}

int DebugTwo(CPU8080 &theCPU, GTUOS	theOS, int DEBUG){
	int cycle = 0;

	do{
		theCPU.Emulate8080p(DEBUG);
		if(theCPU.isSystemCall()){
			theOS.handleCall(theCPU, theOS);
		    cycle += theOS.calculateCycle(theCPU);
			cout << "Cycles " << cycle << endl;
		}
		cin.get(); /*enter girilmesini bekliyor*/

		if(theCPU.isHalted()){
			cout << "ishalt" << endl << endl;
			theOS.runningThread = theOS.runningThread - 1;
			char* file = theOS.changeProgramforState(theCPU);
			theCPU.ReadFileIntoMemoryAt(theOS.threadTable[theOS.tableIndex]->getFileCom(), 0x0000);
		}
		
    }while (!theOS.isFinish());

    return cycle;
}


int DebugThree(CPU8080 &theCPU, GTUOS	theOS, int DEBUG, string fileName){
	int cycle = 0;

	do{
		theCPU.Emulate8080p(DEBUG);
		if(theCPU.isSystemCall()){
			theOS.handleCall(theCPU, theOS);
			theOS.printThreadTable();
			cycle += theOS.calculateCycle(theCPU);
			cout << "Cycles " << cycle << endl;
		}
		if(theCPU.isHalted()){
			theOS.runningThread = theOS.runningThread - 1;
			char* file = theOS.changeProgramforState(theCPU);
			theCPU.ReadFileIntoMemoryAt(theOS.threadTable[theOS.tableIndex]->getFileCom(), 0x0000);

		}
		
    }while (!theOS.isFinish());

    theOS.saveThreadInfos(fileName);

    return cycle;
}