CC=g++
CFLAGS=-I.
DEPS = Thread.h gtuos.h memory.h 8080emuCPP.h memoryBase.h Thread.cpp gtuos.cpp 8080emu.cpp
OBJ = emulator.o


buildemulator:
	$(CC)  main.cpp $(DEPS) -o emulator.out $(CFLAGS) 

