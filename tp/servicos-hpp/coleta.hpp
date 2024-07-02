#ifndef COLETA
#define COLETA

#include <string>
#include "../core_hpp/servico.hpp"

class Coleta:public Servico
{
    public:
        Coleta(float pag, int chanc, int time);

        int trabalhar(int time,int chanc) override;
};

#endif