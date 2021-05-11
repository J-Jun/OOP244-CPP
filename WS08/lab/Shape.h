//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 8 - LAB
//==============================================

#ifndef SDDS_SHAPE_H__
#define SDDS_SHAPE_H__

#include <iostream>

namespace sdds {

	class Shape {
	public:

		// =========== Pure Virtual Function ===========
		virtual void draw(std::ostream& ostr)const = 0;
		virtual void getSpecs(std::istream& istr) = 0;

		// ================= Destructor ================
		virtual ~Shape() {};
	};

	// =============== Helper Functions ================
 
	// Overloading the insertion operator
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
	// Overloading the extraction operator
	std::istream& operator>>(std::istream& istr, Shape& shape);
}
#endif // !SDDS_SHAPE_H__