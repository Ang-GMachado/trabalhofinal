#ifndef MINE
#define MINE

#include <string>
#include "../core_hpp/servico.hpp"

using std::string;

class Mine:public Servico
{
    public:
        Mine(float pag, int chanc, int time);

        int trabalhar(int time,int chanc) override;

};

#endif