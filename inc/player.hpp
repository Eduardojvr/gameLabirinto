#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "gameObject.hpp"
#include <string>
using namespace std;
class Player:GameObject{
private:
  string nome;
  bool alive;
  int pontos;
  bool venceu;
public:
string getNome();
void setNome(string nome);
bool getAlive();
void setAlive(bool a);
int getPontos();
void setPontos(int p);
bool getVenceu();
void setVenceu(bool v);
void escolherPlayer();

};


#endif
