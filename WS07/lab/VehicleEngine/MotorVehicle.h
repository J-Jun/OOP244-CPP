//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 7 - LAB
//==============================================

#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__

#include <iostream>

// Character Sizes:
#define LICENSE_SIZE 9
#define ADDRESS_SIZE 64

namespace sdds {

	class MotorVehicle {

		// License plate number
		char licencePlateNumber[LICENSE_SIZE];

		// The address where the vehicle is kept
		char vehicleAddress[ADDRESS_SIZE];

		// The year when the vehicle was built
		int manufactureYear;

	public:

		// Custom constructor
		MotorVehicle(const char* licenseNumber, int manufactureYear);

		// Moves the vehicle to the new address
		void moveTo(const char* address);

		// A query that inserts the content of the object 
		std::ostream& write(std::ostream& os) const;

		// A mutator that reads from the stream the data, for the current object
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv);
	std::istream& operator>>(std::istream& in, MotorVehicle& mv);
}
#endif // !SDDS_MOTORVEHICLE_H__