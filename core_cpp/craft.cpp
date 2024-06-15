#include "../core_hpp/craft.hpp"

Craft::Craft(float price, int chanc, int time)
    : price(price), chanc(chanc), time(time) {}

Craft::Craft() {}

float Craft::getprice() { return price; }
int Craft::getchanc() { return chanc; }
int Craft::gettime() { return time; }
