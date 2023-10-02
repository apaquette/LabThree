#Alex Paquette
#2-Oct-2023

CC=g++
CPPFILES = Semaphore.cpp Barrier.cpp main.cpp
HFILES = Barrier.h Semaphore.h
OBJFILES = Barrioer.o main.o Semaphore.o
CFLAGS = -Wall -o barrier

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

BARRIER: $(CPPFILES)
	$(CC) $(CPPFILES) $(CFLAGS)

ALL: $(OBJFILES) $(HFILES)
	$(CC) $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm *.o
