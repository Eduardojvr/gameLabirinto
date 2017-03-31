#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
class GameObject{
private:
  int x,y;
  char objeto;
public:
  GameObject();
virtual void escolherPlayer()=0;
virtual int getX();
virtual int getY();
virtual void setX(int x);
virtual void setY(int y);
virtual char getObjeto();
virtual void setObjeto(char o);
};
#endif
