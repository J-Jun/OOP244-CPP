/*
    Final Project Milestone 3
    Module:         IOAble interface
    Filename:		IOAble.cpp
    Author:         Jason Jun
    Student Number: 126 683 200
    Email:          jjun10@myseneca.ca
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "IOAble.h"

using namespace std;
namespace sdds {
    
    std::ostream& operator<<(std::ostream& ostr, const IOAble& IA) {

        //IA.write(ostr);
        return IA.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& IA) {
        
        //IA.read(istr);
        return IA.read(istr);
    }
}