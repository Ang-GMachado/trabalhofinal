#ifndef SIMULADOR
#define SIMULADOR

#include <string>

using namespace std;

class Simulador{
    private:
        float wallet; //somente a carteira do jogador é privada
        
    public:
        //variáveis nome e round são públicas
        int round;
        string playername;

        void startSimulas(string playername, int dif); //inicia o simulador
        void NewRound(string playername,int round, int dif); //cada round
        void Rest(string playername,int round, int dif); //descansa
        void Passa(int time, float din, int dif); //passa o tempo
        
        
        //getter e setter da carteira
        float getwallet();
        void setwallet(float dineros);

        int trabalo(int dif, int time); //função para escolher o trabalho
        int careft(int choice,int time, int dif); //função para escolher um craft
        
        void gameover(int round, float wallet); //o fim do jogo
};
#endif