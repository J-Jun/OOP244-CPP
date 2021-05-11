/*
	Final Project Milestone 4
	Module:         IOAble interface
	Filename:		IOAble.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
*/

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_

#include <iostream>

namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream& ostr)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() {};
	};

	// Overloading the insertion operator
	std::ostream& operator<<(std::ostream& ostr, const IOAble& IA);
	// Overloading the extraction operator
	std::istream& operator>>(std::istream& istr, IOAble& IA);
}
#endif // !SDDS_IOABLE_H_