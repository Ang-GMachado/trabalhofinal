#include "../servicos-hpp/pranta.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Pranta::Pranta(float pag, int chanc, int time) : Servico(pag, chanc, time) {}

int Pranta::trabalhar(int chanc, int time) {
  int r = rand() % 100;
  if (r > chanc / 10 && r < chanc) {
    std::cout << "Nada cresceu\n";
  } else if (r < chanc / 10 && r > 1) {
    std::cout << "O trigo morreu\n";
    time += time;
  } else if (r <= 1)
    std::cout << "A lavoura foi arrasada\n";
  else if (r > 50 + (100 - chanc))
    std::cout << "O melhor trigo da regiao\n";
  else
    std::cout << "Voce colhe trigo.\n";
  return r;
}