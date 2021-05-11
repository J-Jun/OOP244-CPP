/*
	Final Project Milestone 5
	Module:         PreTriage
	Filename:		PreTriage.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
	-----------------------------------------------------------
	Date         Reason
	2020/03/31   Started to work on the Milestone 5
	2020/04/08   Debugged the Milestone 5
	2020/04/08   Submitted the Milestone 5
	-----------------------------------------------------------
	I have done all the coding by myself and only copied the code
	that my professor provided to complete my workshops and assignments.
	-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>

#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"

using namespace std;
namespace sdds {

	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5),
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {

		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage() {

		ofstream d_file(m_dataFilename);
		d_file << m_averCovidWait << "," << m_averTriageWait << endl;
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait << endl;
		cout << "   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;

		for (int i = 0; i < m_lineupSize; i++) {

			m_lineup[i]->fileIO(true);
			d_file << *m_lineup[i] << endl;
			cout << (i + 1) << "- " << *m_lineup[i] << endl;
		}

		for (int i = 0; i < m_lineupSize; i++) {

			delete m_lineup[i];
			m_lineup[i] = nullptr;
		}

		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		cout << "done!" << endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p)const {

		int matchingPatient = 0;

		for (int i = 0; i < m_lineupSize; i++) {

			if (m_lineup[i]->type() == p.type())
				matchingPatient++;
		}
		return (Time(p) *= matchingPatient);
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {

		Time CT;
		CT.setToNow();

		if (p.type() == 'C')
			m_averCovidWait = ((int)(CT - Time(p)) + ((int)m_averCovidWait * (p.number() - 1))) / p.number();
		else if (p.type() == 'T')
			m_averTriageWait = ((int)(CT - Time(p)) + ((int)m_averTriageWait * (p.number() - 1))) / p.number();
	}

	void PreTriage::removePatientFromLineup(int index) {

		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const {

		int firstIndex = -1;
		bool patientFound = false;

		for (int i = 0; i < m_lineupSize && !patientFound; i++) {

			if (m_lineup[i]->type() == type) {
				firstIndex = i;
				patientFound = true;
			}
		}
		return firstIndex;
	}

	void PreTriage::load() {
	
		Patient* n_patient = nullptr;

		ifstream d_file(m_dataFilename);
		cout << "Loading data..." << endl;

		d_file >> m_averCovidWait;
		d_file.ignore(2000, ',');
		d_file >> m_averTriageWait;
		d_file.ignore(2000, '\n');

		for (int i = 0; i < maxNoOfPatients && d_file; i++) {

			char firstCharacter = '\0';

			d_file >> firstCharacter;
			d_file.ignore(2000, ',');

			if (firstCharacter == 'C') {
				n_patient = new CovidPatient();
			}
			else if (firstCharacter == 'T') {
				n_patient = new TriagePatient();
			}

			if (n_patient != nullptr) {

				n_patient->fileIO(true);
				n_patient->csvRead(d_file);
				n_patient->fileIO(false);
				m_lineup[i] = n_patient;
				n_patient = nullptr;
				m_lineupSize++;
			}
		}

		if (d_file)
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;

		if (m_lineupSize == 0)
			cout << "No data or bad data file!" << endl << endl;
		else 
			cout << m_lineupSize << " Records imported..." << endl << endl;		
	}

	void PreTriage::reg() {

		// Variable:
		int m_select;

		if (m_lineupSize >= maxNoOfPatients) {
			cout << "Line up full!" << endl;
		}
		else {
			m_pMenu >> m_select;
			switch (m_select) {

			case 1:
				m_lineup[m_lineupSize] = new CovidPatient();
				break;

			case 2:
				m_lineup[m_lineupSize] = new TriagePatient();
				break;

			case 0:
				break;

			default:
				break;
			}
			m_lineup[m_lineupSize]->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			m_lineup[m_lineupSize]->fileIO(false);
			m_lineup[m_lineupSize]->read(cin);
			cout << endl;
			cout << "******************************************" << endl;
			m_lineup[m_lineupSize]->write(cout);
			cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
			cout << "******************************************" << endl << endl;
			m_lineupSize++;
		}
	}

	void PreTriage::admit() {

		int m_select, nextPatient;
		char type = '\n';

		m_pMenu >> m_select;
		switch (m_select) {

		case 1:
			type = 'C';
			break;

		case 2:
			type = 'T';
			break;

		case 0:
			break;

		default:
			break;
		}

		nextPatient = indexOfFirstInLine(type);
		if (nextPatient != -1) {

			cout << endl;
			cout << "******************************************" << endl;
			m_lineup[nextPatient]->fileIO(false);
			cout << "Calling for ";
			m_lineup[nextPatient]->write(cout);
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[nextPatient]);
			removePatientFromLineup(nextPatient);
		}
	}

	void PreTriage::run(void) {

		int m_select;

		do {
			m_appMenu >> m_select;
			switch (m_select) {

			case 1:
				reg();
				break;

			case 2:
				admit();
				break;

			case 0:
				break;

			default:
				cout << "Wrong option. Try again.";
				break;
			}
		} while (m_select != 0);
	}
}