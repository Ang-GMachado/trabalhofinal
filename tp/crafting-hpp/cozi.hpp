#ifndef COZI
#define COZI

#include "../core_hpp/craft.hpp"

class Cozi:public Craft
{
    public:
        Cozi(float pag, int time);


        int crafting() override;

};

#endif