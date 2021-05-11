//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 5 - DIY
//==============================================

#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {

	void Mark::setEmpty() {
		m_value = 0;
	}

	Mark::Mark() {

		setEmpty();
	}

	Mark::Mark(const int mark) {

		if (mark >= 0 && mark <= 100)
			m_value = mark;
		else
			m_value = -1;
	}

	Mark::operator int()const {

		int markValue = 0;

		if (m_value >= 0 && m_value <= 100)
			markValue = m_value;

		return markValue;
	}

	Mark::operator double()const {

		double finalGrade = 0.0;

		if (m_value >= 50 && m_value < 60)
			finalGrade = 1.0;

		else if (m_value >= 60 && m_value < 70)
			finalGrade = 2.0;

		else if (m_value >= 70 && m_value < 80)
			finalGrade = 3.0;

		else if (m_value >= 80 && m_value <= 100)
			finalGrade = 4.0;

		return finalGrade;
	}

	Mark::operator char()const {

		char finalGrade = 'X';

		if (m_value >= 0 && m_value < 50)
			finalGrade = 'F';

		else if (m_value >= 50 && m_value < 60)
			finalGrade = 'D';

		else if (m_value >= 60 && m_value < 70)
			finalGrade = 'C';

		else if (m_value >= 70 && m_value < 80)
			finalGrade = 'B';

		else if (m_value >= 80 && m_value <= 100)
			finalGrade = 'A';

		return finalGrade;
	}

	Mark& Mark::operator+= (int newMark) {


		if (m_value >= 0 && m_value <= 100)
			m_value += newMark;
		else
			setEmpty();
		
		return *this;
	}

	Mark& Mark::operator= (int newMark) {

		m_value = newMark;
			
		return *this;
	}

	int operator+= (int& newMark, const Mark& finalMark) {

		if (finalMark.m_value >= 0 && finalMark.m_value <= 100)
			newMark += finalMark.m_value;

		return newMark;
	}
}