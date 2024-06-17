#ifndef CRAFT
#define CRAFT

#include <string>

using std::string;

class Craft
{
    private:
        float price;
        int time;
        int chanc;

    public:
        Craft();
        Craft(float price, int chanc, int time);
        float getprice();
        string gettipo();
        int getchanc();
        int gettime();
        

        virtual int crafting() = 0;

};

#endif