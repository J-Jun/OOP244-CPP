//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 7 - LAB
//==============================================

#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__

#include <iostream>

#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle {

		// Maximum weight of the cargo 
		double maxWeight;

		// Current cargo load weight
		double cargoLoad;

	public:

		// Custom constructor
		Truck(const char* t_licenseNumber, int manufactureYear, double truckCapacity, const char* currentAddress);

		// A mutator that adds new weight to the current cargo
		bool addCargo(double cargo);

		// A mutator that unloads current cargo
		bool unloadCargo();

		// A query that inserts the content of the object 
		std::ostream& write(std::ostream& os) const;

		// A mutator that reads from the stream the data, for the current object
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& mv);
	std::istream& operator>>(std::istream& in, Truck& mv);
}
#endif // !SDDS_TRUCK_H__