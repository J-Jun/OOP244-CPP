/*
	Final Project Milestone 4
	Module:         TriagePatient
	Filename:		TriagePatient.cpp
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
#include <cstring>

#include "Patient.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   // ===================== Default Constructor =====================
   TriagePatient::TriagePatient() : Patient(nextTriageTicket) {

	   t_symptoms = nullptr;
	   nextTriageTicket++;
   }

   // ====================== Virtual Function =======================
   char TriagePatient::type()const {

	   return 'T';
   }

   // ================= Virtual Functions Overrides =================
   std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const {

	   Patient::csvWrite(ostr);
	   ostr << "," << t_symptoms;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr) {

	   // Variable:
	   char symptom_records[500];

	   delete[] t_symptoms;
	   t_symptoms = nullptr;

	   Patient::csvRead(istr);
	   istr.ignore(2000, ',');
	   istr.get(symptom_records, 500, '\n');

	   t_symptoms = new char[strlen(symptom_records) + 1];
	   strcpy(t_symptoms, symptom_records);

	   nextTriageTicket = number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr)const {

	   if (fileIO())
		   csvWrite(ostr);
	   else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl;

		   ostr << "Symptoms: " << t_symptoms << endl;	   
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr) {

	   // Variable:
	   char p_symptoms[500];

	   if (fileIO())
		   csvRead(istr);
	   else {
		   delete[] t_symptoms;
		   t_symptoms = nullptr;

		   Patient::read(istr);

		   cout << "Symptoms: ";
		   istr.get(p_symptoms, 500, '\n');
		   istr.ignore();

		   t_symptoms = new char[strlen(p_symptoms) + 1];
		   strcpy(t_symptoms, p_symptoms);
	   }
	   return istr;
   }

   // ========================= Destructor ==========================
   TriagePatient::~TriagePatient() {

	   delete[] t_symptoms;
	   t_symptoms = nullptr;
   }
}