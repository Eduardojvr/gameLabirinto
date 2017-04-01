#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "/home/eduardo/Documentos/Orientação à Objetos/projeto_01/inc/mapa.hpp"

Mapa::Mapa(){
  linhas = 18;
  colunas = 73;
}

int Mapa::getLinhas(){
  return this->linhas;
}

int Mapa::getColunas(){
  return this->colunas;
}

/*void Mapa::lerMapa(){
  char m[18][73];
char aux[80];
FILE * mapa = fopen("mapa.txt","r");
int i=0,j=0;
while(fgets(aux,sizeof(aux),mapa) != NULL){
        for(j=0;j<73;j++){
            m[i][j] = aux[j];
        }
    i++;
}
for(i=0;i<17;i++){
    for(j=0;j<73;j++){
        printf("%c",m[i][j]);
    }
    printf("\n");
}

}*/
