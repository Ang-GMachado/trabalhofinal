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

/*começa o simulador, de forma que um construtor
não seja necessário para o funcionamento*/
void Simulador::startSimulas(string playername, int dif) {
  this->playername = playername;
  NewRound(playername, round, dif);
}
//getter da carteira, pois é privada
float Simulador::getwallet() { return this->wallet; }
//soma o dinheiro recebido à carteira
void Simulador::setwallet(float dineros) {
  this->wallet = getwallet() + dineros;
}
//começa cada rodada
void Simulador::NewRound(string playername, int round, int dif) {
  cout << "----- Round " << round << "-------\n" << endl;
  cout << "Góðan morgin, " << playername << " Como serviremos aos Deuses?\n"
       << endl;
  //começa o trabalho que será feito no round
  int choice = trabalo(dif, round);
  //se nenhum trabalho foi escolhido, nenhum craft é necessário
  if (choice != 0) {
    int craft = careft(choice, round, dif);
    if (craft != 0)
      cout << "Os trabalhos e as refinações estão prontos \n" << endl;
    else
      cout << "Seu trabalho está pronto \n" << endl;
  }
  //termina o round
  Rest(playername, this->round, dif);
}

void Simulador::Rest(string playername, int round, int dif) {
  cout << "God natt " << playername << "\n" << endl;
  round++;
  //chama o próximo round
  NewRound(playername, round, dif);
}

int Simulador::trabalo(int dif, int time) {
  //inicializa os parâmetros do trabalho
  int choice = 0, mod = 0;
  int chanc = 40 + 5 * dif;
  cout << "1 - Mineração;\n 2-Coleta;\n 3-Plantação;\n 4-Caça;\n 5- Pesca;\n "
          "0-Descansar por hoje \n";
  cin >> choice;
  if (choice == 1) {
    //jogador escolheu minerar
    Servico *mineras = new Mine(12.34 * dif, 2, chanc);
    time = mineras->gettime();

    mod = mineras->trabalhar(time, chanc);
    Passa(time, mineras->getpag() + mod, dif);
    free(mineras);
    if (mod >= chanc)
      return 1;
  } else if (choice == 2) {
    //jogador escolheu coletar frutas da floresta
    Servico *col = new Coleta(2 * dif, 1, chanc);
    time = col->gettime();

    mod = col->trabalhar(time, chanc);
    Passa(time, col->getpag() + mod, dif);
    free(col);
    if (mod >= chanc)
      return 2;
  } else if (choice == 3) {
    //jogador escolheu plantar
    Servico *sow = new Pranta(2 * dif, 30, chanc);
    time = sow->gettime();

    mod = sow->trabalhar(time, chanc);

    Passa(time, sow->getpag() + mod, dif);
    free(sow);
    if (mod >= chanc)
      return 3;
  } else if (choice == 4) {
    //jogador escolheu caçar
    Servico *cac = new Hunt(2 * dif, 5, chanc);
    time = cac->gettime();

    mod = cac->trabalhar(time, chanc);

    Passa(time, cac->getpag() + mod, dif);
    free(cac);
    if (mod >= chanc)
      return 4;
  } else if (choice == 5) {
    //jogador escolheu pescar
    Servico *fsh = new Pesca(2 * dif, 3, chanc);
    time = fsh->gettime();

    mod = fsh->trabalhar(time, chanc);
    Passa(time, fsh->getpag() + mod, dif);
    free(fsh);
    if (mod >= chanc)
      return 5;
  } else if (choice == 0) {
    cout << "Sua preguiça deshonra os Deuses" << endl;
  } else {
    //uma escolha inválida começa uma recursividade
    cout << choice << " não é uma das opções forneci1das pelos deuses\n"
         << endl;
    return trabalo(dif, time);
  }
  return 0;
}
//função que inicia os craft
int Simulador::careft(int choice, int time, int dif) {
  int a;
  int mod;
  float price;
  //jogador escolhe se vai ou não refinar itens
  cout << "Os frutos de teu trabalho são majestosos.\n" << endl;
  cout << "0 - Entregá-los puros;\n1 - Refiná-los;\n" << endl;
  cin >> a;
  if (a != 1) {
    //se o jogador escolhe entregar os itens puros, o craft não acontece
    if (a == 0) {
      return 0;
    } else {
      //se o jogador escolhe uma opção inválida, recursão
      cout << choice << " não é uma das opções fornecidas pelos deuses\n"
           << endl;
      careft(choice, time, dif);
    }
  }
  //se o jogador minerou e escolheu refinar, acende a forja.
  if (choice == 1) {
    time = 1;
    price = -3.2;
    Craft *fer = new Forge(price, time);

    mod = fer->crafting();

    Passa(time, fer->getprice() + mod, dif);
    free(fer);
    return 1;
    //se o jogador coletou e escolheu refinar, faz bebidas.
  } else if (choice == 2) {
    time = 36;
    price = -1.79;
    Craft *vin = new Vineo(price, time);

    mod = vin->crafting();

    Passa(time, vin->getprice(), dif);
    free(vin);
    return 2;
    //se o jogador plantou e escolheu refinar, faz pão com o trigo
  } else if (choice == 3) {
    Craft *Pao = new pao(-9.48, 5);
    time = Pao->gettime();
    Pao->crafting();
    Passa(time, Pao->getprice(), dif);
    free(Pao);
    return 3;
  } else if (choice == 4) {
    //se o jogador caçou e escolheu refinar, cozinha a carne
    Craft *cook = new Cozi(-1, 1);
    time = cook->gettime();
    cook->crafting();
    Passa(time, cook->getprice(), dif);
    free(cook);
    return 4;
  } else if (choice == 5) {
     //se o jogador pescou e escolheu refinar, cozinha os peixes
    Craft *cook = new Cozi(-1, 1);
    time = cook->gettime();
    cook->crafting();
    Passa(time, cook->getprice(), dif);
    free(cook);
    return 5;
  }
  return 0;
}
//a função passa é chamada ao fim de um trabalho ou refinação
void Simulador::Passa(int time, float din, int dif) {
  //o setter da carteira é chamado
  float wallet = this->getwallet();
  if (din != 0) {
    wallet += din;
    setwallet(wallet);
  }
  //testamos se iremos ou não acabar o jogo
  for (int i = this->round; i < this->round + time; i++) {
    if (rand() % (100 / dif) == 25)
      gameover(round, this->getwallet());
  }
  this->round += time;
  return;
}

//gameover deleta o simulador e encerra o jogo.
void Simulador::gameover(int round, float wallet) {
  cout << "-----------------------------------------------\n" << endl;
  cout << "Os deuses coletaram " << wallet << "\n" << endl;
  cout << "Seu trabalho chegou ao fim em " << round << " dias\n" << endl;
  cout << "Descanse em paz" << endl;
  cout << "-----------------------------------------------\n" << endl;
  free(this);
}