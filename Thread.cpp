#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"
#include <cstring>
#include <fstream>
#include <cmath>
#include "Thread.h"
#include <string>

#define MAXSIZE 100

using namespace std;

Thread::Thread(){
	initializeState8080();
	this->ThreadID = -1;
	this->currentCycle = 0;
	this->numOfCycles = 0;
	this->state = RUNNING;
	this->startAddress = 0x0000;
	this->alive = 1;
	sprintf(fileCom, "\0");
}

Thread::~Thread(){
	this->alive = 0;
}

void Thread::initializeThread(int threadID, char file[MAXSIZE], State8080 state){
	this->setState8080(state);
	this->setThreadID(threadID);
	this->setCurrentCycle(0);
	this->setNumOfCycle(0);
	this->setState(RUNNING);
	this->setStartAddress(0x4000);
	this->setAlive(1);
	this->setFileCom(file);
}

void Thread::setState8080(State8080 state){
	this->state8080 = state;
}

State8080 Thread::getState8080(){
	return this->state8080;
}

void Thread::initializeState8080(){
	this->state8080.a=0;
    this->state8080.b=0;
    this->state8080.c=0;
    this->state8080.d=0;
    this->state8080.e=0;
    this->state8080.h=0;
    this->state8080.l=0;
    this->state8080.int_enable=0;
    this->state8080.sp=0x4000-1;
    this->state8080.pc=0;
    this->state8080.cc.ac=0;
    this->state8080.cc.cy=0;
    this->state8080.cc.pad=0;
    this->state8080.cc.pad2=0;
    this->state8080.cc.pad3=0;
    this->state8080.cc.s=0;
    this->state8080.cc.z=0;
    this->state8080.cc.p = 0;
}

void Thread::setThreadID(uint16_t ThreadID){
	this->ThreadID = ThreadID;
}

uint16_t Thread::getThreadID(){
	return this->ThreadID;
}

void Thread::setCurrentCycle(uint64_t currCycle){
	this->currentCycle = currCycle;
}

uint64_t Thread::getCurrentCycle(){
	return this->currentCycle;
}

void Thread::setNumOfCycle(uint64_t numOfCycles){
	this->numOfCycles = numOfCycles;
}

uint64_t Thread::getNumOfCycle(){	
	return this->numOfCycles;
}

void Thread::setState(ThreadState state){
	this->state = state;
}

ThreadState Thread::getState(){
	return this->state;
}

void Thread::setStartAddress(uint32_t startAddress){
	this->startAddress = startAddress;
}

uint32_t Thread::getStartAddress(){
	return this->startAddress;
}

void Thread::setStackState(bool stackState){
	this->stackState = stackState;
}

bool Thread::getStackState(){
	return this->stackState;
}

bool Thread::isAlive(){
	if(alive == 1)
		return true;
	return false;
}

void Thread::setAlive(int alive){
	this->alive = alive;
}
		
int Thread::getAlive(){
	return this->alive;
}

void Thread::setFileCom(char file[MAXSIZE]){
	sprintf(this->fileCom, "%s", file);
}

char* Thread::getFileCom(){
	return this->fileCom;
}


void Thread::operator =(const Thread &thread){
	this->state8080 = (thread.state8080);
	this->ThreadID = thread.ThreadID;
	this->currentCycle = thread.currentCycle;
	this->numOfCycles = thread.numOfCycles;
	this->state = thread.state;
	this->startAddress = thread.startAddress;
	this->alive = thread.alive;
	sprintf(this->fileCom, "%s", thread.fileCom);
}