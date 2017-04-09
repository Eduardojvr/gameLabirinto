#include "player.hpp"

Player::Player(){
  setX(1);
  setY(0);
  setVivo(true);
  setVenceu(false);
  setPontos(0);
}
bool Player::getVivo(){
  return this->vivo;
}
void Player::setVivo(bool a){
  this->vivo = a;
}
void Player::setNome(string nome){
  this->nome = nome;
}
string Player::getNome(){
  return this->nome;
}
int Player::getPontos(){
  return this->pontos;
}
void Player::setPontos(int p){
  this->pontos = p;
}

bool Player::getVenceu(){
  return this->venceu;
}
void Player::setVenceu(bool v){
  this->venceu = v;
}

void Player::escolherPlayer(){
  int op;
  cout<<"Escolha um player\n"<<"[1]- @\n"<<"[2]- }\n"<<"[3]- >"<<endl;
  cout<<"Op:";
  cin>>op;
  switch (op) {
    case 1:
      setObjeto('@');
      break;
    case 2:
        setObjeto('}');
        break;
    case 3:
        setObjeto('>');
          break;
  }
}
