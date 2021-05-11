//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 7 - LAB
//==============================================

#include "cstring.h"
namespace sdds {

	void strCpy(char* des, const char* src) {

		// Variable:
		int i;

		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

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

