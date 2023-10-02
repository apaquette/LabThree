CC=g++
FLAGS= -Wall -o barrier
FILES = Semaphore.cpp Barrier.cpp main.cpp

%.o: %.cpp
	$(CC) -c -o $@ $< $(FLAGS) $(DEBUGFLAGS)

BARRIER: $(FILES)
	$(CC) $(FILES) $(FLAGS)

ALL: $(FILES)
	$(CC) $(FILES) $(FLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm *.o
