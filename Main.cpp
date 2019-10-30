#include <iostream>
#include <cstring>
#include "MemoryManager.hpp"
#include "MemPool.hpp"
#include "LinkedList.hpp"
#include "Object.cpp"
#include "Block.hpp"
using namespace std;

MemoryManager mm;

/** Time complexity O(n) , Strategy - Given a size ceiled to the square of 2, Check the corresponding
 * linkedlist, If exist pop the first node, if not try and allocate space from the memory pool **/


int main(int argc, char *argv[]) {
    
    int heapSize = 0;
    
    if (!strcmp(argv[1],"-S")) {
        heapSize = atoi(argv[2]);
    }
    mm.initializePool(heapSize);
    
    Object* obj1 = new Object;
    Object* obj2 = new Object;
    Object* obj3 = new Object;
    Object* obj4 = new Object;
        
    delete(obj1);
    delete(obj2);
    delete(obj3);
    delete(obj4);
    

    Object* objects = new Object[5];
    delete[](objects);
    
    
    int* inter = new int[20000];
    delete[](inter);
    
    
    MemPool::getInstance()->freeMemoryPool();
}