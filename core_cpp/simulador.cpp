#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "../core_hpp/simulador.hpp"

#include "../servicos-hpp/mine.hpp"

#include "../crafting-hpp/forge.hpp"

using namespace std;

void Simulador::startSimulas(string playername, int dif) {
  NewRound(playername, round, dif);
}

float Simulador::getwallet() { return this->wallet; }
void Simulador::setwallet(float dineros) {
  this->wallet = getwallet() + dineros;
}

void Simulador::NewRound(string playername, int round, int dif) {

  cout << "-----Round " << round << "-------\n" << endl;
  cout << "Góðan morgin, " << playername << "Como agradaremos aos Deuses?\n"
       << endl;
  int choice = trabalo(dif, round);
  careft(choice, round);
  Rest(playername, this->round, dif);
}
void Simulador::Rest(string playername, int round, int dif) {
  cout << "Os trabalhos e as refinações estão prontos" << playername << "\n"
       << endl;
  cout << "God natt" << endl;
  round++;
  NewRound(playername, round, dif);
}

int Simulador::trabalo(int dif, int time) {
  int choice = 0, mod = 0;
  cout << "1 - Mineração;\n 2-Coleta;\n 3-Plantação;\n 4-Caça;\n 5-Criação de "
          "Gado;\n 6-Descansar por hoje";
  try {
    cin >> choice;
    throw choice;
  } catch (int a) {
    cout << choice << " não é uma das opções fornecidas pelos deuses\n" << endl;
    trabalo(dif, time);
  }
  if (choice == 1) {
    int chanc = 80 / dif;

    Servico *mineras = new Mine(12.34 * dif, chanc, time);
    time = mineras->gettime();

    mod = mineras->trabalhar(time, chanc);
    Passa(time, mineras->getpag());
    return 1;
  } else if (choice == 2) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
    mine->trabalhar(chanc);
    */
    cout << "Ainda não foi implementado\n" << endl;
    return 2;
  } else if (choice == 3) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
  mine->trabalhar(chanc);*/
    cout << "Ainda não foi implementado\n" << endl;
    return 3;
  } else if (choice == 4) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
    mine->trabalhar(chanc);*/
    cout << "Ainda não foi implementado\n" << endl;
    return 4;
  } else if (choice == 5) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
    mine->trabalhar(chanc);*/
    cout << "Ainda não foi implementado\n" << endl;
    return 5;
  } else {
    cout << choice << " não é uma das opções fornecidas pelos deuses\n" << endl;
    return trabalo(dif, time);
  }
}

int Simulador::careft(int choice, int time) {
  int a;
  cout << "Os frutos de teu trabalho são majestosos. Vende-los \n" << endl;
  cout << "0 - Brutos;\n 1 - Refinados;\n" << endl;
  cin >> a;
  if (a != 1) {
    if (a == 0) {
      return 0;
    } else {
      cout << choice << " não é uma das opções fornecidas pelos deuses\n"
           << endl;
      careft(choice, time);
    }
    if (a != 1) {
      if (a == 0)
        return 0;
    } else {
      cout << a << " não é uma das opções fornecidas pelos deuses\n" << endl;
      careft(choice, time);
    }
  }
  if (choice == 1) {

    Craft *fer = new Forge(-3.2, time);
    time = fer->gettime();
    fer->crafting();
    Passa(time, fer->getprice());
    return Passa(time, fer->getprice());
  } else if (choice == 2) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
    mine->trabalhar(chanc);
    */
    cout << "Ainda não foi implementado\n" << endl;
    return 0;
  } else if (choice == 3) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
  mine->trabalhar(chanc);*/
    cout << "Ainda não foi implementado\n" << endl;
    return 0;
  } else if (choice == 4) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
    mine->trabalhar(chanc);*/
    cout << "Ainda não foi implementado\n" << endl;
    return 0;
  } else if (choice == 5) {
    /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
    mine->trabalhar(chanc);*/
    cout << "Ainda não foi implementado\n" << endl;
    return 0;
  } else if (choice == 6) {
    cout << "Sua preguiça desonra os deuses\n" << endl;
    return 0;
  } else {
    cout << choice << " não é uma das opções fornecidas pelos deuses\n" << endl;
    return careft(choice, time);
  }
}
int Simulador::Passa(int time, float din) {
  float wallet = this->getwallet();
  wallet += din;
  if (din != 0) {
    setwallet(wallet);
  }
  this->round += time;
  return round;
}

void Simulador::gameover(int round, float wallet) {
  cout << "-----------------------------------------------\n" << endl;
  cout << "Os deuses coletaram " << wallet << " de dinheiro\n" << endl;
  cout << "Seu trabalho chegou ao fim em " << round << " dias\n" << endl;
  cout << "Descanse em paz" << endl;
  cout << "-----------------------------------------------\n" << endl;
}
