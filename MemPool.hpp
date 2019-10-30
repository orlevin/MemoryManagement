#ifndef _MEM_POOL
#define _MEM_POOL

class MemPool {
  
  private:
    
    char* lastAddress;
    char* lastValidAddress;
    char* charArray;
    static MemPool* instance;
    MemPool();
  
  public:
  
    static MemPool* getInstance();
    char* getLastValidAddress();
    char* getLastAddress();
    char* getStartingAddress();
    void incrementLastValidAddress(int size);
    void initialize(int size);
    void freeMemoryPool();
};

#endif