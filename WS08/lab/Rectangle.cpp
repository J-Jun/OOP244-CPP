//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 8 - LAB
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Rectangle.h"

using namespace std;
namespace sdds {


	// ========================== Constructor ===========================
	Rectangle::Rectangle() : LblShape() {

		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* R_cstring, int R_width, int R_height) : LblShape(R_cstring) {

		int labelLength = strlen(label());
		m_width = R_width;
		m_height = R_height;

		if (m_height < 3 || m_width < (labelLength + 2)) {

			m_width = 0;
			m_height = 0;
		}
	}

	// ====================== Overriding Functions ======================
	void Rectangle::getSpecs(std::istream& istr) {
		
		LblShape::getSpecs(istr);

		istr >> m_width;
		istr.ignore(100, ',');

		istr >> m_height;
		istr.ignore(100, '\n');
	}

	void Rectangle::draw(std::ostream& ostr)const {

		if (m_width > 0 && m_height > 0) {

			ostr << "+" << setw(streamsize(m_width) - 1) << setfill('-') << "+" << endl;
			ostr << "|" << setw(streamsize(m_width) - 2) << left << setfill(' ') << label() << "|" << endl;

			for (int i = 0; i < (m_height - 3); i++)
				ostr << "|" << setw(streamsize(m_width) - 1) << setfill(' ') << right << "|" << endl;

			ostr << "+" << setw(streamsize(m_width) - 1) << setfill('-') << "+";
		}
	}
}