#include "zoo.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

void cleanLine(string& line){
    string cleanedLine;
    for(const auto& letter : line){
        if(letter == ' ' || isalpha(letter) || isdigit(letter))
            cleanedLine.push_back(letter);
    }
    line = cleanedLine;
}

unsigned Zoo::numAnimals() const {
    return animals.size();
}

unsigned Zoo::numVeterinarians() const {
    return veterinarians.size();
}

void Zoo::addAnimal(Animal *a1) {
    animals.push_back(a1);
}

string Zoo::getInfo() const {
    ostringstream out;
    for(const auto & animal : animals)
        out << animal->getInfo() << endl;
    return out.str();
}

bool Zoo::isYoung(string nameA) {
    for (const auto &animal : animals) {
        if (nameA == animal->getName())
            return animal->isYoung();
    }
    return false;
}

void Zoo::allocateVeterinarians(istream &isV) {
    string name, code;
    unsigned count = 0;
    for(string line; getline(isV, line); count++){
        cleanLine(line);
        if(count%2 == 0) {
            name = line;
        }
        else{
            code = line;
            veterinarians.push_back(new Veterinary(name, stoi(code)));
        }
    }

    for(unsigned int i=0; i < animals.size(); i++){
        if(i < veterinarians.size())
            animals[i]->setVeterinary(veterinarians[i]);
        else {
            unsigned index = rand() % veterinarians.size();
            animals[i]->setVeterinary(veterinarians[index]);
        }
    }
}

bool Zoo::removeVeterinary(string nameV) {
    auto nextVet = veterinarians.begin(); advance(nextVet, 1);
    for(const auto & animal : animals){
        if(animal->getVeterinary()->getName() == nameV) {
            animal->setVeterinary(*nextVet);
        }
    }
    for(unsigned i=0; i < veterinarians.size(); i++){
        if(veterinarians.at(i)->getName() == nameV) {
            nextVet+=i;
            veterinarians.erase(nextVet);
        }
    }
    if(nextVet == veterinarians.begin()) return false;
    return true;
}

bool Zoo::operator<(Zoo &zoo2) const {
    unsigned sumZoo1 = 0, sumZoo2 = 0;
    for(auto const & animal : animals)
        sumZoo1 += animal->getAge();
    for(const auto & animal : zoo2.animals)
        sumZoo2 += animal->getAge();
    return sumZoo1 < sumZoo2;
}