#include "../servicos-hpp/hunt.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Hunt::Hunt(float pag, int chanc, int time) : Servico(pag, chanc, time) {}

int Hunt::trabalhar(int chanc, int time) {
  int r = rand() % 100;
  if (r > chanc / 10 && r < chanc) {
    std::cout << "Voce nao encontra nada\n";
  } else if (r < chanc / 10 && r > 1) {
    std::cout << "Um predador te atacou, voce teve que fugir\n";
    time += 2;
  } else if (r <= 1)
    std::cout << "Um predador te atacou, nao deu pra fugir\n";
  else if (r > 50 + (100 - chanc))
    std::cout << "O melhor trigo da regiao\n";
  else
    std::cout << "Voce colhe trigo.\n";
  return r;
}