#include "armadilha.hpp"

Armadilha::Armadilha(){
  setX(3);
  setY(0);
  setObjeto('X');
}
void Armadilha::setPerda(int p){
  this->perda = getPerda()-3;
}

int Armadilha::getPerda(){
  return this->perda;
}
void Armadilha::escolherPlayer(){
}
