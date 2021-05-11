/*
    Final Project Milestone 2
    Module:         Menu
    Filename:       Menu.cpp
    Author:         Jason Jun
    Student Number: 126 683 200
    Email:          jjun10@myseneca.ca
    -----------------------------------------------------------
    Date         Reason
    2020/03/19   Started to work on the Milestone 2
    2020/03/19   Debugged and submitted the Milestone 2
    -----------------------------------------------------------
    I have done all the coding by myself and only copied the code
    that my professor provided to complete my workshops and assignments.
    -----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Menu.h"
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds {

    void Menu::display()const {

        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }

	Menu::Menu(const char* MenuContent, int NoOfSelections) {

		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);

		m_noOfSel = NoOfSelections;
	}

    Menu::Menu(const Menu& src) {

        m_noOfSel = src.m_noOfSel;

        if (src.m_text != nullptr) {
            m_text = new char[strlen(src.m_text) + 1];
            strcpy(m_text, src.m_text);
        }
        else {
            m_text = nullptr;
        }
    }

	Menu::~Menu() {

		delete[] m_text;
		m_text = nullptr;

		m_noOfSel = 0;
	}

    int& Menu::operator>>(int& Selection) {

        display();
        Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
        return Selection;
    }
} 