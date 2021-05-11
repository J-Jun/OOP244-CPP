//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - LAB
//==============================================

#include "cstring.h"

namespace sdds {

	// strCpy:
	void strCpy(char* des, const char* src) {

		// Variable:
		int i;

		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	// strCmp:
	int strCmp(const char* s1, const char* s2) {

		// Variables:
		int comparison = 0, i = 0;

		// Checking if every index of the s1 and s2 are equal
		while (i < strLen(s1)) {
			if (s1[i] > s2[i])
				comparison = 1;
			else if (s1[i] < s2[i])
				comparison = -1;
			else
				comparison = 0;

			i++;
		}

		return comparison;
	}

	// strLen:
	int strLen(const char* s) {

		// Variable:
		int wordLength = 0;

		// Looping and counting for number of characters
		for (int i = 0; s[i] != '\0'; i++) {
			wordLength++;
		}

		return wordLength;
	}
}