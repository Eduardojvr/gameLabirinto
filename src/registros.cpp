#include "registros.hpp"

Registros::Registros(){
  setQtd(0);
}
void Registros::setQtd(int qtd){
  this->qtd = qtd;
}
int Registros::getQtd(){
  return this->qtd;
}
void Registros::registro(string nome,int pontos){
  FILE * reg;
  reg = fopen("../obj/registros.txt","a+");
  if(reg == NULL){
    reg = fopen("./obj/registros.txt","a+");
  }else{
    cout<<"Nao foi possivel abrir o arquivo!"<<endl;
  }
  fprintf(reg, "%s\n%d\n",nome.c_str(),pontos);
  fclose(reg);
}
void Registros::verReg(){

  char aux[100];
  int a=0;
    FILE * reg ;
    reg = fopen("../obj/registros.txt","r");
    if(reg == NULL){
        reg = fopen("./obj/registros.txt","r");
      if(reg == NULL){
        cout<<"Nao foi possivel abrir o arquivo!\n";
      }
    }
  while(fgets(aux,sizeof(aux),reg) != NULL){
    if(a == 1){
      setQtd(getQtd()+1);
      a=0;
    }
    cout<<aux;
    a++;
  }
  fclose(reg);
}
