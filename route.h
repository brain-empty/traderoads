#pragma once
#include<string>
#include<cstdlib>
#include<time.h>


class Route {
    public:
    int a;
    int b;

    int banditRisk;
    int roadCondition;

    Route () {}

    Route (int fromCity, int toCity) {
        srand(time(0));

        a = fromCity;
        b = toCity;

        banditRisk = (rand() % ( 70 - 5 + 1)) + 5;
        roadCondition = (rand() % ( 95 - 30 + 1)) + 30;
    }

};