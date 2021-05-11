//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 7 - LAB
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#include "MotorVehicle.h"
#include "Truck.h"

using namespace std;

namespace sdds {

	// ========================= Public Members ==============================

	Truck::Truck(const char* licenseNumber, int manufactureYear, double truckCapacity, const char* currentAddress) : MotorVehicle(licenseNumber, manufactureYear)  {

		maxWeight = truckCapacity;
		cargoLoad = 0.0;
		MotorVehicle::moveTo(currentAddress);
	}

	bool Truck::addCargo(double cargo) {

		bool changedLoad = false;

		if (cargoLoad < maxWeight) {
			
			if ((cargoLoad + cargo) <= maxWeight) {

				cargoLoad += cargo;
			}
			else {
				cargoLoad = maxWeight;	
			}
			changedLoad = true;
		}
		return changedLoad;
	}

	bool Truck::unloadCargo() {

		bool unload = false;

		if (cargoLoad > 0) {
			cargoLoad = 0;
			unload = true;
		}
			
		return unload;
	}

	std::ostream& Truck::write(std::ostream& os) const {

		MotorVehicle::write(os);
		os << " | " << cargoLoad << "/" << maxWeight;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {

		MotorVehicle::read(in);

		cout << "Capacity: ";
		in >> maxWeight;

		cout << "Cargo: ";
		in >> cargoLoad;

		return in;
	}

	// ====================== Helper Functions =========================

	std::ostream& operator<<(std::ostream& os, const Truck& mv) {

		mv.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, Truck& mv) {

		mv.read(in);
		return in;
	}
}