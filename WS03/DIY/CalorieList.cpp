//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - DIY
//==============================================

#include <iostream>

#include "cstring.h"
#include "CalorieList.h"

using namespace std;
namespace sdds {

	int CalorieList::totalCalorie()const {

		// Variable:
		int t_calorie = 0;

		// Adding all the calories of the Food items
		for (int i = 0; i < c_noOfItems; i++) {
			t_calorie += f_items[i].calorieNumber();
		}

		return t_calorie;
	}

	void CalorieList::setEmpty() {

		// Setting title to an empty string
		c_title[0] = '\0';

		// Setting the f_items to a null pointer
		f_items = nullptr;
	}

	bool CalorieList::isValid()const {

		// Variable:
		bool valid = false;
		bool flag = true;

		for (int i = 0; i < c_noOfItems && flag; i++) {
			if (f_items[i].isValid()) {
				valid = true;
			}
			else {
				valid = false;
				flag = false;
			}
		}

		return valid;
	}

	void CalorieList::init(int size) {

		c_noOfItems = size;
		c_itemsAdded = 0;

		f_items = new Food[c_noOfItems]();
	}

	bool CalorieList::add(const char* item_name, int calories, int when) {

		// Variable:
		bool success = false;

		if (c_itemsAdded < c_noOfItems) {
			f_items[c_itemsAdded].set(item_name, calories, when);
			c_itemsAdded++;
			success = true;
		}

		return success;
	}

	void CalorieList::title()const {

		cout << "+----------------------------------------------------+" << endl;

		// If the CalorieList is valid
		if (isValid()) {

			// Displaying title
			cout << "| ";
			cout.width(50);
			cout << left << " Daily Calorie Consumption";
			cout << " |" << endl;
		}
		// If the CalorieList is invalid
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}

		// Displaying in both cases (valid or invalid)
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const {

		cout << "+--------------------------------+------+------------+" << endl;

		// If the CalorieList is valid
		if (isValid()) {

			// Display the total calorie
			cout << "|    Total Calories for today:";

			cout.width(9);
			cout << right << totalCalorie() << " |            |" << endl;

		}
		// If the CalorieList is invalid
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}

		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::display()const {

		// Display title
		title();

		// Display Food items
		for (int i = 0; i < c_noOfItems; i++) {
			f_items[i].display();
		}

		// Display footer
		footer();
	}

	void CalorieList::deallocate() {

		delete[] f_items;
		f_items = nullptr;

		c_noOfItems = 0;
	}

}