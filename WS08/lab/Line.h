//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 8 - LAB
//==============================================

#ifndef SDDS_LINE_H__
#define SDDS_LINE_H__

#include <iostream>

#include "LblShape.h"

namespace sdds {

	class Line : public LblShape {

		// Length of the "Line" in characters
		int m_length;

	public:

		// ====================== Constructor ======================
		Line(); // Invokes the default constructor of the base class
		Line(const char* l_cstring, int l_length);

		// ================== Overriding Functions ==================
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_LINE_H__