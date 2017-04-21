
#include "gameObject.hpp"

GameObject::GameObject(){
  x=0;
  y=0;
}
GameObject::~GameObject(){}
void GameObject::setX(int x){
  this->x=x;
}

int GameObject::getX(){
  return this->x;
}

void GameObject::setY(int y){
  this->y=y;
}

int GameObject::getY(){
  return this->y;
}

void GameObject::setObjeto(char o){
  this->objeto=o;
}
char GameObject::getObjeto(){
  return this->objeto;
}
void GameObject::escolherPlayer(){}
