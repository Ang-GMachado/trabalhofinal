#include "../crafting-hpp/pao.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

pao::pao(float price, int time) {}

pao::pao(){};

int pao::crafting() {
  int r = rand() % 100;
  if (r == 0)
    cout << "O pao queimou\n";
  else if (r >= 90) {
    cout << "O trigo se tornou um delicioso pao\n";
    r *= 2;
  }
  return r;
}