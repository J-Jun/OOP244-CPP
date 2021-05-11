//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 1 - Lab
//==============================================

#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds {

	// Prototypes:

	// loadList:
	bool loadList();
	
	// displayList
	void displayList();
	
	// removeBoughtItems
	void removeBoughtItems();
	
	// removeItem
	void removeItem(int index);
	
	// saveList
	bool saveList();
	
	// clearList
	void clearList();
	
	// toggleBought
	void toggleBought();
	
	// addItemToList
	void addItemToList();
	
	// removeItemfromList
	void removeItemfromList();
	
	// listIsEmpty
	bool listIsEmpty();
}

#endif