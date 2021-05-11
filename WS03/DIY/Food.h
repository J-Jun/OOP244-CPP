//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - DIY
//==============================================

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_

namespace sdds {

	class Food {

		// Private Variables:
		char f_foodName[31]; // Holds the food name up to 30 characters
		int f_calorieNumber;
		int f_timeConsumption; 

		// Private Member Function:
		void setName(const char* name);

	public:

		// Returns true if the Food item is not set to the empty state
		bool isValid()const;

		// Set the Item to a recognizable safe Empty State
		void setEmpty();

		// Sets the Food item attributes
		void set(const char* item_name, int calories, int when);

		// Returns the calorie number attribute
		int calorieNumber()const;

		// Returns the time consumed attribute
		int timeConsumption()const;

		// Displaying Food items
		void display()const;
	};
}
#endif 