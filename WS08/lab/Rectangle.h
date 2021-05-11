//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 8 - LAB
//==============================================

#ifndef SDDS_RECTANGLE_H__
#define SDDS_RECTANGLE_H__

#include <iostream>

#include "LblShape.h"

namespace sdds {

	class Rectangle : public LblShape {

		// Width of a rectangular frame
		int m_width;

		// Height of a rectangular frame
		int m_height;

	public:

		// ========================== Constructor ===========================
		Rectangle();
		Rectangle(const char* R_cstring, int R_width, int R_height);

		// ====================== Overriding Functions ======================
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_RECTANGLE_H__