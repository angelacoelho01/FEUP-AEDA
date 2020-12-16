#ifndef CARPARK_H_
#define CARPARK_H_

#include "insertionSort.h"
#include "sequentialSearch.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class InfoCard {
public:
    string name;
    bool present;
    int frequency;
    bool operator==(const InfoCard& I2) const;
    bool operator<(const InfoCard& I2) const;
};

class CarPark {
    unsigned freePlaces;
    const unsigned  capacity;
    vector<InfoCard> clients;
    const unsigned numMaxClients;
public:
    CarPark(unsigned cap, unsigned nMaxCli);
    unsigned getNumPlaces() const;
    unsigned getNumMaxClients() const;
    unsigned getNumOccupiedPlaces() const;
    vector<InfoCard> getClients() const;
    unsigned getNumClients() const;
    bool addClient(const string & name);
    bool removeClient(const string & name);
    bool enter(const string & name);
    bool leave(const string & name);
    int clientPosition(const string & name) const;
    friend ostream & operator<<(ostream & os, const CarPark & cp);
    unsigned getFrequency(const string &name) const;
    InfoCard getClientAtPos(unsigned p) const;
    void sortClientsByFrequency();
    void sortClientsByName();
    vector<string> clientsBetween(unsigned f1, unsigned f2);
};

class ClientDoesNotExist{
private:
    string _name;
public:
    ClientDoesNotExist(const string& name);
    string getName() const;
};

class PositionDoesNotExist{
private:
    unsigned int _position;
public:
    PositionDoesNotExist(unsigned int position);
    unsigned int getPosition() const;
};

#endif /*CARPARK_H_*/
