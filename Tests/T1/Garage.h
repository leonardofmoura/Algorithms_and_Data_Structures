/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include <iostream>

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
	bool findVehicle(Vehicle * vehicle);
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() {};
};


class NoSuchBrandException {
	std::string brand;
public:
	NoSuchBrandException(std::string brand);
	std::string getBrand() const;
};

NoSuchBrandException::NoSuchBrandException(std::string brand)  {
	this->brand = brand;
}

std::string NoSuchBrandException::getBrand() const {
	return this->brand;
}


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
bool Garage<Vehicle>::findVehicle(Vehicle * vehicle) {
	for (int i = 0; i < this->vehicles.size(); i++ ) {
		if (*vehicles[i] == *vehicle) {
			return true;
		}
		else {
			return false;
		}
	}
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle * vehicle) {
	if (this->vehicles.size() < this->capacity && !this->findVehicle(vehicle)) {
		this->vehicles.push_back(vehicle);
		return true;
	}
	else {
		return false;
	}

}

template<class Vehicle>
bool compare (Vehicle * v1, Vehicle * v2) {
	return (*v1 < *v2);
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
	sort(this->vehicles.begin(), this->vehicles.end(),compare<Vehicle>);

}

template<class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model) {

	for (int i = 0; i < vehicles.size(); i++) {
		if (vehicles[i]->getBrand() == brand && vehicles[i]->getModel() == model) {

			Vehicle* ret = vehicles[i];
			vehicles.erase(vehicles.begin() + i);
			return ret;
		}
	}

	throw NoSuchVehicleException();
}

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const {
	float price = 0;
	float n_cars = 0;
	for (int i = 0; i < vehicles.size(); i++) {
		if (vehicles[i]->getBrand() == brand) {
			price += vehicles[i]->getPrice();
			n_cars++;
		}
	}

	if (price != 0) {
		return price/n_cars;
	}
	else {
		throw NoSuchBrandException(brand);
	}


}

#endif /* SRC_GARAGE_H_ */
