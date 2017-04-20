#ifndef MAPA_HPP
#define MAPA_HPP
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "player.hpp"
using namespace std;
class Mapa{
private:
  int linhas,colunas;
  //char mBase[17][73];
public:
  Mapa();
  ~Mapa();
int getLinhas();
int getColunas();
void lerMapa(char ** m);
void posicionaJog(Player * jog,char ** m);
};
#endif
