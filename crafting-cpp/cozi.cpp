#include "../crafting-hpp/cozi.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Cozi::Cozi(float price, int time) {}

Cozi::Cozi(){};

int Cozi::crafting() {
  int r = rand() % 100;
  if (r == 0)
    cout << "O fogao nao ascendeu \n";
  else if (r >= 90) {
    cout << "Um delicioso caldo de bicho\n";
    r *= 2;
  }
  return r;
}