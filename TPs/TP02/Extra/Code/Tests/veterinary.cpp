#include "veterinary.h"
#include <sstream>
using namespace std;

Veterinary::Veterinary(string nome, int cod) : name(nome), codOrder(cod){
}

string Veterinary::getName() const {
    return name;
}

string Veterinary::getInfo() const {
    ostringstream out;
    out << name << ", " << codOrder;
    return out.str();
}


