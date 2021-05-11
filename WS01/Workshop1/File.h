//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 1 - Lab
//==============================================

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds {

	// Prototypes:

	// openFileForRead
	bool openFileForRead();

	// openFileForOverwrite
	bool openFileForOverwrite();

	// closeFile
	void closeFile();

	// freadShoppingRec
	bool freadShoppingRec(ShoppingRec* rec);

	// fwroteShoppintec
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif
