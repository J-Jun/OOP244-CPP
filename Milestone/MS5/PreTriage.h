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

#ifndef SDDS_PRETRIAGE_H
#define SDDS_PRETRIAGE_H

#include "Patient.h"
#include "Menu.h"

namespace sdds {
    const int maxNoOfPatients = 100; // Max number of patients in the lineup (Covid and Triage)
    class PreTriage {
        Time
            m_averCovidWait,  // Holds the average wait time for COVID test per patient 
            m_averTriageWait; // Holds the average wait time for Triage per patient
        Patient* m_lineup[maxNoOfPatients]{}; // An array of Patient pointers to hold COVID and Triage Patient lineups dynamically
        char* m_dataFilename = nullptr; // Holds the name of the data file dynamically
        int m_lineupSize = 0;           // Number of Patients in the lineup
        Menu
            m_appMenu, // Holds the main menu
            m_pMenu;   // Holds the COVID/Triage patient selection
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const; // Returns the product of estimated wait time by the number of patients
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
    public:
        PreTriage(const char* dataFilename); 
        ~PreTriage();
        void run(void);
    };
}
#endif // !SDDS_PRETRIAGE_H