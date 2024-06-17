#include "../servicos-hpp/pesca.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Pesca::Pesca(float pag, int chanc, int time) : Servico(pag, chanc, time) {}

int Pesca::trabalhar(int chanc, int time) {
  int r = rand() % 100;
  if (r > chanc / 10 && r < chanc) {
    std::cout << "Nenhuma Mordida\n";
  } else if (r < chanc / 10 && r > 1)
    std::cout << "O peixe era grande demais e sumiu com a isca\n";
  else if (r <= 1)
    std::cout << "Voce foi puxado para a agua e caiu, haha \n";
  else if (r > 50 + (100 - chanc))
    std::cout << "Bacalhau\n";
  else
    std::cout << "Arenque.\n";
  return r;
}