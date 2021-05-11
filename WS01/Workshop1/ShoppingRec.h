//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 1 - Lab
//==============================================

#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H

namespace sdds {

	// Constant Value:
	const int MAX_TITLE_LENGTH = 50;

	// Struct:
	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	// Prototypes:

	// getShoppingRec:
	ShoppingRec getShoppingRec();

	// displayShoppingRec:
	void displayShoppingRec(const ShoppingRec* shp);

	// toggleBoughtFlag:
	void toggleBoughtFlag(ShoppingRec* rec);

	// isShoppingRecEmpty:
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif