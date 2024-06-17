#include "../servicos-hpp/coleta.hpp"

#include <cstdlib>
#include <iostream>
using namespace std;

Coleta::Coleta(float pag, int chanc, int time) : Servico(pag, chanc, time) {}

int Coleta::trabalhar(int chanc, int time) {
  int r = rand() % 100;

  if (r > chanc / 10 && r < chanc) {
    std::cout << "A floresta te decepcionou\n";
  } else if (r < chanc / 10 && r > 1) {
    std::cout << "Uma fruta que você comeu não estava boa.\n"
              << "Você precisara se tratar\n";
    time += r;
  } else if (r <= 1)
    std::cout << "Uma cobra te picou.\n";
  else
    std::cout << "Frutas encontradas Da pra fazer vinho.\n";
  return r;
}