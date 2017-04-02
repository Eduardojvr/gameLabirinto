#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/player.hpp"

Player::Player(){
  setX(1);
  setY(0);
  setAlive(true);
  //setVenceu(true);
  venceu = true;
}
bool Player::getAlive(){
  return this->alive;
}
void Player::setAlive(bool a){
  this->alive = a;
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
  this->pontos = pontos;
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
