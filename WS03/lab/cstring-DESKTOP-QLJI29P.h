//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - LAB
//==============================================

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_

namespace sdds {

	// Returns the length of the C-string in characters
	int strLen(const char* s);

	// Copies the source character string into the destination
	void strnCpy(char* des, const char* src, int len);
}
#endif // !SDDS_CSTRING_H_



