#include "../core_hpp/servico.hpp"

Servico::Servico(float pag, int time, int chanc)
    : pag(pag), time(time), chanc(chanc) {}

Servico::Servico() {}

float Servico::getpag() { return pag; }
void Servico::setpag(float pag) { this->pag = pag; }
int Servico::getchanc() { return chanc; }
int Servico::gettime() { return time; }