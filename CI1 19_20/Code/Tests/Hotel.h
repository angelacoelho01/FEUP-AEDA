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
/*    std::vector<Chamber*> temp;
    for(unsigned int p=1; p < chambers.size(); p++){

    } */
}

//TODO
template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor) {
    return NULL;
}

//TODO
template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const {
    return 0.0;
}

//TODO
template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor){
    return false;
}

//TODO
template<class Chamber>
std::list<Chamber> Hotel<Chamber>::roomsNeverReserved() const {
    std::list<Chamber> res;
    return res;
}


//TODO
class NoSuchFloorException {
public:
    int getFloor() { return 0;}
};


#endif /* SRC_HOTEL_H_ */
