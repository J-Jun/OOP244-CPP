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

#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds {

	// ========================= Public Members ==============================

	MotorVehicle::MotorVehicle(const char* licenseNumber, int builtYear) {

		if (licenseNumber != nullptr && strLen(licenseNumber) <= LICENSE_SIZE) {

			strCpy(licencePlateNumber, licenseNumber);
		}

		manufactureYear = builtYear;
		strCpy(vehicleAddress, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) {

		if (address != vehicleAddress && strLen(address) < ADDRESS_SIZE) {

			// Variable:
			char tempAddress[ADDRESS_SIZE];

			// Setting temporary address as the current address
			strCpy(tempAddress, vehicleAddress);

			// Setting into a new address
			strCpy(vehicleAddress, address);

			cout << "|";

			// License plate
			cout.width(8);
			cout <<right << licencePlateNumber;

			cout << "| |";

			// Current Address
			cout.width(20);
			cout << right << tempAddress;

			cout << " ---> ";
			
			// New Address
			cout.width(20);
			cout << left << vehicleAddress << "|" << endl;
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const {

		os << "| " << manufactureYear << " | " << licencePlateNumber << " | " << vehicleAddress;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) {

		cout << "Built year: ";
		in >> manufactureYear;

		cout << "License plate: ";
		in >> licencePlateNumber;

		cout << "Current location: ";
		in >> vehicleAddress;

		return in;
	}

	// ====================== Helper Functions =========================

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv) {

		mv.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, MotorVehicle& mv) {

		mv.read(in);
		return in;
	}
}


