#ifndef HUNT
#define HUNT

#include <string>
#include "../core_hpp/servico.hpp"

class Hunt:public Servico
{
    public:
        Hunt(float pag, int chanc, int time);

        int trabalhar(int time,int chanc) override;

};

#endif