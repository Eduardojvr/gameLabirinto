#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "bonus.hpp"
#include "player.hpp"
#include "armadilha.hpp"
#include "gameObject.hpp"
using namespace std;

void inicial(){
  system("clear");
  cout<<"=========================\n        O Labirinto\n=========================\n[1]-Jogar\n[2]-Como jogar\n[3]-Rank\n[4]-Sair\nOp:";
}
int posiciona(int mod){
  return rand()%mod;
}

int main(int argc, char ** argv){
  string nome;
int movimento,j,dif,controle,op;
//Criação dos Objetos
  char m[17][73];
char aux[75];
FILE * mapa;
mapa = fopen("src/mapa.txt","r");

int a=0,b=0;

//ler mapa
while(fgets(aux,sizeof(aux),mapa) != NULL){
        for(b=0;b<73;b++){
            m[a][b] = aux[b];
        }
    a++;
}
fclose(mapa);

Player * jog = new Player();
Armadilha * p[17];
Bonus * bon[5];
//cria bonus
for(int i=0;i<5;i++){
  bon[i] = new Bonus();
}

do{
inicial();
cin>>op;
switch (op) {
  case 1:
    system("clear");
    cout<<"Nome do jogador:\n";
    setbuf(stdin,NULL);
    getline(cin,nome);
    jog->setNome(nome);
    system("clear");
    cout<<"Jogador: "<<jog->getNome()<<"\n";
    jog->escolherPlayer();
    system("clear");
    cout<<"Nível de dificuldade [1-17]\nDigite o nível:";
    cin>>dif;
  break;
  case 2:
    system("clear");
    cout<<"#Conquiste 100 pontos pegando '+' e saia \ndo labirinto para vencer!\n\n\n[Tecle enter para voltar ao menu]";
    setbuf(stdin,NULL);
    getchar();
  break;
  case 3:
  break;
  case 4:
    exit(0);
    break;
  default:
      system("clear");
      cout<<"Opção inválida!"<<endl;
      setbuf(stdin,NULL);
      cout<<"Enter para voltar ao menu!"<<endl;
      getchar();
      break;
}

}while(op!=1);
//cria Armadilha
for(int i=0;i<dif;i++){
  p[i] = new Armadilha();
}




while (jog->getVivo() != false) {
  initscr();

  if(m[jog->getX()][jog->getY()] != '#'){
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
    if(m[bon[i]->getX()][bon[i]->getY()] != '|' && m[bon[i]->getX()][bon[i]->getY()] != 'B'){
        m[bon[i]->getX()][bon[i]->getY()]  = bon[i]->getObjeto();
    }
  }
}

  if(m[jog->getX()][jog->getY()-1] == '+'){
    jog->setPontos(jog->getPontos()+10);
    m[jog->getX()][jog->getY()]=jog->getObjeto();
    m[jog->getX()][jog->getY()-1]='B';
    controle=30;
  }

for(int i=0;i<dif;i++){
  if(p[i]->getX() == jog->getX() && p[i]->getY() == jog->getY()){
      jog->setVivo(false);
      break;
  }
}

refresh();
clear();
//imprimi mapa
 for(int i=0;i<17;i++){
  for(j=0;j<73;j++){
    if(m[i][j] != '-' && m[i][j]!='B'){
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
//posiciona bonus
if(controle == 30){
for(int q=0;q<5;q++){
  for(int i=0;i<17;i++){
    for(int j=0;j<73;j++){
      bon[q]->setX(posiciona(17));
      bon[q]->setY(posiciona(72));
    }
  }
}
controle = 0;
}
controle++;
//posiciona armadilha
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
cout<<jog->getPontos()<<endl;

  return 0;

}
