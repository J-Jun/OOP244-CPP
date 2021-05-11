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

#include "LblShape.h"

using namespace std;
namespace sdds {

	const char* LblShape::label()const {

		return m_label;
	}

	// ======================== Constructor =======================
	LblShape::LblShape() {

		if (m_label != nullptr) {
			m_label = nullptr;
		}
	}

	LblShape::LblShape(const char* n_string) {

		m_label = new char[strlen(n_string) + 1];
		strcpy(m_label, n_string);
	}

	// ======================== Destructor ========================
	LblShape::~LblShape() {

		delete[] m_label;
		m_label = nullptr;
	}

	// =================== Overriding Function ====================
	void LblShape::getSpecs(std::istream& istr) {

		char c_label[100];
		istr.get(c_label, 100, ',');

		delete[] m_label;
		m_label = nullptr;

		m_label = new char[strlen(c_label) + 1];
		strcpy(m_label, c_label);
		istr.ignore(99, ',');
	}
}