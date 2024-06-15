#ifndef SERVICO
#define SERVICO

#include <string>

using std::string;

class Servico
{
    private:
        float pag;
        int time;
        int chanc;
        string tipo;

    public:
        Servico();
        Servico(float pag, int chanc, int time);
        float getpag();
        int gettime();
        int getchanc();
        void setpag(float pag);

        virtual int trabalhar(int time, int chanc);

};

#endif