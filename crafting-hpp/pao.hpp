#ifndef PAO
#define PAO

#include "../core_hpp/craft.hpp"

class pao:public Craft
{
    public:
        pao();
        pao(float pag, int time);


        int crafting() override;

};

#endif