#include "../core_hpp/craft.hpp"
//Classe pai de todas as refinações

//construtor padrão e construtor específico da classe pai
Craft::Craft(float price, int time, int chanc)
    : price(price), time(time), chanc(chanc) {}
Craft::Craft() {}

//getters
float Craft::getprice() { return this->price; }
int Craft::gettime() { return this->time; }
int Craft::getchanc() { return this->chanc; }
//A classe pai não tem métodos além dos getters
//No contexto do código, não há necessidade de setters