/*
	Final Project Milestone 4
	Module:         TriagePatient 
	Filename:		TriagePatient.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
	-----------------------------------------------------------
	Date         Reason
	2020/03/28   Started to work on the Milestone 4
	2020/03/28   Debugged and submitted the Milestone 4
	-----------------------------------------------------------
	I have done all the coding by myself and only copied the code
	that my professor provided to complete my workshops and assignments.
	-----------------------------------------------------------
*/

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds {
	
	class TriagePatient : public Patient {

		char* t_symptoms;

	public:

		// ===================== Default Constructor =====================
		TriagePatient();

		// ====================== Virtual Function =======================
		virtual char type()const;

		// ================= Virtual Functions Overrides =================
		std::ostream& csvWrite(std::ostream& ostr)const; // Adds the symptoms to the comma-separated values of the patient
		std::istream& csvRead(std::istream& istr);       // Read the record of a triage Patient and sets the global ticket number 
		std::ostream& write(std::ostream& ostr)const;    // Writing the patient in a certain format
		std::istream& read(std::istream& istr);          // Reading the patient in a certain format

		// ========================= Destructor ==========================
		~TriagePatient(); // Deletes the memory pointed by the symptoms member variable
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


