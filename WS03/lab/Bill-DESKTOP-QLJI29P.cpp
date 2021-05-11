//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - LAB
//==============================================

#include <iostream>

#include "cstring.h"
#include "Bill.h"

using namespace std;
namespace sdds {

	void Bill::setEmpty() {

		// Setting m_title to an empty cstring
		m_title[0] = '\0';

		// Setting m_items to nullptr
		m_items = nullptr;
	}

	bool Bill::isValid()const {

		// Variable:
		bool valid = false;

		if (m_title[0] != '\0' && m_items != NULL) {
			for (int i = 0; i < m_noOfItems; i++) {
				if (m_items[i].isValid()) {
					valid = true;
				}
				else
					valid = false;
			}
		}

		return valid;
	}

	double Bill::totalTax()const {

		// Variable:
		double totalTax = 0.0;

		// Adding all the taxes of the items
		for (int i = 0; i < m_noOfItems; i++) {
			totalTax += m_items[i].tax();
		}

		return totalTax;
	}

	double Bill::totalPrice()const {

		// Variable:
		double t_Price = 0.0;

		// Adding all the prices of the items
		for (int i = 0; i < m_noOfItems; i++) {
			t_Price += m_items[i].price();
		}

		return t_Price;
	}

	void Bill::Title()const {

		cout << "+--------------------------------------+" << endl;

		// If the Bill is valid
		if (isValid()) {

			// Displaying title
			cout << "| ";
			cout.width(36);
			cout << left << m_title;
			cout << " |" << endl;
		}
		// If the Bill is invalid
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		// Displaying in both cases (valid or invalid)
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {

		cout << "+----------------------+---------+-----+" << endl;

		// If the Bill is valid
		if (isValid()) {

			// Display total tax
			cout << "|                Total Tax: ";

			cout.width(10);
			cout.precision(2);
			cout << right << fixed << totalTax();

			cout << " |" << endl;

			// Display total price
			cout << "|              Total Price: ";

			cout.width(10);
			cout.precision(2);
			cout << right << fixed << totalPrice();

			cout << " |" << endl;

			// Display total after tax
			cout << "|          Total After Tax: ";

			cout.width(10);
			cout.precision(2);
			cout << right << fixed << (totalTax() + totalPrice());

			cout << " |" << endl;
		}
		// If the Bill is invalid
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		// Displaying in both cases (valid or invalid)
		cout << "+--------------------------------------+" << endl;
	}
	
	void Bill::init(const char* title, int noOfItems) {

		if (title == nullptr || noOfItems <= 0) {
			// Bill set to an empty state
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];

			// All the dynamically allocated Items are set to empty
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {

		// Variable:
		bool success = false;

		// Checking for condition --> if number of added Items is less than the length of the m_items array
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			success = true;
		}
		return success;
	}

	void Bill::display()const {

		// Displays title
		Title();

		// Displays m_items elements
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}

		// Display footer
		footer();
	}

	void Bill::deallocate() {

		delete[] m_items;
		m_items = nullptr;
	}
}