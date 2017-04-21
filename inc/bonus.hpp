#ifndef BONUS_HPP
#define BONUS_HPP
#include "gameObject.hpp"
using namespace std;
class Bonus:public GameObject{
private:
  int bonus;
public:
  Bonus();
  ~Bonus();
int getBonus();
void setBonus(int b);
void escolherPlayer();
};
#endif
