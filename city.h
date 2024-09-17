#pragma once
#include <string>
#include<iostream>
#include<cmath>
#include<fstream>
#include "route.h"
#include<map>
#include<vector>
#include<time.h>
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
        std::vector<std::string> cityNames;
        City cities [10][10];
        int count = 0;

        
        void getCityNames () {
            std::ifstream input ("citynames.txt");
            for ( std::string line ; std::getline( input, line ) ; ) {
                cityNames.push_back(line);
            }
        }

        void generateCity(int total) {
            srand(time(0));
            int sqrtTotal = std::sqrt(total);

            getCityNames();

            for (int i=0; i < sqrtTotal ; i++) { 
            
                for (int j=0; j < sqrtTotal ; j++) {
                    std::cout << count;
                    std::cout << " : " << i << j << " : " << cityNames[count] << std::endl;
                    
                    cities[i][j] = City(cityNames[count], count); // generate city, store it in matrix, give it a name from names arr n pass it "count" as the id

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
            cityNames.clear();
        }
}
