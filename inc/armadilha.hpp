#ifndef ARMADILHA_HPP
#define ARMADILHA_HPP
#include "gameObject.hpp"
using namespace std;
class Armadilha:public GameObject{
private:
  int perda;
public:
  Armadilha();
  ~Armadilha();
  int getPerda();
  void setPerda(int p);
  void escolherPlayer();
};




#endif
