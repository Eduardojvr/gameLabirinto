#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include "/home/eduardo/Documentos/Orientação à Objetos/Projeto_01/inc/mapa.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/Projeto_01/inc/bonus.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/Projeto_01/inc/player.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/Projeto_01/inc/armadilha.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/Projeto_01/inc/gameObject.hpp"
using namespace std;

void inicial(){
  system("clear");
  cout<<"=========================\n        O Labirinto\n========================="<<endl;
}

int main(){
string nome;
//initscr();
inicial();
  //Criação dos Objetos
Mapa * m = new Mapa();
Player * jogador = new Player();
Armadilha * p[7];
Bonus * b[2];
for(int i=0;i<2;i++){
  b[i] = new Bonus();
}
for(int i=0;i<7;i++){
  p[i] = new Armadilha();
}
cout<<"Nome do jogador:"<<endl;
getline(cin,nome);
jogador->setNome(nome);
cout<<"Jogador "<<jogador->getNome()<<endl;
jogador->escolherPlayer();
setbuf(stdin,NULL);

while (1) {



}

  return 0;

}
