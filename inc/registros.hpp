#ifndef REGISTROS_HPP
#define REGISTROS_HPP
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Registros{
private:
  int qtd;
public:
  Registros();
  void setQtd(int qtd);
  int getQtd();
  void registro(string nome,int pontos);
  void verReg();

};
#endif
