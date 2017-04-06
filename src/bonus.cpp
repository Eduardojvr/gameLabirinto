#include "bonus.hpp"


void Bonus::setBonus(int b){
  this->bonus = b;
}
int Bonus::getBonus(){
  return this->bonus;
}
void Bonus::escolherPlayer(){
  setObjeto('+');
}
