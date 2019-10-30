
#ifndef _BLOCK
#define _BLOCK

class Block {
    
  private:
    char* pointer;
    int power;
    Block* nextBlock;
  
  public:
    
    Block(char* pointer);
    void setNextBlock(Block* nextBlock);
    void setPointer(char* ptr);
    void setPower(int power);
    int getPower();
    Block* getNextBlock();
    char* getPointer();
};

#endif