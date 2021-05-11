//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - DIY
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "cstring.h"
#include "Food.h"

using namespace std;
namespace sdds {

	void Food::setName(const char* name) {

		strnCpy(f_foodName, name, 30);
	}

	bool Food::isValid()const {

		// Variable:
		bool valid = true;

		if (f_foodName[0] == '\0' || f_timeConsumption == 0) {
			valid = false;
		}

		return valid;
	}

	void Food::setEmpty() {

		f_foodName[0] = '\0';
		f_calorieNumber = 0;
	}

	void Food::set(const char* item_name, int calories, int when) {

		if (item_name == nullptr || calories < 0) {
			setEmpty();
		}
		else {
			setName(item_name);
			f_calorieNumber = calories;
			f_timeConsumption = when;
		}
	}

	int Food::calorieNumber()const {

		return f_calorieNumber;
	}

	// Returns the time consumed attribute
	int Food::timeConsumption()const {

		return f_timeConsumption;
	}

	void Food::display()const {

		// if the Food items are valid
		if (isValid()) {

			// Displaying the food name
			cout << "| ";

			cout.width(30);
			cout.fill('.');
			cout << left << f_foodName;

			cout << " | ";

			// Displaying the calories
			cout.fill(' ');
			cout.width(4);
			cout.precision(2);
			cout << right << fixed << f_calorieNumber;
			cout.fill(' ');

			cout << " | ";

			// Displaying the meal type
			cout.fill(' ');
			if (f_timeConsumption == 1)
				cout << "Breakfast  |" << endl;
			else if (f_timeConsumption == 2)
				cout << "Lunch      |" << endl;
			else if (f_timeConsumption == 3)
				cout << "Dinner     |" << endl;
			else if (f_timeConsumption == 4)
				cout << "Snack      |" << endl;
		}
		else
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
	}
}