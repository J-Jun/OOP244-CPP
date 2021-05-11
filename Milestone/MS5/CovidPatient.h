/*
	Final Project Milestone 5
	Module:         CovidPatient 
	Filename:		CovidPatient.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds {

	class CovidPatient : public Patient {

	public:

		// ===================== Default Constructor =====================
		CovidPatient(); // Sets the Ticket number to the current global value and then increases the global value by one 

		// ====================== Virtual Function =======================
		virtual char type()const; // Returns the letter "C" if the Patient object is identified as a Covid patient

		// ================= Virtual Functions Overrides =================
		std::ostream& csvWrite(std::ostream& ostr)const; // Calling "csvWrite" function of the base class
		std::istream& csvRead(std::istream& istr);       // Read the record of a Patient and sets the global ticket number 
		std::ostream& write(std::ostream& ostr)const;    // Writing the patient in a certain format
		std::istream& read(std::istream& istr);          // Reading the patient in a certain format

	};
}
#endif // !SDDS_COVIDPATIENT_H_



