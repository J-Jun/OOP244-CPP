//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - LAB
//==============================================

#include <iostream>

#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds {

	void Item::setName(const char* name) {

		// Variable:
		int i = 0;

		for (i = 0; i < 20; i++) {
			m_itemName[i] = name[i];
		}

		m_itemName[i] = '\0';
	}

	void Item::setEmpty() {

		// Setting the price to 0
		m_price = 0.0;

		// Setting the itemName to a blank string
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed) {

		if (price < 0 or name == nullptr) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}


	}

	double Item::price()const {

		return m_price;
	}

	double Item::tax()const {

		// Variable:
		double finalTax = 0.0;

		if (m_taxed) {
			finalTax = m_price * 0.13;
		}

		return finalTax;
	}

	bool Item::isValid()const {

		// Variable:
		bool valid = false;

		if (m_price > 0 && m_itemName != nullptr) {
			valid = true;
		}

		return valid;
	}

	void Item::display()const {

		// If the Item is valid
		if (isValid()) {

			// Displaying m_itemName
			cout << "| ";

			cout.width(20);
			cout.fill('.');
			cout << left << m_itemName;

			cout << " | ";

			// Displaying m_price
			cout.fill(' ');
			cout.width(7);
			cout.precision(2);
			cout << right << fixed << m_price;
			cout.fill(' ');

			cout << " | ";

			// Displaying m_taxed
			cout.fill(' ');
			if (m_taxed)
				cout << "Yes";
			else
				cout << "No ";

			cout << " |" << endl;
		}
		// If the Item is invalid
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}