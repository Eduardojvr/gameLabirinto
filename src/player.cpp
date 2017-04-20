#include "player.hpp"

Player::Player(){
  setX(1);
  setY(1);
  setVivo(true);
  setVenceu(false);
  setPontos(0);
  setVidas(3);
}
Player::~Player(){
}
int Player::getVidas(){
  return this->vidas;
}
void Player::setVidas(int vidas){
  this->vidas=vidas;
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

void Player::movimento(char ** m,char movimento){
  if(m[getX()][getY()+1] != '#' && movimento == 'd' && m[getX()][getY()+1] != '|'){
    setY(getY()+1);
    m[getX()][getY()-1] =' ';
  }else if(m[getX()][getY()-1] != '#' && movimento == 'a' && m[getX()][getY()-1] != '|'){
    setY(getY()-1);
    m[getX()][getY()+1] =' ';
  }else if(m[getX()+1][getY()] !='#' && movimento == 's' && m[getX()+1][getY()] != '|'){
    setX(getX()+1);
    m[getX()-1][getY()] =' ';
  }else if(m[getX()-1][getY()] !='#' && movimento == 'w' && m[getX()][getY()-1] != '|'){
    setX(getX()-1);
    m[getX()+1][getY()] =' ';
  }
}
void Player::resultado(){
  if(getVenceu() == false){
    system("clear");
    cout<<"#########################\n      Você perdeu 8-(\n#########################";
  }else{
    system("clear");
    cout<<"#########################\n      Resumo 8-)\n#########################";
  }
  cout<<"\n\nPontos obtidos:   "<<getPontos()<<"\nVidas             "<<getVidas()<<"\n[Enter] para voltar ao menu!"<<endl;
  setbuf(stdin,NULL);
  getchar();
}
void Player::abrePortal(char ** m){
  if(getPontos()>=10){
    for(int i=16;i<=16;i++){
      for(int j=22;j<26;j++){
        m[i][j] = ' ';
      }
    }
  }
}
void Player::verificaPontuacao(){
  if(getPontos() >= 10 && getX() == 16 && (getY()==22 || getY()==23 || getY()==24 || getY()==25)){
    setVenceu(true);
  }
}
void Player::posicionaJog(char ** m){
  if(m[getX()][getY()] != '#'){
    m[getX()][getY()]  = getObjeto();
  }
}
