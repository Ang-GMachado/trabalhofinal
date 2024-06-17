#ifndef VINEO
#define VINEO

#include "../core_hpp/craft.hpp"

class Vineo:public Craft
{
    public:
        Vineo();
        Vineo(float pag, int time);


        int crafting() override;

};

#endif