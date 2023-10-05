#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/

/*! Barrier with parameter constructor*/
Barrier::Barrier(int ThreadCount){
  count = ThreadCount;
  threadNum = 0;
  condition = false;
  mutex = std::make_shared<Semaphore>(1);
  innerLock = std::make_shared<Semaphore>(0);//0 for closed
  outerLock = std::make_shared<Semaphore>(1);//1 for open
}
/*! Barrier deconstructor*/
Barrier::~Barrier(){ }//NOTHING TO DO

/*! returns count value*/
int Barrier::getCount(){
  return this->count;
}

/*! waits for all the threads before starting second half of code*/ 
void Barrier::waitForAll(){
  mutex->Wait();
  ++threadNum;
  if(threadNum == count){
    outerLock->Wait();//won't block because it's initialized to 1, 1 wait is allowed without blockign the code
    innerLock->Signal();
  }
  mutex->Signal();
  innerLock->Wait();
  innerLock->Signal();

  mutex->Wait();
  --threadNum;
  if(threadNum == 0){
    innerLock->Wait();
    outerLock->Signal();
  }
  mutex->Signal();
  outerLock->Wait();
  outerLock->Signal();
}