/*
	Final Project Milestone 5
	Module:         Menu
	Filename:       Menu.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
*/

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>

namespace sdds {

	class Menu {

		char* m_text{ nullptr }; // holds the menu content dynamically
		int m_noOfSel;  // holds the number of options displayed in menu content

		// Displays the Menu content
		void display()const;
	public:

		// Dynamically allocates memory to hold the content pointed by m_text and keeps the number of Selections in m_noOfSel
		Menu(const char* MenuContent, int NoOfSelections);

		// Deallocates the dynamically allocated memory
		virtual ~Menu();

		int& operator>>(int& Selection);

		// Copy logic
		Menu(const Menu& src);
		// Making sure to not to assign to another Menu object
		Menu& operator=(const Menu&) = delete;
	};
}
#endif // !SDDS_MENU_H_