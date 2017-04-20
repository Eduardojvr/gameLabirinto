#ifndef DESENHA_HPP
#define DESENHA_HPP
#include "map.hpp"
#include <ncurses.h>
class Desenha{
private:
  bool tela;
public:
  Desenha();
  ~Desenha();
  void setTela(bool tela);
  bool getTela();
  void draw(char ** m,Player * jog);
};
#endif
