#include "desenha.hpp"

void Desenha::draw(char ** m,Player * jog){
  for(int s=0;s<17;s++){
    for(int j=0;j<73;j++){
      if(m[s][j] != '-' && m[s][j]!='B'){
        printw("%c",m[s][j]);
      }else{
        printw(" ");
      }
    }
    printw("\n");
  }
  printw("\n________________________________________\nPontos:         %d\nVidas:          %d\nPersonagem:     %c\n________________________________________\n",jog->getPontos(),jog->getVidas(),jog->getObjeto());
}
