#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <vector>
#include <list>

template <class Chamber>
class Hotel {
	std::vector<Chamber *> chambers;
	const unsigned int maxCapacity;
	const std::string city;
    std::list<Chamber> reservationsDone;
public:
	Hotel(int size, std::string municipality);
	~Hotel();
	std::vector<Chamber *> getChambers() const;
	void setChambers(std::vector<Chamber *> chambers);
	int getCapacity() const;
    std::list<Chamber> getReservationsDone() const;
	bool addChamber(Chamber *chamber);
    void addReservationDone(Chamber chamber);
    Chamber* removeChamber(std::string code, int floor);
	float avgArea(int floor) const;
	void sortChambers();
	bool doReservation(std::string code, int floor);
    std::list<Chamber> roomsNeverReserved() const;
};

class NoSuchChamberException {
public:
	NoSuchChamberException() { }
};

template <class Chamber>
Hotel<Chamber>::Hotel(int size, std::string municipality) : maxCapacity(size), city(municipality) {
}

template <class Chamber>
Hotel<Chamber>::~Hotel(){
	typename std::vector<Chamber *>::const_iterator it;
	for (it=chambers.begin(); it!=chambers.end(); it++) {
		delete *it;
	}
}

template<class Chamber>
std::vector<Chamber *> Hotel<Chamber>::getChambers() const {
	return chambers;
}

template<class Chamber>
void Hotel<Chamber>::setChambers(std::vector<Chamber*> chambers) {
	this->chambers = chambers;
}

template<class Chamber>
int Hotel<Chamber>::getCapacity() const {
	return maxCapacity;
}

template<class Chamber>
void Hotel<Chamber>::addReservationDone(Chamber chamber) {
    reservationsDone.push_back(chamber);
}

template<class Chamber>
std::list<Chamber> Hotel<Chamber>::getReservationsDone() const {
    return reservationsDone;
}

//------------------------------------------------------
//------------------------------------------------------

//TODO
template<class Chamber>
bool Hotel<Chamber>::addChamber(Chamber *chamber) {
    if(reservationsDone.size() < maxCapacity){
        for(const auto & ch : chambers){
            if(*ch == *chamber)
                return false;
        }
        chambers.push_back(chamber);
        return true;
    }
    return false;
}


//TODO
template<class Chamber>
void Hotel<Chamber>::sortChambers() {
    std::sort(chambers.begin(), chambers.end(), [](Chamber* c1, Chamber* c2){
       if(c1->getCode() == c2->getCode())
           return c1->getFloor() > c2->getFloor();
       return c1->getCode() < c2->getCode();
    });

}

//TODO
template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor) {
    Chamber chamber(code, floor);
    for(unsigned int i=0; i < chambers.size(); i++){
        if(*(chambers.at(i)) == chamber){
            Chamber* chamberRemoved = chambers.at(i);
            chambers.erase(chambers.begin()+i);
            return chamberRemoved;
        }
    }
    throw NoSuchChamberException();
}

//TODO
class NoSuchFloorException {
private:
    int _floor;
public:
    NoSuchFloorException(int floor) : _floor(floor){};
    int getFloor() { return _floor;}
};

//TODO
template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const {
    float sum = 0; int count = 0;
    for(const auto& chamber : chambers){
        if(chamber->getFloor() == floor) {
            sum += chamber->getArea();
            count++;
        }
    }
    if(count == 0) throw NoSuchFloorException(floor);
    return sum/count;
}

//TODO
template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor){
    for(const auto& ch : chambers){
        if(*ch == Chamber(code, floor)) {
            if(ch->getReservation()) return false;
            ch->setReservation(true);
            reservationsDone.push_back(*ch);
            return true;
        }
    }
    return false;
}

//TODO
template<class Chamber>
std::list<Chamber> Hotel<Chamber>::roomsNeverReserved() const {
    std::list<Chamber> rooms;
    for(const auto& ch : chambers){
        bool found = false;
        for(auto it = reservationsDone.begin(); it != reservationsDone.end(); it++){
            if(*it == *ch) found = true;
        }
        if(!found) rooms.push_back(*ch);
    }
    return rooms;
}

#endif /* SRC_HOTEL_H_ */
