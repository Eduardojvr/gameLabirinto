#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "bonus.hpp"
#include "player.hpp"
#include "armadilha.hpp"
#include "gameObject.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "desenha.hpp"
#include "registros.hpp"

using namespace std;

int posiciona(int mod){
  return rand()%mod;
}

int main(int argc, char ** argv){
  int cont=0,so=1;
  do{
      int movimento,dif=0,controle=0;
      char  ** m =(char**)malloc(sizeof(char*)*17);
      Player * jog = new Player();
      Armadilha * p[17];
      Bonus * bon[5];
      Menu * menu = new Menu();
      Mapa * mapa = new Mapa();
      Desenha * des = new Desenha();
      Registros * reg = new Registros();
      for(int i=0;i<5;i++){
        bon[i] = new Bonus();
      }
      menu->setAberto(true);
      dif = menu->menuJogo(jog,reg,cont,so);
      system("clear");
      cout<<"[1]-Linux\n[2]-Mac Os\nDigite a opção do seu sistema: ";
      cin>>so;
      system("clear");
      mapa->lerMapa(m);
      menu->setAberto(false);
      for(int i=0;i<dif;i++){
        p[i] = new Armadilha();
      }

      while (jog->getVivo() != false) {

        initscr();
        jog->posicionaJog(m);

        for(int i=0;i<dif;i++){
        if(m[p[i]->getX()][p[i]->getY()] != '#'){
          if(m[p[i]->getX()][p[i]->getY()] != '|'){
            p[i]->escolherPlayer();
            //p[i]->setObjeto('X');
            m[p[i]->getX()][p[i]->getY()]  = p[i]->getObjeto();
          }
        }
      }

      for(int i=0;i<5;i++){
        if(m[bon[i]->getX()][bon[i]->getY()] != '#' && m[bon[i]->getX()][bon[i]->getY()] != jog->getObjeto()){
          if(m[bon[i]->getX()][bon[i]->getY()] != '|' && m[bon[i]->getX()][bon[i]->getY()] != 'B'){
            if((bon[i]->getY()+1)%2 == 0){
              m[bon[i]->getX()][bon[i]->getY()]  = bon[i]->getObjeto();
            }
          }
        }
      }
      for(int i=0;i<5;i++){
        if(m[jog->getX()][jog->getY()-1] == '+'){
          jog->setPontos(jog->getPontos()+bon[i]->getBonus());
          m[jog->getX()][jog->getY()]=jog->getObjeto();
          m[jog->getX()][jog->getY()-1]='B';
          controle=30;
        }
      }
      for(int i=0;i<dif;i++){
        if(p[i]->getX() == jog->getX() && p[i]->getY() == jog->getY()){
            jog->setVidas(jog->getVidas()-p[i]->getPerda());
            if(jog->getVidas() == 0){
              jog->setVivo(false);
            }
            break;
        }
      }

       refresh();
       clear();

      //imprime mapa
      des->setTela(true);
      des->draw(m,jog);

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
            p[q]->setY(posiciona(73));
          }
        }
      }

      movimento = getch();
      noecho();
      jog->movimento(m,movimento);

      jog->abrePortal(m);
      jog->verificaPontuacao();
      if(jog->getVenceu() == true)
        break;

      endwin();
   }
  endwin();
  if(jog->getVenceu() == true){
    reg->setQtd(reg->getQtd()+1);
    reg->registro(jog->getNome(),jog->getPontos());
  }
  jog->resultado();
  delete(m);
  delete(menu);
  //menu->~Menu(); Funciona so para alocação estatica
  delete(mapa);
  delete(des);
  delete(reg);
  cont++;
}while(1);

  return 0;
}
