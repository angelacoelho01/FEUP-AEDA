#include <queue>
#include <cstdlib>
#include "counter.h"
#include "exceptions.h"
using namespace std;


Client::Client() : numGifts(rand() % 5 + 1){
}

unsigned Client::getNumGifts() const {
    return numGifts;
}


Counter::Counter(unsigned wt)
    : clients(queue<Client>()), wrappingTime(wt), actualTime(0),
    nextEnter(rand() % 20 + 1), nextLeave(0), numAttendedClients(0) {
}

unsigned Counter::getActualTime() const {
    return actualTime;
}

unsigned Counter::getNextEnter() const {
    return nextEnter;
}

unsigned Counter::getNumAttendedClients() const {
    return numAttendedClients;
}

unsigned Counter::getWrappingTime() const {
    return wrappingTime;
}

unsigned Counter::getNextLeave() const {
    return nextLeave;
}

Client & Counter::getNextClient() {
    if(clients.empty()) throw EmptyQueue();
    return clients.front();
}

void Counter::enter(){
    Client client;
    nextEnter = rand() % 20 + 1;
    if(clients.empty()) nextLeave = (actualTime + client.getNumGifts()) * wrappingTime;
    clients.push(client);
    cout << "actualTime =  " << actualTime << ", numGifts = " << client.getNumGifts() << endl;
}

void Counter::leave(){
    if(clients.empty()) throw EmptyQueue();
    Client clientRemove = getNextClient();
    clients.pop();
    nextLeave = (actualTime + clientRemove.getNumGifts()) * wrappingTime;
    cout << "actualTime =  " << actualTime << ", numGifts = " << clientRemove.getNumGifts() << endl;
}

void Counter:: nextEvent(){
    if((nextLeave <= nextEnter) && (!clients.empty())) {
        leave();
        actualTime += nextLeave;
    }
    else {
        enter();
        actualTime += nextEnter;
    }
}

ostream & operator << (ostream & out, const Counter & c2){
    out << "Number of attended clients: " << c2.getNumAttendedClients() << " Number of clients waiting: " << c2.clients.size() << endl;
    return out;
}
