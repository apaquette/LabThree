#include "Barrier.h"
#include <thread>
#include <vector>

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Barrier> barrierObj){
  std::cout << "first\n";
  barrierObj->waitForAll();
  std::cout << "second\n";
}

int main(void){
  /*!< An array of threads*/
  int threadCount = 5;
  std::vector<std::thread> threadArray(threadCount);
  /*!< Pointer to barrier object*/
  std::shared_ptr<Barrier> barrierObj(new Barrier(threadCount));
  for(unsigned long int i=0; i < threadArray.size(); ++i){
    threadArray[i]=std::thread(task,barrierObj);
  }
  for(unsigned long int i = 0; i < threadArray.size(); ++i){
    threadArray[i].join();
  }
  return 0;
}
