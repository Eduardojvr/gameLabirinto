#ifndef MENU_HPP
#define  MENU_HPP
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "player.hpp"
#include "registros.hpp"
using namespace std;
class Menu{
  bool aberto;
public:
  void setAberto(bool aberto);
  bool getAberto();
  int menuJogo(Player * jog,Registros * reg,int cont,int so );
};
#endif
