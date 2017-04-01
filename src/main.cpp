#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/mapa.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/bonus.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/player.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/armadilha.hpp"
#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/gameObject.hpp"
using namespace std;

void inicial(){
  system("clear");
  cout<<"=========================\n        O Labirinto\n=========================\n";
}
int posicaoArmad(){
  return rand()%100;
}

int main(){
  string nome;
int movimento,i,j;
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
Armadilha * p[7];
Bonus * bon[2];
for(int i=0;i<2;i++){
  bon[i] = new Bonus();
}
for(int i=0;i<7;i++){
  p[i] = new Armadilha();
}
cout<<"Nome do jogador:\n";
getline(cin,nome);
jog->setNome(nome);
cout<<"Jogador: "<<jog->getNome()<<"\n";
jog->escolherPlayer();

while (true) {
  initscr();

  if(m[jog->getX()][jog->getY()] != '#'){
  m[jog->getX()][jog->getY()]  = jog->getObjeto();
}
refresh();
clear();
 for(i=0;i<17;i++){
  for(j=0;j<73;j++){
    if(m[i][j] != '-'){
      printw("%c",m[i][j]);
    }else{
      printw(" ");
    }
  }
  printw("\n");
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

  return 0;

}
