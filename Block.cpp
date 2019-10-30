#include <iostream>
#include "Block.hpp"
    
 
 void Block::setNextBlock(Block* nextBlock) {
     this->nextBlock = nextBlock;
 }
 
 Block* Block::getNextBlock() {
     return nextBlock;
 }
 void Block::setPower(int power) {
     this-> power = power;
 }
 int Block::getPower() {
     return power;
 }