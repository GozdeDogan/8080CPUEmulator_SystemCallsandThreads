#ifndef H_GTUOS
#define H_GTUOS

#include <string>
#include <queue>
#include "8080emuCPP.h"
#include "memory.h"
#include "Thread.h"
#include <string>

#define MAX_THREAD_COUNT 10
#define MAX_PATH_LEN 255
#define CS_CYCLE 100 // thread switch cycles

using namespace std;


struct QueueElm
{
	Thread thread;
	uint32_t address;
};

class GTUOS{
	public:
		Thread *threadTable[MAX_THREAD_COUNT];
		int tableIndex = 0;	    

	    /* round robin icin eklendiler, quantum cycle'a gore bu queue'lara ekleme yapilir */
	    queue <QueueElm> readyQueue;
	    queue <QueueElm> blockedQueue;


	    GTUOS(CPU8080 *cpu, char file[MAX_PATH_LEN]);
		uint64_t handleCall(CPU8080 & cpu, GTUOS & theOS);
		int calculateCycle(CPU8080 & cpu); 
		void PRINT_B(CPU8080 & cpu);
		void READ_B(CPU8080 & cpu);
		void PRINT_MEM(CPU8080 & cpu);
		void READ_MEM(CPU8080 & cpu);
		void PRINT_STR(CPU8080 & cpu);
		void READ_STR(CPU8080 & cpu);
		void GET_RND(CPU8080 & cpu);
		void saveMemory(char *filename, CPU8080& cpu);
		uint8_t TCreate(CPU8080 & cpu);
		void TJoin(CPU8080 & cpu);
		void TExit(CPU8080 & cpu);
		void TYield(CPU8080 & cpu);
		void printThreadTable();
		void saveThreadInfos(string& filename);
		void threadSwitch(uint8_t t1, uint8_t t2);
		void printThreadInformations(uint64_t ind);
		char* changeProgramforState(CPU8080 &cpu);
		bool isFinish();

		/* queue'larin bos olup olmadigini kontrol eden fonksiyonlar */
		bool isEmptyReadyQueue();
		bool isEmptyBlockedQueue();
		/* queue'lara eleman ekleyen fonksiyonlar */
		void addEllmInReadyQueue(Thread thread, uint32_t addr);
		void addElmInBlockedQueue(Thread thread, uint32_t addr);
		/* queue'lara ekelenen ilk elemani alirlar */
		QueueElm getElmReadyQueue();
		QueueElm getElmBlockedQueue();

		int threadID = 1;
		int runningThread = 1;
};

#endif
