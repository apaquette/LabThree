#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutexSem and condition variables to implement a barrier using Semaphores with N number threads

*/

/*! Barrier constructor*/
Barrier::Barrier(){
  this->count = 0;
  threadNum = 0;
  condition = false;

  mutexSem = std::make_shared<Semaphore>(1);
  barrierSem=std::make_shared<Semaphore>(0);

}
/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){
  this->count = count;
  threadNum = 0;
  condition = false;
  std::shared_ptr<Semaphore> mutexSem(new Semaphore(1));
  std::shared_ptr<Semaphore> barrierSem(new Semaphore(0));
}
/*! Barrier deconstructor*/
Barrier::~Barrier(){ }

/*! sets count value*/
void Barrier::setCount(int x){
  this->count = x;
}
/*! returns count value*/
int Barrier::getCount(){
  return this->count;
}

/*! waits for all the threads before starting second half of code*/ 
void Barrier::waitForAll(){
  mutexSem->Wait();//N wait
  threadNum++;

  if(threadNum == count){
    barrierSem->Signal();//1 signal
    threadNum = 0;
  }
  mutexSem->Signal();//N signal
  barrierSem->Wait();//N waits
  barrierSem->Signal();//N signal (this needs to happen N-1 times)

  //result is N+1 signal for every N waits (need to solve this somehow)
}

