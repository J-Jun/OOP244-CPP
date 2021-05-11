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

#include "Line.h"

using namespace std;
namespace sdds {

	// ====================== Constructor ======================
	Line::Line() : LblShape() {

		m_length = 0;
	}

	Line::Line(const char* l_cstring, int l_length) : LblShape(l_cstring) {

		m_length = l_length;
	}

	// ================== Overriding Functions ==================	
	void Line::getSpecs(std::istream& istr) {

		LblShape::getSpecs(istr);
		
		istr >> m_length;
		istr.ignore();
	}
	
	void Line::draw(std::ostream& ostr)const {

		if (m_length > 0 && label() != nullptr) {

			ostr << label() << endl;
			for (int i = 0; i < m_length; i++)
				ostr << '=';
		}
	}
}