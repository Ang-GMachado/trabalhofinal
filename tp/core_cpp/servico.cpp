#include "../core_hpp/servico.hpp"
//classe pai de todos os serviços

//construtor padrão e construtor específico da classe pai
Servico::Servico(float pag, int time, int chanc)
    : pag(pag), time(time), chanc(chanc) {}
Servico::Servico() {}

//getters das variáveis e setter do pagamento
float Servico::getpag() { return pag; }
void Servico::setpag(float pag) { this->pag = pag; }
int Servico::getchanc() { return chanc; }
int Servico::gettime() { return time; }