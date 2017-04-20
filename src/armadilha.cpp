#include "armadilha.hpp"

Armadilha::Armadilha(){
  setX(3);
  setY(0);
  perda=1;
  setObjeto('X');
}
Armadilha::~Armadilha(){}
void Armadilha::setPerda(int perda){
  this->perda = perda;
}

int Armadilha::getPerda(){
  return this->perda;
}
void Armadilha::escolherPlayer(){
  setObjeto('X');
}
