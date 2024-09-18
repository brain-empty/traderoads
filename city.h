#pragma once

#include <string>
#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>

#include "route.h"

class City {
    public:
    std::string name;
    int id;
    std::map<char, Route> routes;

    City () {}

    City (std::string cityName, int cityId) {
        name = cityName;
        id = cityId;
    }
};

namespace CityStatic{
        City cities [10][10];
        int count = 0;

        
        std::vector<std::string> getCityNames (int total) {

            std::vector<std::string> tempCityNames;
            std::ifstream input ("citynames.txt");

            for ( std::string line ; std::getline( input, line ) ; ) {
                tempCityNames.push_back(line);
            }

            std::random_device rd;
            std::default_random_engine engine(rd()); 

            std::shuffle(tempCityNames.begin(), tempCityNames.end(), engine);

            std::vector<std::string> cityNames(tempCityNames.begin(), tempCityNames.begin() + total);

            return cityNames;
        }

        void generateCity(int total) {
            int sqrtTotal = std::sqrt(total);

            std::vector<std::string> cityNames = getCityNames(total);

            for (int i=0; i < sqrtTotal ; i++) { 
            
                for (int j=0; j < sqrtTotal ; j++) {
                    std::cout << count;
                    std::cout << " : " << i << j << " : " << cityNames[count] << std::endl;
                    
                    cities[i][j] = City(cityNames[count], count); // generate city, store it in matrix

                    if ( i - 1 >= 0 ) {
                        // make routes top
                        cities[i][j].routes['n'] = Route(cities[i-1][j].id, cities[i][j].id);
                        cities[i-1][j].routes['s'] = cities[i][j].routes['n'];
                    }
                    if ( j - 1 >= 0 ) {
                        //make routes left
                        cities[i][j].routes['w'] = Route(cities[i][j-1].id, cities[i][j].id);
                        cities[i][j-1].routes['e'] = cities[i][j].routes['w'];

                    }
                    count += 1;
                }

            }
        }
}
