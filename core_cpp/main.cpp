#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

#include "../core_cpp/simulador.cpp"

using std::cout;
using std::endl;
using std::string;

int main() {
  string nome;
  int dificudade;

  Simulador *sim = new Simulador();
  cout << "Hallo. Insira seu nome\n" << endl;
  try {
    cin >> nome;
    throw nome;
  } catch (string nome) {
    cout << nome << " não é um nome digno de um Guerreiro\n" << endl;
    main();
  }
  cout << "O quão bravo" << nome << "é?\n" << endl;
  try {
    cin >> dificudade;
    throw dificudade;
  } catch (int a) {
    cout << "Deve ser um numero inteiro\n" << endl;
    main();
  }
  sim->startSimulas(nome, dificudade);

  while (rand() != 69) {
    rand();
  };
  sim->gameover(sim->round, sim->getwallet());
}