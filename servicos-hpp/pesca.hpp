#ifndef PESCA
#define PESCA

#include <string>
#include "../core_hpp/servico.hpp"

class Pesca:public Servico
{
    public:
        Pesca(float pag, int chanc, int time);

        int trabalhar(int time,int chanc) override;

};

#endif