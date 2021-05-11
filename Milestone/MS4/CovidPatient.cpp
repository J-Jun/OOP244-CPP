/*
	Final Project Milestone 4
	Module:         CovidPatient
	Filename:		CovidPatient.h
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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Patient.h"
#include "CovidPatient.h"

using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   // ===================== Default Constructor =====================
   CovidPatient::CovidPatient() : Patient(nextCovidTicket)  {

	   nextCovidTicket++;
   }

   // ====================== Virtual Function =======================
   char CovidPatient::type()const {

	   return 'C';
   }

   // ================= Virtual Functions Overrides =================
   std::ostream& CovidPatient::csvWrite(std::ostream& ostr)const {

	   Patient::csvWrite(ostr);
	   return ostr;
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {

	   Patient::csvRead(istr);
	   nextCovidTicket = number() + 1;
	   istr.ignore();
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr)const {

	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr);
		   ostr << endl;
	   }
	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr) {

	   if (fileIO())
		   csvRead(istr);
	   else
		   Patient::read(istr);

	   return istr;
   }
}