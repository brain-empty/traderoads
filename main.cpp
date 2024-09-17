#include <iostream>
#include <string>
#include <typeinfo>

#include"city.h"
#include"helper.h"

int main () {
    int coins = 0;

    int cityGenCount = 25; //note that this number should be a perfect square

    CityStatic::generateCity(cityGenCount);

    return 0;
}