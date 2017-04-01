#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/armadilha.hpp"

void Armadilha::setPerda(int p){
  this->perda = getPerda()-1;
}
int Armadilha::getPerda(){
  return this->perda;
}
void Armadilha::escolherPlayer(){
    setObjeto('|');
}
