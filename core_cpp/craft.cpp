#include "../core_hpp/craft.hpp"

Craft::Craft(float price, int time, int chanc)
    : price(price), time(time), chanc(chanc) {}

Craft::Craft() {}

float Craft::getprice() { return price; }
int Craft::gettime() { return time; }
int Craft::getchanc() { return chanc; }
