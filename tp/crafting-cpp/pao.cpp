#include "../crafting-hpp/pao.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

pao::pao(float price, int time) {}

int pao::crafting() {
  int r = rand() % 100;
  if (r == 0)
    cout << "O pao queimou\n";
  else if (r >= 90) {
    cout << "As leveduras cresceram o pao mais do que o esperado\n";
    r *= 2;
  }
  return r;
}