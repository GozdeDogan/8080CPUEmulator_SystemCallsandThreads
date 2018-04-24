#ifndef H_THREAD
#define H_THREAD

#include <string>
#include "8080emuCPP.h"
#include "memory.h"
#include <string>

#define MAXSIZE 100

using namespace std;

enum ThreadState{READY, BLOCKED, RUNNING};

class Thread
{
	public:
		Thread();
		~Thread();

		void initializeThread(int threadID, char file[MAXSIZE], State8080 state);

		void setState8080(State8080 state);
		State8080 getState8080();
		void initializeState8080();

		void setThreadID(uint16_t ThreadID);
		uint16_t getThreadID();

		void setCurrentCycle(uint64_t currCycle);
		uint64_t getCurrentCycle();

		void setNumOfCycle(uint64_t numOfCycles);
		uint64_t getNumOfCycle();

		void setState(ThreadState state);
		ThreadState getState();

		void setStartAddress(uint32_t startAddress);
		uint32_t getStartAddress();

		void setStackState(bool stackState);
		bool getStackState();

		bool isAlive();
		void setAlive(int alive);
		int getAlive();

		void setFileCom(char file[MAXSIZE]);
		char* getFileCom();

		void operator =(const Thread &thread);

	private:
		State8080 state8080;    // saved registers like a,b,c,sp,pc
		uint32_t baseReg;
		uint16_t ThreadID;
		uint64_t currentCycle;
		uint64_t numOfCycles;
		ThreadState state;
		uint32_t startAddress;
		bool stackState;
		int alive;
		char fileCom[MAXSIZE];
	
};


#endif