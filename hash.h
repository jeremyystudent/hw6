#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        std::string copy = k;
        size_t result = 0;
        int counter = 4;
        while(copy.size()> 6){
            std::string substr = copy.substr(copy.size()-6);
            int x = letterDigitToNumber(substr[0]);
            for(int i = 1;i<6;i++){
                x *= 36;
                x += letterDigitToNumber(substr[i]);
            }
            std::cout << "w[] = " << rValues[counter]*x << std::endl;
            result += rValues[counter]*x;
            counter--;
            copy = copy.substr(0,copy.size()-6);
        }
        int x = letterDigitToNumber(copy[0]);
        for(int i = 1;i<copy.size();i++){
            x *= 36;
            x += letterDigitToNumber(copy[i]);
        }
        result += rValues[counter]*x;
        return result;
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        if(letter < 60){return letter - '0' + 26;}
        if(letter >= 'a'){
            return letter - 'a';
        }else{
            return letter - 'A';
        }

    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
