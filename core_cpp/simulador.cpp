#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "../core_hpp/simulador.hpp"

#include "../servicos-hpp/coleta.hpp"
#include "../servicos-hpp/hunt.hpp"
#include "../servicos-hpp/mine.hpp"
#include "../servicos-hpp/pesca.hpp"
#include "../servicos-hpp/pranta.hpp"

#include "../crafting-hpp/cozi.hpp"
#include "../crafting-hpp/forge.hpp"
#include "../crafting-hpp/pao.hpp"
#include "../crafting-hpp/vineo.hpp"

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
  if (choice != 0)
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
  cout << "1 - Mineração;\n 2-Coleta;\n 3-Plantação;\n 4-Caça;\n 5- Pesca;\n "
          "6-Descansar por hoje";
  try {
    cin >> choice;
    throw choice;
  } catch (int a) {
    cout << choice << " não é uma das opções fornecidas pelos deuses\n" << endl;
    trabalo(dif, time);
  }
  if (choice == 1) {
    int chanc = 200 / dif + time;
    Servico *mineras = new Mine(12.34 * dif, chanc / dif, time);
    time = mineras->gettime();

    mod = mineras->trabalhar(time, chanc);
    Passa(time, mineras->getpag() + mod);
    free(mineras);
    return 1;
  } else if (choice == 2) {
    int chanc = 200 / dif + time;

    Servico *col = new Coleta(2 * dif, chanc / dif, time);
    time = col->gettime();

    mod = col->trabalhar(time, chanc);
    Passa(time, col->getpag() + mod);
    free(col);
    return 2;
  } else if (choice == 3) {
    int chanc = 200 / dif + time;

    Servico *sow = new Pranta(2 * dif, chanc / dif, time);
    time = sow->gettime();

    mod = sow->trabalhar(time, chanc);
    Passa(time, sow->getpag() + mod);
    free(sow);
    return 3;
  } else if (choice == 4) {
    int chanc = 200 / dif + time;

    Servico *cac = new Hunt(2 * dif, chanc / dif, time);
    time = cac->gettime();

    mod = cac->trabalhar(time, chanc);
    Passa(time, cac->getpag() + mod);
    free(cac);
    return 4;
  } else if (choice == 5) {
    int chanc = 200 / dif + time;

    Servico *fsh = new Pesca(2 * dif, chanc / dif, time);
    time = fsh->gettime();

    mod = fsh->trabalhar(time, chanc);
    Passa(time, fsh->getpag() + mod);
    free(fsh);
    return 5;
  } else if (choice == 6) {
    cout << "Sua preguiça desgraca os Deuses" << endl;
    return 0;
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

    Craft *fer = new Forge(-3.2, 1);
    time = fer->gettime();
    fer->crafting();
    Passa(time, fer->getprice());
    free(fer);
    return 1;
  } else if (choice == 2) {
    Craft *vin = new Vineo(-1.79, 36);
    time = vin->gettime();
    vin->crafting();
    Passa(time, vin->getprice());
    free(vin);
    return 2;
  } else if (choice == 3) {
    Craft *Pao = new pao(-9.48, 5);
    time = Pao->gettime();
    Pao->crafting();
    Passa(time, Pao->getprice());
    free(Pao);
    return 3;
  } else if (choice == 4) {
    Craft *cook = new Cozi(-1, 1);
    time = cook->gettime();
    cook->crafting();
    Passa(time, cook->getprice());
    free(cook);
    return 4;
  } else if (choice == 5) {
    Craft *cook = new Cozi(-1, 1);
    time = cook->gettime();
    cook->crafting();
    Passa(time, cook->getprice());
    free(cook);
    return 5;
  }
  return 0;
}
int Simulador::Passa(int time, float din) {
  float wallet = this->getwallet();
  wallet += din;
  if (din != 0) {
    setwallet(wallet);
  }
  for (int i = this->round; i < this->round + time; i++) {
    if (rand() == 69)
      gameover(round, this->getwallet());
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
  free(this);
}
