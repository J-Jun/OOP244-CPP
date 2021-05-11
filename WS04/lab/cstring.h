//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - LAB
//==============================================

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_

namespace sdds {
  
	// Copies the source character string into the destination
	void strCpy(char* des, const char* src);

	// Compares two C-strings 
	// returns 0 i they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2);

	// returns the lenght of the C-string in characters
	int strLen(const char* s);
}
#endif // !SDDS_CSTRING_H_



