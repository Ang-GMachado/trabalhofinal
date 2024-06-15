#ifndef FORGE
#define FORGE

#include "../core_hpp/craft.hpp"

class Forge:public Craft
{
    public:
        Forge();
        Forge(float pag, int chanc, int time);

            
        int crafting() override;

};

#endif