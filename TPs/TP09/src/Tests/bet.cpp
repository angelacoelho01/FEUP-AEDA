#include "bet.h"
#include <iostream>
#include <sstream>
using namespace std;


//TODO
bool Bet::contains(unsigned num) const{
	return numbers.find(num) != numbers.end();
}

//TODO
void Bet::generateBet(const vector<unsigned>& values, unsigned n){
    for(unsigned i = 0; i < n ; i++){
        if(numbers.find(values.at(i)) == numbers.end()) numbers.insert(values.at(i));
        else n++;
    }
}

//TODO
unsigned Bet::countRights(const tabHInt& draw) const{
    unsigned counter = 0;
    for(auto it = draw.begin(); it != draw.end(); it++)
        if(contains(*it)) counter++;
	return counter;
}
