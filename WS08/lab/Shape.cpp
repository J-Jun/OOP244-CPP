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

#include "Shape.h"

using namespace std;
namespace sdds {

    std::ostream& operator<<(std::ostream& ostr, const Shape& shape) {

        shape.draw(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Shape& shape) {

        shape.getSpecs(istr);
        return istr;
    }
}