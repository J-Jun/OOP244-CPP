//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 6 - DIY
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

#include "Stats.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	void Stats::setFilename(const char* fname) {

		// Dynamically allocating memory in s_fileName
		delete[] s_fileName;
		s_fileName = nullptr;

		s_fileName = new char[strLen(fname) + 1];

		// Copying the fname into the s_fileName
		strCpy(s_fileName, fname);
	}





	// ================= Construction ====================

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {

		s_columnWidth = columnWidth;
		s_noOfColumns = noOfColumns;
		s_precision = precision;
	}

	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {

		s_columnWidth = columnWidth;
		s_noOfColumns = noOfColumns;
		s_precision = precision;

		if (filename != nullptr && filename[0] != '\0') {
			setFilename(filename);
			setNoOfOccurence();
			loadStats();
		}
	}





	// ================= Helper Implementations ====================
	std::ostream& operator<<(std::ostream& ostr, const Stats& stats) {

		stats.view(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Stats& stats) {

		stats.getFile(istr);
		return istr;
	}
}