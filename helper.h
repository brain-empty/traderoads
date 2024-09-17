#pragma once
#include<iostream>

#include"city.h"

namespace helper {
    void printRouteForCityByIndex (int i, int j) {
        char dir[4] = {'w', 'n', 'e', 's'};
        std::cout << std::endl << CityStatic::cities[i][j].id << std::endl << '-' << std::endl ;

        for (int k = 0 ; k < 4 ; k++ ) { 

            if ( CityStatic::cities[i][j].routes[dir[k]].a >= 0 ) {
                std::cout << dir[k] << std::endl ;
                std::cout << CityStatic::cities[i][j].routes[dir[k]].a << std::endl;
                std::cout << CityStatic::cities[i][j].routes[dir[k]].b << std::endl;
                std::cout << std::endl;
            }

        }
    }
}