#include "carPark.h"

using namespace std;

bool InfoCard::operator==(const InfoCard &I2) const {
    return name == I2.name;
}

bool InfoCard::operator<(const InfoCard &I2) const {
    if(frequency == I2.frequency)
        return name < I2.name;
    return frequency > I2.frequency;
}

CarPark::CarPark(unsigned cap, unsigned nMaxCli): capacity(cap), numMaxClients(nMaxCli){
    freePlaces=cap;
}

vector<InfoCard> CarPark::getClients() const{
    return clients;
}

unsigned CarPark::getNumPlaces() const{
    return capacity;
}

unsigned CarPark::getNumOccupiedPlaces() const{
    return capacity-freePlaces;
}

unsigned CarPark::getNumMaxClients() const{
    return numMaxClients;
}

unsigned CarPark::getNumClients() const{
    return clients.size();
}

int CarPark::clientPosition(const string & name) const{
    return sequentialSearch(clients, InfoCard{name, false, 0});
}

unsigned CarPark::getFrequency(const string &name) const{
    unsigned index = clientPosition(name);
    if(index == -1) throw ClientDoesNotExist(name);
    return clients.at(clientPosition(name)).frequency;
}

bool CarPark::addClient(const string & name){
    if (clients.size() == numMaxClients) return false;
    if (clientPosition(name) != -1) return false;
    clients.push_back(InfoCard{name,false, 0});
    return true;
}

bool CarPark::removeClient(const string & name)
{
    for (vector<InfoCard>::iterator it = clients.begin(); it != clients.end(); it++)
        if (it->name == name) {
            if (!(it->present)) {
                clients.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}

bool CarPark::enter(const string & name){
    if (freePlaces == 0) return false;
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == true) return false;
    clients[pos].present = true;
    clients[pos].frequency++;
    freePlaces--;
    return true;
}

bool CarPark::leave(const string & name){
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == false) return false;
    clients[pos].present = false;
    freePlaces++;
    return true;
}

InfoCard CarPark::getClientAtPos(unsigned p) const{
    if(p < 0 || p >= clients.size()) throw PositionDoesNotExist(p);
    return clients[p];
}

void CarPark::sortClientsByFrequency(){
    insertionSort(clients);
}

void CarPark::sortClientsByName(){
    sort(clients.begin(), clients.end(), [](InfoCard client1, InfoCard client2){
        return client1.name < client2.name;
    });
}

vector<string> CarPark::clientsBetween(unsigned f1, unsigned f2){
    vector<string> names;
    sortClientsByFrequency();
    for(unsigned int i=0; i < clients.size();i++)
        if(clients.at(i).frequency >= f1 && clients.at(i).frequency <= f2)
            names.push_back(clients.at(i).name);
    return names;
}

ostream & operator<<(ostream & os, const CarPark & cp){
    for(const auto & client : cp.getClients())
        os << client.name << ", " << client.present << ", " << client.frequency << endl;
    return os;
}


ClientDoesNotExist::ClientDoesNotExist(const string& name): _name(name) {
}

string ClientDoesNotExist::getName() const {
    return _name;
}


PositionDoesNotExist::PositionDoesNotExist(unsigned int position) : _position(position){
}

unsigned int PositionDoesNotExist::getPosition() const {
    return _position;
}