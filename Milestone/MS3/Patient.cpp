/*
	Final Project Milestone 3
	Module:         Patient
	Filename:       Patient.cpp
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
	-----------------------------------------------------------
	Date         Reason
	2020/03/23   Started to work on the Milestone 3
	2020/03/23   Debugged and submitted the Milestone 3
	-----------------------------------------------------------
	I have done all the coding by myself and only copied the code
	that my professor provided to complete my workshops and assignments.
	-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Ticket.h"
#include "Patient.h"
#include "utils.h"

using namespace std;
namespace sdds {

	// ======================== Constructor =======================
	Patient::Patient(int ticketNumber, bool ioFlag) : p_ticket(ticketNumber) {

		p_ioFlag = ioFlag;
	}

	// ======================== Destructor ========================
	Patient::~Patient() {

		delete[] p_patientName;
		p_patientName = nullptr;
	}

	// ===================== Member Functions =====================
	bool Patient::fileIO()const {

		return p_ioFlag;
	}

	void Patient::fileIO(bool boolMember) {

		p_ioFlag = boolMember;
	}

	bool Patient::operator== (const char n_char)const {

		return (n_char == this->type());
	}

	bool Patient::operator== (const Patient& n_patient)const {

		return (n_patient.type() == this->type());
	}

	void Patient::setArrivalTime() {

		p_ticket.resetTime();
	}

	Patient::operator Time()const {

		return (Time)p_ticket;
	}

	int Patient::number()const {

		return p_ticket.number();
	}

	// ============ Pure Virtual Function Overwrites ===============
	std::ostream& Patient::csvWrite(std::ostream& ostr)const {

		ostr << type() << ',' <<  p_patientName << ',' << p_ohipNumber << ',';
		p_ticket.csvWrite(ostr);
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr) {

		char n_patientName[101];
		istr.get(n_patientName, 101, ',');

		delete[] p_patientName;
		p_patientName = nullptr;
		p_patientName = new char[strlen(n_patientName) + 1];
		strcpy(p_patientName, n_patientName);
		istr.ignore(2000, ',');

		istr >> p_ohipNumber;
		istr.ignore(2000, ',');

		p_ticket.csvRead(istr);
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr)const {

		ostr << p_ticket << '\n'; 

		if (strlen(p_patientName) > 25) {
			for (int i = 0; i < 25; i++)
				ostr << p_patientName[i];
		}
		else
			ostr << p_patientName;
	
		ostr << ", OHIP: " << p_ohipNumber;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr) {

		delete[] p_patientName;
		p_patientName = nullptr;

		p_patientName = getcstr("Name: ", istr, '\n');
		p_ohipNumber = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ", true);
		return istr;
	}
}
