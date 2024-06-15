#include "../servicos-hpp/mine.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Mine::Mine(float pag, int chanc, int time) {}

Mine::Mine(){};

int Mine::trabalhar(int chanc) {
  int r = rand() % 100;
  if (r > chanc / 10 && r < chanc) {
    std::cout << "Nenhum minerio acessivel encontrado na mina\n";
  } else if (r < chanc / 10 && r > 1)
    std::cout << "Sua picareta quebrou. Uma nova custa 32,50\n";
  else if (r <= 1)
    std::cout << "A dinamite explodiu na hora errada\n";
  else if (r > 50 + (100 - chanc))
    std::cout << "Ouro encontrado. Muito valioso.\n";
  else
    std::cout << "Ferro encontrado.\n";
  return r;
}