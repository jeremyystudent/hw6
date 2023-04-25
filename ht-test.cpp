#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
using namespace std;

struct TestHash2 {
    HASH_INDEX_T operator()(int k) const
    {
        return k;
    }
};

int main()
{
    DoubleHashProber<std::string, MyStringHash > dh;
    HashTable<
        std::string, 
        int, 
        DoubleHashProber<std::string, MyStringHash >, 
        std::hash<std::string>, 
        std::equal_to<std::string> > ht(0.7, dh);

    // This is just arbitrary code. Change it to test whatever you like about your 
    // hash table implementation.
    HashTable<string, int, LinearProber<string>, hash<string>, equal_to<string> > table;
    //Insert (one, 1)
    pair<string, int> pair1("one", 1);
    table.insert(pair1);
    //Insert (two, 2)
    pair<string, int> pair2("two", 2);
    table.insert(pair2);
    //Insert (three, 3)
    pair<string, int> pair3("three", 3);
    table.insert(pair3);


    return 0;
}
