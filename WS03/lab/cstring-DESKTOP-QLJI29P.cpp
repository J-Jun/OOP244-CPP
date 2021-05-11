//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - LAB
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
		for (i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
		}

		if (strLen(src) < len)
			des[i] = '\0';
	}
}