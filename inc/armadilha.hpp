#ifndef ARMADILHA_HPP
#define ARMADILHA_HPP
#include "gameObject.hpp"
using namespace std;
class Armadilha:GameObject{
private:
  int perda;
public:
  int getPerda();
  void setPerda(int p);
  void escolherPlayer();
};




#endif
