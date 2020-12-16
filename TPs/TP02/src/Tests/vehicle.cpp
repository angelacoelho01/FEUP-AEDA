#include "vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string b, int m, int y) : brand(b), month(m), year(y){}

int Vehicle::getYear() const{ return year; }

string Vehicle::getBrand() const{ return brand; }

int Vehicle::info() const
{
    int numVar = 3;
    return numVar;
}

int Vehicle::info(ostream &o) const
{
    int numVar = 3;
    o << brand << ", " << month << ", " << year << endl;
    return numVar;
}

bool Vehicle::operator<(const Vehicle &v) const
{
    bool result = false;
    if(year < v.year)
        result = true;
    else if((year == v.year) && (month < v.month))
        result = true;

   return result;
}


/*MotorVehicle*/

MotorVehicle::MotorVehicle(string b, int m, int y, string f, int cyl) : Vehicle(b, m, y)
{
        fuel = f;
        cylinder = cyl;
}

string MotorVehicle::getFuel() const { return fuel; }

int MotorVehicle::info() const
{
    int numVar = 5;
    return numVar;
}

int MotorVehicle::info(ostream &o) const
{
    int numVar = 5;
    o << brand << ", " << month << ", " << year << ", " << fuel << ", " << cylinder << endl;
    return numVar;
}

float MotorVehicle::calculateTax() const
{
    float tax;
    if((fuel == "gas" && cylinder <= 1000) || (fuel != "gas" && cylinder <= 1500))
    {
        if(year > 1995)
            tax = 14.56;
        else
            tax = 8.10;
    }
    else if((fuel == "gas" && (cylinder > 1000 && cylinder <= 1300)) || (fuel != "gas" && (cylinder > 1500 && cylinder <= 2000)))
    {
        if(year > 1995)
            tax = 29.06;
        else
            tax = 8.10;
    }
    else if((fuel == "gas" && (cylinder > 1300 && cylinder <= 1750)) || (fuel != "gas" && (cylinder > 2000 && cylinder <= 3000)))
    {
        if(year > 1995)
            tax = 45.15;
        else
            tax = 22.65;
    }
    else if((fuel == "gas" && (cylinder < 1750 && cylinder >= 2600)) || (fuel != "gas" && cylinder > 3000))
    {
        if (year > 1995)
            tax = 113.98;
        else
            tax = 54.89;
    }
    else if(fuel == "gas" && (cylinder > 2600 && cylinder <= 3500))
    {
        if(year > 1995)
            tax = 181.17;
        else
            tax = 87.13;
    }
    else if(fuel == "gas" && cylinder > 3500)
    {
        if(year < 1995)
            tax = 320.89;
        else
            tax = 148.37;
    }
    return tax;
}

/*Car*/

Car::Car(string b, int m, int y, string f, int cyl) : MotorVehicle(b,m, y, f, cyl){}

int Car::info() const
{
    int numVar = 5;
    return numVar;
}

int Car::info(ostream &o) const
{
    int numVar = 5;
    o << brand << ", " << month << ", " << year << ", " << fuel << ", " << cylinder << endl;
    return numVar;
}

/*Truck*/

Truck::Truck(string b, int m, int y, string f, int cyl, int ml) : MotorVehicle(b, m, y, f, cyl) { maximumLoad = ml; }

int Truck::info() const
{
    int numVar = 6;
    return numVar;
}

int Truck::info(ostream &o) const
{
    int numVar = 6;
    o << brand << ", " << month << ", " << year << ", " << fuel << ", " << cylinder << ", " << maximumLoad << endl;
    return numVar;
}

/*Bicycle*/

Bicycle::Bicycle(string b, int m, int y, string t) : Vehicle(b, m, y) { type = t; }

int Bicycle::info() const
{
    int numVar = 4;
    return numVar;
}

int Bicycle::info(ostream &o) const
{
    int numVar = 4;
    o << brand << ", " << month << ", " << year << ", " << type << endl;
    return numVar;
}
float Bicycle::calculateTax() const { return 0; }
