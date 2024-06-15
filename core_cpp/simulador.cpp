#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "../core_hpp/simulador.hpp"

#include "../servicos-hpp/mine.hpp"

#include "../crafting-hpp/forge.hpp"

using namespace std;

Simulador::Simulador(string playername, int dif) : playername(playername), dif(dif), wallet(0), exaust(0), round(0){

}
void Simulador::NewRound(int round, int tire) {
  cout << "-----Round " << round << "-------\n" << endl;
  int choice;
  cout << "Góðan morgin. Como agradaremos a Odin?\n";
  cout << "1 - Mineração;\n 2-Coleta;\n 3-Plantação;\n 4-Caça;\n 5-Criação de "
          "Gado\n 6-Descansar por hoje";
  cin >> choice;
  switch (choice)
  case 1:
    Servico *mine = new Mine(12.34 / dif, 53 / dif, time * (dif / 4));
  mine->trabalhar(chanc);
  exaust++;
case 2:
  /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
  mine->trabalhar(chanc);
  */
  cout << "Ainda não foi implementado\n" << endl;
case 3:
  /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
mine->trabalhar(chanc);*/
  cout << "Ainda não foi implementado\n" << endl;
case 4:
  /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
  mine->trabalhar(chanc);*/
  cout << "Ainda não foi implementado\n" << endl;
case 5:
  /*Servico *mine = new Mine(12.34/dif, 53/dif, time* (dif/4));
  mine->trabalhar(chanc);*/
  cout << "Ainda não foi implementado\n" << endl;
case 6:
  cout << "Sua preguiça desonra os deuses\n" << endl;
  exaust = 0;
  break;
}