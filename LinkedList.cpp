#include <iostream>
#include "LinkedList.hpp"
#include "Block.hpp"

using namespace std;
  
  LinkedList::LinkedList() : head(nullptr) {
  }
  
  
  Block* LinkedList::popFirstBlock() {
     Block* toReturn = nullptr;
     
     if(head == nullptr) {
        //  cout << "A" << endl;
         return toReturn;
         
     }
     else if (head->getNextBlock() == nullptr) {
        //  cout << "B" << endl;
          toReturn = head;
          head = nullptr;
          return toReturn;
          
      } else {
        //   cout << "C" << endl;
          toReturn = head;
          head = head->getNextBlock();
      }
      return toReturn;
  }
  void LinkedList::addNode(Block* block) {
      if (head == nullptr) {
          head = block;
          return;
      }
      Block* it = head;
      while (it->getNextBlock() != nullptr) {
          it = it->getNextBlock();
      }
      it->setNextBlock(block);
  }
  void LinkedList::isEmpty() {
    //   cout << "printing " << endl;
  }