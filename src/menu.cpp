#include "menu.hpp"
Menu::Menu(){
  aberto = false;
}
Menu::~Menu(){}
bool Menu::getAberto(){
  return aberto;
}
void Menu::setAberto(bool aberto){
  this->aberto = aberto;
}

int Menu::menuJogo(Player * jog,Registros * reg,int cont,int so){
  string nome;
  int op,dif;
do{
  system("clear");
  cout<<"=========================\n        O Labirinto\n=========================\n[1]-Jogar\n[2]-Como jogar\n[3]-Ranking\n[4]-Apagar dados de partidas\n[5]-Sair\nOp:";
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
    system("clear");
    if(dif>17 || dif<1){
      cout<<"Nível de dificuldade inválido!\n";
      exit(0);
    }
  break;
  case 2:
    system("clear");
    cout<<"=========================\n        Objetivos\n=========================\n";
if(so==1){
  cout<<"Conquiste no minimo 100 pontos \npegando '+',abra o portal e saia do \nlabirinto para vencer!\nO portal abre quando a pontuação\nfor maior ou igual a 10\n\n[Enter] para voltar ao menu\n";
  setbuf(stdin,NULL);
  getchar();
}
if(so==2){
    if(cont < 1){
      cout<<"Conquiste no minimo 100 pontos \npegando '+',abra o portal e saia do \nlabirinto para vencer!\nO portal abre quando a pontuação\nfor maior ou igual a 10\n\n[Enter] para voltar ao menu\n";
      setbuf(stdin,NULL);
      getchar();
    }else{
      cout<<"Conquiste no minimo 100 pontos \npegando '+',abra o portal e saia do \nlabirinto para vencer!\nO portal abre quando a pontuação\nfor maior ou igual a 10\n";
    }
    //system("clear");
  }
  break;
  case 3:
    system("clear");
    cout<<"=========================\n    Jogos com Vitória\n=========================\n";
    reg->verReg();
    if(reg->getQtd() == 0){
      cout<<"Sem registro de jogos!\n";
    }
    if(so==1){
      cout<<"[Enter] para voltar ao menu!\n";
      setbuf(stdin,NULL);
      getchar();
    }
    if(so==2){
    if(cont < 1){
      cout<<"[Enter] para voltar ao menu!\n";
      setbuf(stdin,NULL);
      getchar();
    }
      system("clear");
  }
  break;
  case 4:
    FILE * r;
    r = fopen("./obj/registros.txt","w");
    if(r == NULL){
      fopen("../obj/registros.txt","w");
    }
    fclose(r);
    reg->setQtd(0);
    system("clear");
    cout<<"Dados apagados!\n[Enter] para voltar ao menu"<<endl;
    setbuf(stdin,NULL);
    getchar();
    break;
  case 5:
    exit(0);
    break;
  default:
      //system("clear");
      cout<<"Opção inválida!"<<endl;
      exit(0);
    break;
}
}while(op!=1);
return dif;
}
