//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 1 - Lab
//==============================================

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

	// Prototypes:

	// flushkeys:
	void flushkeys();
	
	// ValidYesResponse:
	bool ValidYesResponse(char ch);
	
	// yes:
	bool yes();
	
	// readCstr:
	void readCstr(char cstr[], int len);

	// readInt:
	int readInt(int min, int max);
}

#endif