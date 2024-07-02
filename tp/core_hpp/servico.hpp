#ifndef SERVICO
#define SERVICO

#include <string>

using std::string;

class Servico
{
    private:
        float pag; //pagamento do trabalho
        int time; //tempo de trabalho
        int chanc; //chance do trabalho falhar

    public:
        Servico(float pag, int time, int chanc); //construtor específico
        Servico(); //construtor padrão
        //getters
        float getpag(); 
        int getchanc();
        int gettime();
        //setters
        void setpag(float pag);
        //método trabalhar é inteiro, retornando o resultado do trabalho
        virtual int trabalhar(int chanc,int time)=0;
        virtual ~Servico() = default; 
};

#endif