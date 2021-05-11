/*
	Final Project Milestone 3
	Module:         Ticket
	Filename:       Ticket.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
	-----------------------------------------------------------
	Date         Reason
	2020/03/23   Started to work on the Milestone 3
	2020/03/23   Read and understand what this class does
	-----------------------------------------------------------
*/

#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
namespace sdds {
	class Ticket:public IOAble{

		// The time the Ticket was issued
		Time m_time; 

		// Ticket number
		int m_number;
	public:

		// ===================== Constructor ======================
		Ticket(int number);

		// =================== Member Functions ===================
		operator Time()const; // Return m_time
		int number()const;    // Return the number of the ticket
		void resetTime();     // Sets the Ticket time to the current time
		 
		// ============== Virtual Function Overrides ==============
		std::ostream& csvWrite(std::ostream& ostr)const; // Inserts comma-separated ticket number and time into ostream
		std::istream& csvRead(std::istream& istr);       // Extracts the ticket number and time in a comma-separated format from istream
		std::ostream& write(std::ostream& ostr )const;   // Inserts a ticket into the ostream to be displayed on the console
		std::istream& read(std::istream& istr);          // Extracts the ticket information from istream. This function works the same as csvRead
	};
}
#endif // !SDDS_TICKET_H_
