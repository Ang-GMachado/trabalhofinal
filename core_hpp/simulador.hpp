#ifndef SIMULAS
#define SIMULAS

#include <string>

using namespace std;
using std::string;

class Simulador{
    protected:
        float wallet;
        int exaust;
    public:
        Simulador(string playername, int dif);
        int round;

        void NewRound(int round, int exaust);
        string getplayername();
        int getdif();
        void trabalo();
        void careft();
        void noite();
        void ganhagrana(float wallet);
        void gameover(int round, float wallet);
};
#endif