#Alex Paquette
#2-Oct-2023

CC=g++
CPPFILES = Semaphore.cpp Barrier.cpp main.cpp
HFILES = Barrier.h Semaphore.h
OBJFILES = Barrier.o main.o Semaphore.o
CFLAGS = -Wall -std=c++11 -pthread -I.

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

#BARRIER: $(CPPFILES)
#	$(CC) $(CPPFILES) $(CFLAGS)

ALL: $(OBJFILES) $(HFILES)
	$(CC) -o barrier $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm *.o

INSTALL:
	cp ./barrier /usr/bin/barrier