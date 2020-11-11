#include "animal.h"
#include <sstream>
using namespace std;

int Animal::youngest = 9999;

Animal::Animal(string name, int age) : name(name), age(age), vet(nullptr){
    if(age < youngest) youngest = age;
}

string Animal::getName() const {
	return name;
}

int Animal::getAge() const {
    return age;
}

void Animal::setVeterinary(Veterinary *vet) {
    this->vet = vet;
}

Veterinary *Animal::getVeterinary() const {
    return vet;
}

int Animal::getYoungest() {
    return youngest;
}

string Animal::getInfo() const {
    ostringstream out;
    if(vet == nullptr)
        out << name << ", " << age;
    else
        out << name << ", " << age << ", " << vet->getInfo();
    return out.str();
}


Dog::Dog(string name, int age, string breed) : Animal(name, age), breed(breed) {
}

bool Dog::isYoung() const {
    if(age < 5) return true;
    return false;
}

string Dog::getInfo() const {
    ostringstream out;
    if(vet == nullptr)
        out << name << ", " << age << ", " << breed ;
    else
        out << name << ", " << age << ", " << vet->getInfo() << ", " << breed ;
    return out.str();
}


Flying::Flying(int maxv, int maxa) : maxVelocity(maxv), maxAltitude(maxa){
}


Bat::Bat(string name, int age, int maxv, int maxa) : Animal(name, age), Flying(maxv, maxa){
}

bool Bat::isYoung() const {
    if(age < 4) return true;
    return false;
}

string Bat::getInfo() const {
    ostringstream out;
    if(vet == nullptr)
        out << name << ", " << age << ", " << maxVelocity << ", " << maxAltitude;
    else
        out << name << ", " << age << ", " << vet->getInfo() << ", " << maxVelocity << ", " << maxAltitude;
    return out.str();
}

