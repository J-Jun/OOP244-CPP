/*
	Final Project Milestone 4
	Module:         Patient
	Filename:       Patient.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
*/

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include <iostream>

#include "Time.h"
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient : public IOAble {

		// ===================== Member Variables =====================
		char* p_patientName{ nullptr }; // Holds the name of the patient
		int p_ohipNumber;    // Holds the OHIP insurance number of the patient
		Ticket p_ticket;     // Holds the ticket of the patient for the lineup
		bool p_ioFlag;       // Holds the boolean value of the patient object

	public:

		// ======================== Constructor =======================
		Patient(int ticketNumber = 0, bool ioFlag = false);

		// ============== Copying Construct (Deleted) =================
		Patient(const Patient& src) = delete;

		// ============= Assignment Operator (Deleted) ================
		Patient& operator= (const Patient& src) = delete;

		// ======================== Destructor ========================
		~Patient();

		// ===================== Member Functions =====================
		virtual char type()const = 0;

		bool fileIO()const; // Returns the member fileIO flag
		void fileIO(bool boolMember); // Sets the member fileIO flag with the parameter

		bool operator== (const char n_char)const;        // Compares current object with an incoming single character
		bool operator== (const Patient& n_patient)const; // Compares current object to another patient

		void setArrivalTime(); // Sets the time of the ticket of the patient to the current time
		operator Time()const;  // Returns the time of the ticket
		int number()const;     // Returns the number of the ticket

		// ============ Pure Virtual Function Overwrites ===============
		std::ostream& csvWrite(std::ostream& ostr)const; // Inserts the following values into the ostream in a comma-separated format
		std::istream& csvRead(std::istream& istr);       // Extracts all the values in the same order as the csvWrite function, except for the type
		std::ostream& write(std::ostream& ostr)const;    // Inserts the patient information into the ostream to be displayed on the console
		std::istream& read(std::istream& istr);          // Extracts the ticket information from the console
	};
}
#endif // !SDDS_PATIENT_H_
