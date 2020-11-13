#include "fleet.h"
#include <string>

using namespace std;

vector<Vehicle *> Fleet::getVehicles() const
{
    return vehicles;
}

void Fleet::addVehicle(Vehicle *vl)
{
    vehicles.push_back(vl);
}

int Fleet::numVehicles() const
{
    return vehicles.size();
}

int Fleet::lowestYear() const
{
    int result = 1;

    if(vehicles.size() == 0)
        result = 0;
    else{
        int lowYear = (*vehicles[0]).getYear();
        for(auto vl : vehicles)
        {
            if((*vl).getYear() < lowYear)
                lowYear = (*vl).getYear();
        }
        result = lowYear;
    }
    return result;
}

vector<Vehicle *> Fleet::operator()(int yearM) const
{
    vector<Vehicle *> vehiclesYearM;

    for(auto vl : vehicles)
    {
        if((*vl).getYear() == yearM)
            vehiclesYearM.push_back(vl);
    }
    return vehiclesYearM;
}

float Fleet::totalTax() const
{
    float total = 0;
    for(auto vl : vehicles)
    {
        total += (*vl).calculateTax();
    }
    return total;
}

unsigned Fleet::removeOldVehicles(int yl)
{
    unsigned total = 0;
    for(int i=0; i<vehicles.size(); i++)
    {
        if((*vehicles[i]).getYear() <= yl) {
            vehicles.erase(vehicles.begin() + i);
            i--;
            total++;
        }
    }
    return total;
}

ostream& operator<<(ostream & o, const Fleet & f)
{
    vector<Vehicle*> vehiclesCopy = f.getVehicles();
    for(auto vl : vehiclesCopy)
    {
        (*vl).info(o);
    }
    return o;
}




