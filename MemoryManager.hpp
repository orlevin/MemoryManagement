#ifndef _MEMORY_MANAGER
#define _MEMORY_MANAGER

#include <iostream>
#include "MemPool.hpp"
#include "LinkedList.hpp"

using namespace std;

class MemoryManager {
    
    private:
     
        MemPool* mPool;
               
        
    public:
    
        LinkedList freeList[20]; 
        int progress;
        MemoryManager();
        void initializePool(int size);
        void* getAChunk(int size);
        void freeChunk(void* ptr);

    
};

#endif