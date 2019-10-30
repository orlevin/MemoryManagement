#include <iostream>
#include "MemPool.hpp"
#include "MemoryManager.hpp"
using namespace std;

extern MemoryManager mm;

void* operator new(std::size_t size) {
    return  mm.getAChunk(size);;
}
void* operator new[](size_t count) {
     void* chunk = mm.getAChunk(count); 
}
void operator delete[](void* ptr) {
     mm.freeChunk(ptr);
}
void operator delete(void* ptr) {
     mm.freeChunk(ptr);
}