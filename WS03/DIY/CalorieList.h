//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - DIY
//==============================================

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_

#include "Food.h"

namespace sdds {

	class CalorieList {

		// Private Variables:
		
		// Title of the list
		char c_title[37];

		// Pointer to the dynamically allocated array of Food items
		Food* f_items;

		// Size of the dynamically allocated array of Food items
		int c_noOfItems;

		// Size of the max number of Food items
		int c_maxItems;

		// Number of the Food items added by the add method
		int c_itemsAdded;


		// Private Functions:

		// Returns the total calories of the Food items
		int totalCalorie()const;

		// Displays the title of the list
		void title()const;

		// Displays a footer containing the total calories
		void footer()const;

		// Sets the CalorieList to an empty state
		void setEmpty();

		// Returns true if the CalorieList and all of its Food items are valid
		bool isValid()const;

	public:

		// sets the CalorieList to accept the "size" number of Food Items. 
		// This function is called to prepare the CalorieList for accepting food items
		void init(int size);

		// Adds Food Items using their Name, Calorie count and time of consumption up to the number set in the init() function, returns true if successful.
		bool add(const char* item_name, int calories, int when);

		// Displays the report with food information and the total calorie consumed in the day as shown in the report sample
		void display()const;

		// Releases all the memory used. After this function init() can be called for another report;
		void deallocate();
	};
}

#endif 

