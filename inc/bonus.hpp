#ifndef BONUS_HPP
#define BONUS_HPP
#include "gameObject.hpp"
using namespace std;
class Bonus:GameObject{
  int bonus;

int getBonus();
void setBonus(int b);
void escolherPlayer();
};
#endif
