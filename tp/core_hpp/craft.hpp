#ifndef CRAFT
#define CRAFT

#include <string>

using std::string;

class Craft
{
    private:
        float price; //preço do craft
        int time; //tempo de refinar
        int chanc; //chance de falhar

    public:
        Craft(float price, int time, int chanc); //construtor específico
        Craft(); //construtor padrão
//getters
        float getprice(); 
        int getchanc();
        int gettime();
        
//o método crafting é virtual para que a classe pai possa ser usada como base para as outras classes, que farão override deste método
        virtual int crafting() = 0;

};

#endif