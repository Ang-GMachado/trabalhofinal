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

    public:
        Servico(float pag, int chanc, int time);
        Servico();
        float getpag();
        int getchanc();
        int gettime();
        void setpag(float pag);

        virtual int trabalhar(int chanc,int time)=0;
        virtual ~Servico() = default; 
};

#endif