
#include "map.hpp"

Mapa::Mapa(){
  linhas = 17;
  colunas = 73;
}
Mapa::~Mapa(){}
int Mapa::getLinhas(){
  return this->linhas;
}

int Mapa::getColunas(){
  return this->colunas;
}


void Mapa::lerMapa(char ** m){

char aux[75];
for(int i=0;i<17;i++){
    m[i] = (char*)malloc(sizeof(char)*73);
}

FILE * mapa = fopen("./obj/mapa.txt","r");
if(mapa == NULL){
  mapa = fopen("../obj/mapa.txt","r");
  if(mapa == NULL){
    cout<<"Erro ao abrir o arquivo!"<<endl;
  }
}
int i=0;

while(fgets(aux,sizeof(aux),mapa) != NULL){
       for(int j=0;j<73;j++){
           m[i][j] = aux[j];
        }
    i++;
}
fclose(mapa);

}
