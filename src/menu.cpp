#include "menu.hpp"



int Menu::menuJogo(Player * jog,Registros * reg,int cont){
  string nome;
  int op,dif;
do{
  system("clear");
  cout<<"=========================\n        O Labirinto\n=========================\n[1]-Jogar\n[2]-Como jogar\n[3]-Ranking\n[4]-Sair\nOp:";
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
    if(cont < 1){
      cout<<"Conquiste no minimo 100 pontos \npegando '+',abra o portal e saia do \nlabirinto para vencer!\n\n\n[Enter] para voltar ao menu\n";
      setbuf(stdin,NULL);
      getchar();
    }else{
      cout<<"Conquiste no minimo 100 pontos \npegando '+',abra o portal e saia do \nlabirinto para vencer!\n\n\n";
    }
    system("clear");

  break;
  case 3:
    system("clear");
    cout<<"=========================\n          jogos\n=========================\n";
    reg->verReg();
    if(reg->getQtd() == 0){
      cout<<"Sem registro de jogos!\n";
    }
    if(cont < 1){
      cout<<"[Enter] para voltar ao menu!\n";
      setbuf(stdin,NULL);
      getchar();
    }
      system("clear");
  break;
  case 4:
    exit(0);
    break;
  default:
      system("clear");
      cout<<"Opção inválida!"<<endl;
      exit(0);
    break;
}
}while(op!=1);
return dif;
}
