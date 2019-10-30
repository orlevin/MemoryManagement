#include <iostream>
#include <cstdlib>
#include <cmath>
#include "MemPool.hpp"
  
  using namespace std;
  
  /** Singleton - create and return an instance of MemPool **/
  MemPool* MemPool::getInstance() {
    if (instance == nullptr) {
      instance = (MemPool*) malloc(sizeof(MemPool));
      instance->lastAddress = nullptr;
      instance->charArray = nullptr;
      instance->lastValidAddress = nullptr;
    }
    return instance;
  }
  
  MemPool::MemPool() : lastValidAddress(nullptr) , charArray(nullptr) {
   
  } 
  
  char* MemPool::getLastValidAddress() {
      return lastValidAddress;    
  }
  char* MemPool::getLastAddress() {
    return lastAddress;
  }
  char* MemPool::getStartingAddress() {
    return charArray;
  }
  void MemPool::incrementLastValidAddress(int size) {
      lastValidAddress += size;
  }
  /** Initialize the MemPool with allocated heap memory **/
  void MemPool::initialize(int size) {
    
     charArray = (char*)malloc(size+1111);
     lastValidAddress = charArray;
     lastAddress = charArray + size;
  }
 
 /** Free the allocations from the heap **/
  void MemPool::freeMemoryPool() {
    free(charArray);
    free(instance);
  }
  
  
  MemPool* MemPool::instance = nullptr;   