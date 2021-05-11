/* 
	Final Project Milestone 1
	Module:         Time
	Filename:       Time.cpp
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
	-----------------------------------------------------------
	I have done all the coding by myself and only copied the code
	that my professor provided to complete my workshops and assignments.
	-----------------------------------------------------------
*/

#include "Time.h"
#include "utils.h"

using namespace std;

namespace sdds {

	Time& Time::setToNow() {

		// Set to a current time
		m_min = getTime();

		return *this;
	}

	Time::Time(unsigned int min) {

		// Setting the number of minutes
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {

		// Hours:
		ostr.width(2);
		ostr.fill('0');
		ostr << (m_min / 60);

		// Column:
		ostr << ":";

		// Minutes:
		ostr.width(2);
		ostr.fill('0');
		ostr << (m_min % 60);

		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {

		// Variables:
		int hourValue = 0;
		char columnChar;
		int minuteValue = 0;

		// Taking in the hour value
		istr >> hourValue;

		// Checking if the inputted value is a correct type
		if (istr) {
			if (hourValue < 0)
				istr.setstate(ios::failbit);
			else {
				// Taking in the column value
				istr >> columnChar;
				if (columnChar != ':')
					istr.setstate(ios::failbit);
				else {
					// Taking ing the minute value
					istr >> minuteValue;
					if (minuteValue < 0)
						istr.setstate(ios::failbit);
				}

				// When all the inputted values didn't fail
				if (!cin.fail())
					m_min = (hourValue * 60) + minuteValue;
			}
		}
		else {
			istr.setstate(ios::failbit);
		}
		return istr;
	}

	Time& Time::operator-=(const Time& D) {

		if (D.m_min < m_min)
			m_min -= D.m_min;
		else {
			m_min = (m_min + (((D.m_min / 1440) + 1) * 1440))- D.m_min;
		}

		return *this;
	}

	Time Time::operator-(const Time& D)const {
		
		Time timeResult;

		if (D.m_min < m_min)
			timeResult.m_min =  m_min - D.m_min;
		else {
			timeResult.m_min = (m_min + (((D.m_min / 1440) + 1) * 1440)) - D.m_min;
		}
		return timeResult;
	}

	Time& Time::operator+=(const Time& D) {

		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const {

		Time timeResult;

		timeResult.m_min  = m_min + D.m_min;
		return timeResult;
	}

	Time& Time::operator=(unsigned int val) {

		m_min = val;
		return *this;
	}

	Time& Time::operator *= (unsigned int val) {

		m_min *= val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const {

		Time timeResult;

		timeResult.m_min = m_min * val;
		return timeResult;
	}

	Time& Time::operator /= (unsigned int val) {

		m_min /= val;
		return *this;
	}

	Time Time::operator /(unsigned int val)const {

		Time timeResult;

		timeResult.m_min = m_min / val;
		return timeResult;
	}

	Time::operator int()const {

		return int(m_min);
	}

	Time::operator unsigned int()const {

		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D) {

		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& D) {

		return D.read(istr);
	}
}