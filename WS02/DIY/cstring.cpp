//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 2 - DIY
//==============================================

#include <iostream>

#include "cstring.h"

using namespace std;

namespace sdds {

	// Functions:

	// strCpy:
	void strCpy(char* des, const char* src) {

		// Variable:
		int i;

		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	// strnCpy:
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

	// strnCmp:
	int strnCmp(const char* s1, const char* s2, int len) {

		// Variables:
		int comparison = 0, i = 0;

		// Checking if every index of the s1 and s2 are equal within a range 
		while (i < len) {
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

	// strStr:
	const char* strStr(const char* str1, const char* str2) {

		// Variables:
		int i = 0, match = 1, matchFlag = 0;
		int indexStart, charCompare;

		const char* matchedIndex = nullptr;

		// Checking if str2 is bigger than str1 
		charCompare = strLen(str1) > strLen(str2);

		while (charCompare) {

			// Going through the loop until the index of str1 reaches a certain point
			for (i = 0;  i < (strLen(str1) -  strLen(str2) + 1) && matchFlag == 0; i++) {

				// Checking if the index of the str1 is equal to the first index of str2
				if (str1[i] == str2[0]) {

					// Comparing the the address of str1 at the index and the str2
					match = strnCmp(&str1[i], str2, strLen(str2));

					indexStart = i;
					matchFlag = 1;
				}
			}

			// If the comparison is true
			if (match == 0) {
				charCompare = 0;
				matchedIndex = &str1[indexStart];
			}
			else
				charCompare = 0;
		}

		return matchedIndex;
	}

	// strCat:
	void strCat(char* des, const char* src) {

		// Variables:
		int desLength;
		int i = 0;

		desLength = strLen(des);

		// Adding the value at the index of src to the end of the des
		while (des[i] != '\0') {
			des[desLength + i] = src[i];
			i++;
		}
		des[desLength + i] = '\0';
	}
}