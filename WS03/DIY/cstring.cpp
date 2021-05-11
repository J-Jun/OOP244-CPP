//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - DIY
//==============================================

#include "cstring.h"

namespace sdds {

	int strLen(const char* s) {

		// Variable:
		int wordLength = 0;

		// Looping and counting for number of characters
		for (int i = 0; s[i] != '\0'; i++) {
			wordLength++;
		}
		return wordLength;
	}

	void strnCpy(char* des, const char* src, int len) {

		// Variable:
		int i = 0;

		// Looping through and copying each index of src to the index of des
		if (strLen(src) < len) {
			for (i = 0; i < strLen(src); i++) {
				des[i] = src[i];
			}
		}
		else {
			for (i = 0; i < len; i++) {
				des[i] = src[i];
			}
		}
		des[i] = '\0';
	}
}