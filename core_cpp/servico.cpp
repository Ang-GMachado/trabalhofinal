#include "../core_hpp/servico.hpp"


Servico::Servico(float pag, int chanc, int time):pag(pag),chanc(chanc), time(time){
  
}

Servico::Servico(){}

float Servico::getpag(){
  return pag;
}
void Servico::setpag(float pag){
  this->pag = pag;
}
int Servico::gettime(){
  return time;
}
int Servico::getchanc(){
  return chanc;
}
