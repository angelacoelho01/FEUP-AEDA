/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include <algorithm>
#include <numeric>

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};


class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};


class NoSuchBrandException{
private:
    std::string _brand;
public:
    NoSuchBrandException(std::string brand) : _brand(brand){};
    std::string getBrand() const {return _brand;}
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle) {
    if(vehicles.size() >= capacity) return false;
    for(const auto& v : vehicles){
        if(*v == *vehicle) return false;
    }
    vehicles.push_back(vehicle); return true;
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
    std::sort(vehicles.begin(), vehicles.end(), [](Vehicle* v1, Vehicle* v2){
       if(v1->getBrand() == v2->getBrand())
           return v1->getPrice() > v2->getPrice();
       return v1->getBrand() < v2->getBrand();
    });
}

template<class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model) {
    Vehicle* vehicleToRemove;
    for(unsigned int i = 0; i < vehicles.size(); i++){
        vehicleToRemove = vehicles.at(i);
        if((vehicleToRemove->getBrand() == brand) && (vehicleToRemove->getModel() == model)){
            vehicles.erase(vehicles.begin()+i);
            return vehicleToRemove;
        }
    }
    throw NoSuchVehicleException();
}

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const {
    std::vector<float> prices;
    for(const auto& v : vehicles){
        if(v->getBrand() == brand)
            prices.push_back(v->getPrice());
    }
    if(prices.empty()) throw NoSuchBrandException(brand);
    return std::accumulate(prices.begin(), prices.end(),0)/prices.size();
}

#endif /* SRC_GARAGE_H_ */
