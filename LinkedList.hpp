#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Block.hpp"

class LinkedList {
    
  private:
    Block* head;  
  
  public:
  
  LinkedList();
  Block* popFirstBlock();
  void addNode(Block* block);
  void isEmpty();
  
};

#endif