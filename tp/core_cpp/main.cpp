#include <exception>
#include <iostream>
#include <string>
// a main inclui o simulador e os cabeçalhos necessários para trabalhar com
// strings
#include "../core_hpp/simulador.hpp"

// usando cout, endl e string padrões.
using std::cout;
using std::endl;
using std::string;

// A função puxanome pede o nome do jogador
string puxanome() {
  string nome;
  cout << "Hallo. Insira seu nome\n";
  cin >> nome;
  // exceção para que o jogador não crie um nome muito grande ou muito pequeno
  try {
    if (nome.size() < 3 || nome.size() > 25)
      throw nome;
  } catch (...) {
    cout << nome << " Não é um nome digno de um guerreiro\n";
    puxanome();
  }
  return nome;
}
// a função dif define a dificuldade do jogo, setada pelo jogador
int dif(string nome) {

  int dificuldade = 0;
  cout << "Qual a Dificuldade em que " << nome
       << " terá a experiencia em Midgard?\n";
  cin >> dificuldade;
  /*A dificuldade deve ser um número inteiro, 
  caso contrário, a função retorna ao início*/
  try {
    //exceção, se cin falhar, retira o valor digitado e retorna
    if (cin.fail()) {
      cin.clear();
      //ignore evita loop infinito
      cin.ignore();
      throw dificuldade;
    }
  } catch (int a) {
    cout << "A dificuldade do jogo deve ser um numero inteiro maior que zero\n"
         << endl;
    return dif(nome);
  }
  //limites da dificuldade
  if (dificuldade < 1) {
    cout << "A dificuldade minima do jogo é 1\n" << endl;
    dificuldade = 1;
  }
  if (dificuldade > 10) {
    cout << "A dificuldade máxima do jogo é 10\n" << endl;
    dificuldade = 10;
  }
  return dificuldade;
}
int main() {
  //começa o programa pedindo nome e a dificuldade
  string nome = puxanome();
  int dificuldade = dif(nome);
  //inicia o simulador
  //Para manter a main limpa, o jogo funciona pelo simulador
  Simulador *sim = new Simulador();
  sim->startSimulas(nome, dificuldade);

  cout << "Obrigado por jogar\n";
  return 0;
}
