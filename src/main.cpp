#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ncurses.h>
#include "bonus.hpp"
#include "player.hpp"
#include "armadilha.hpp"
#include "gameObject.hpp"
using namespace std;

void inicial(){
  system("clear");
  cout<<"=========================\n        O Labirinto\n=========================\n";
}
int posiciona(int mod){
  return rand()%mod;
}

int main(int argc, char ** argv){
  string nome;
int movimento,j,dif;
//Criação dos Objetos
  char m[17][73];
char aux[75];
FILE * mapa = fopen("mapa.txt","r");
int a=0,b=0;

while(fgets(aux,sizeof(aux),mapa) != NULL){
        for(b=0;b<73;b++){
            m[a][b] = aux[b];
        }
    a++;
}
fclose(mapa);

inicial();
Player * jog = new Player();
Armadilha * p[17];
Bonus * bon[5];

for(int i=0;i<5;i++){
  bon[i] = new Bonus();
}

cout<<"Nome do jogador:\n";
getline(cin,nome);
jog->setNome(nome);
system("clear");
cout<<"Jogador: "<<jog->getNome()<<"\n";
jog->escolherPlayer();
system("clear");
cout<<"Nível de dificuldade [1-17]\nDigite o nível:";
cin>>dif;

//bon[1]->setX(3);
//bon[1]->setY(15);

for(int i=0;i<dif;i++){
  p[i] = new Armadilha();
}
//m[bon[1]->getX()][bon[1]->getY()] = '+';


while (jog->getVenceu() != false) {
  initscr();
  if(m[jog->getX()][jog->getY()] != '#' && m[jog->getX()][jog->getY()] != '+'){
    m[jog->getX()][jog->getY()]  = jog->getObjeto();
  }

for(int i=0;i<dif;i++){
  if(m[p[i]->getX()][p[i]->getY()] != '#'){
    if(m[p[i]->getX()][p[i]->getY()] != '|'){
      p[i]->setObjeto('X');
      m[p[i]->getX()][p[i]->getY()]  = p[i]->getObjeto();
    }
  }
}

for(int i=0;i<5;i++){
  if(m[bon[i]->getX()][bon[i]->getY()] != '#' && m[bon[i]->getX()][bon[i]->getY()] != jog->getObjeto()){
    if(m[p[i]->getX()][p[i]->getY()] != '|'){
      bon[i]->setObjeto('+');
      m[bon[i]->getX()][bon[i]->getY()]  = bon[i]->getObjeto();
    }
  }
}

if(m[jog->getX()][jog->getY()] == '+'){
  jog->setPontos(jog->getPontos()+4);
  m[bon[1]->getX()][bon[1]->getY()]=jog->getObjeto();
}

for(int i=0;i<dif;i++){
  if(p[i]->getX() == jog->getX() && p[i]->getY() == jog->getY()){
      jog->setVenceu(false);
      break;
  }
}

refresh();
clear();
 for(int i=0;i<17;i++){
  for(j=0;j<73;j++){
    if(m[i][j] != '-'){
      printw("%c",m[i][j]);
    }else{
      printw(" ");
    }
  }
  printw("\n");
}
printw("\nPontos: %d",jog->getPontos());

for(int i=0;i<dif;i++){
  if(m[p[i]->getX()][p[i]->getY()] !='#'){
    if(m[p[i]->getX()][p[i]->getY()] !='|'){
      m[p[i]->getX()][p[i]->getY()] = ' ';
    }
  }
}
for(int i=0;i<5;i++){
  if(m[bon[i]->getX()][bon[i]->getY()] !='#'){
    if(m[bon[i]->getX()][bon[i]->getY()] !='|'){
      m[bon[i]->getX()][bon[i]->getY()] = ' ';
    }
  }
}
for(int q=0;q<5;q++){
  for(int i=0;i<17;i++){
    for(int j=0;j<73;j++){
      bon[q]->setX(posiciona(17));
      bon[q]->setY(posiciona(72));
    }
  }
}

for(int q=0;q<dif;q++){
  for(int i=0;i<17;i++){
    for(int j=0;j<73;j++){
      p[q]->setX(posiciona(17));
      p[q]->setY(posiciona(72));
    }
  }
}
  movimento = getch();
  noecho();
  if(m[jog->getX()][jog->getY()+1] != '#' && movimento == 'd' && m[jog->getX()][jog->getY()+1] != '|'){
    jog->setY(jog->getY()+1);
    m[jog->getX()][jog->getY()-1] =' ';
  }else if(m[jog->getX()][jog->getY()-1] != '#' && movimento == 'a' && m[jog->getX()][jog->getY()-1] != '|'){
    jog->setY(jog->getY()-1);
    m[jog->getX()][jog->getY()+1] =' ';
  }else if(m[jog->getX()+1][jog->getY()] !='#' && movimento == 's' && m[jog->getX()+1][jog->getY()] != '|'){
    jog->setX(jog->getX()+1);
    m[jog->getX()-1][jog->getY()] =' ';
  }else if(m[jog->getX()-1][jog->getY()] !='#' && movimento == 'w' && m[jog->getX()][jog->getY()-1] != '|'){
    jog->setX(jog->getX()-1);
    m[jog->getX()+1][jog->getY()] =' ';
  }

  endwin();
}
if(jog->getVenceu() == false){
  cout<<"Você perdeu!\n";
}

  return 0;

}
