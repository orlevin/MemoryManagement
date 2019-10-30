#include <iostream>
#include <cmath>
#include <typeinfo>
#include "MemoryManager.hpp"
#include "MemPool.hpp"

    using namespace std;
    
    MemoryManager::MemoryManager() {
        mPool = MemPool::getInstance();
    }
    
    void MemoryManager::initializePool(int size) {
        mPool->initialize(size);
    }
 
    /** Free the pointer deleted by the user - add it to the free list **/
    void MemoryManager::freeChunk(void* ptr) {
        
        char* currAddress = (char*)ptr;
        
        currAddress = currAddress - sizeof(Block);
        Block* block = (Block*) currAddress;
        
        freeList[block->getPower()].addNode(block);
        
    }
    /** Check in the linked list whether there exist a block with large enough space and return it
     * if exist , otherwise check if there is enough space in the memory pool and if so allocate and return
     * a pointer with the allocation to the user **/
    void* MemoryManager::getAChunk(int size) {
        char* chunkToReturn = nullptr;
        
        int power = ceil(log2(size));
        int storageSpace = pow(2,power);
        
        Block* popedBlock = freeList[power].popFirstBlock();
        
        if (popedBlock==nullptr) {
            int sizer = mPool->getLastAddress() - mPool->getLastValidAddress();
            
            if ( sizer > storageSpace+sizeof(Block) ) {
                
                char* currAddress = mPool->getLastValidAddress();
                Block* block = (Block*)currAddress;
                block->setPower(power);
                block->setNextBlock(nullptr);
                
                currAddress += sizeof(Block);
                chunkToReturn = currAddress;
                
                mPool->incrementLastValidAddress(storageSpace+sizeof(Block));
                
            } else {
                cout << "- Could not allocate space -" << endl;
            }
        } else {
            cout << "Using existing block " << endl;
            
            char* addrToReturn = (char*) popedBlock;
            addrToReturn += sizeof(Block);
            chunkToReturn = addrToReturn;
        }
        
        return chunkToReturn;
    }