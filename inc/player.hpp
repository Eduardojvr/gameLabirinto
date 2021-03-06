#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "gameObject.hpp"
#include <string>
using namespace std;

class Player:public GameObject{
private:
  string nome;
  bool vivo;
  int pontos;
  bool venceu;
  int vidas;
public:
  Player();
  ~Player();
string getNome();
void setNome(string nome);
bool getVivo();
void setVivo(bool a);
int getPontos();
void setPontos(int p);
bool getVenceu();
void setVenceu(bool v);
void escolherPlayer();
void setVidas(int vidas);
int getVidas();
void movimento(char ** m,char movimento);
void posicionaJog(char ** m);
void resultado();
void verificaPontuacao();
void abrePortal(char ** m);
};


#endif
