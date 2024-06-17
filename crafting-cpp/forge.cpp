#include "../crafting-hpp/forge.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Forge::Forge(float price, int time) {}

Forge::Forge(){};

int Forge::crafting() {
  int r = rand() % 100;
  if (r == 0)
    cout << "A forja nao ascendeu\n";
  else if (r >= 90) {
    cout << "Uma pedra preciosa estava oculta nas impurezas do minerio\n";
    r *= 2;
  }
  return r;
}