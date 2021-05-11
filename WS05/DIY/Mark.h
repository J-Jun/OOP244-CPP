//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 5 - DIY
//==============================================

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {

	class Mark {

		int m_value;
		void setEmpty();

	public:

		// Set to default value
		Mark();

		// Create Mark using integer value
		Mark(const int mark);

		// Return the value of the mark
		operator int()const;

		// Convert to the equivalent GPA grade value
		operator double()const;

		// Convert to the equivalent GPA grade letter
		operator char()const;

		// Add to the value of the mark
		Mark& operator+= (int newMark);

		// Set the value to the mark
		Mark& operator= (int newMark);

		// Returns total integer after adding Mark with the integers
		friend int operator+= (int& newMark, const Mark& finalMark);
	};
}
#endif 
