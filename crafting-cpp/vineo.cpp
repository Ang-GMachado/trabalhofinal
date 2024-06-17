#include "../crafting-hpp/vineo.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Vineo::Vineo(float price, int time) {}

Vineo::Vineo(){};

int Vineo::crafting() {
  int r = rand() % 100;
  if (r == 0)
    cout << "Passaros comeram a fruta\n";
  else if (r >= 90) {
    cout << "Sua bebida virou uma bebida alcólica deliciosa\n";
    r *= 2;
  }
  return r;
}