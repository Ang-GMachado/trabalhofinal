#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include <string>

using namespace std;
using std::string;

class Simulador{
    private:
        float wallet;
    public:
        int round;
        void startSimulas(string playername, int dif);
        void NewRound(string playername,int round, int dif);
        void Rest(string playername,int round, int dif);
        

        float getwallet();
        void setwallet(float dineros);

        int trabalo(int dif, int time);
        int careft(int choice,int time);
        int Passa(int time, float din);

        void gameover(int round, float wallet);
};
#endif