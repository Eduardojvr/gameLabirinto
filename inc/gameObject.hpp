#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
class GameObject{
private:
  int x;
  int y;
  char objeto;
public:
  GameObject();
  void setX(int x);
  int getX();
  void setY(int y);
  int getY();
  char getObjeto();
  void setObjeto(char o);
  void escolherPlayer();
};
#endif
