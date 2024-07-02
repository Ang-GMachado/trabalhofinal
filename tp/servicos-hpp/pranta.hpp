#ifndef PRANTA
#define PRANTA

#include <string>
#include "../core_hpp/servico.hpp"

class Pranta:public Servico
{
    public:
        Pranta(float pag, int chanc, int time);

        int trabalhar(int time,int chanc) override;

};

#endif