//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - DIY
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "cstring.h"
#include "Label.h"

using namespace std;
namespace sdds {

	void Label::setToDefault() {

		l_labelMessage = nullptr;
		strCpy(l_frame, "+-+|+-+|");
	}

	Label::Label() {

		setToDefault();
	}

	Label::Label(const char* frameArg) {

		l_labelMessage = nullptr;
		strCpy(l_frame, frameArg);
	}

	Label::Label(const char* frameArg, const char* content) {

		l_labelMessage = new char[71];

		strCpy(l_frame, frameArg);
		strCpy(l_labelMessage, content);
	}

	Label::~Label() {
		
		delete[] l_labelMessage;
		l_labelMessage = nullptr;

		l_frame[0] = '\0';
	}

	void Label::readLabel() {

		char* consoleLabel = new char[71];

		cin.getline(consoleLabel, 71);
		l_labelMessage = new char[strLen(consoleLabel) + 1];
		strCpy(l_labelMessage,consoleLabel);

		delete[] consoleLabel;
		consoleLabel = nullptr;
	}

	std::ostream& Label::printLabel()const {
	
		if (l_frame && l_labelMessage) {

			int messageLength = strLen(l_labelMessage) + 3;
			
			// Outputting the first line of the frame
			cout << l_frame[0];

			cout.width(messageLength);
			cout.fill(l_frame[1]);

			cout << right << l_frame[2] << endl;

			for (int i = 0; i < 3; i++) {
				cout << l_frame[7];

				// Outputting the label message
				if (i == 1) {
					cout << " " << l_labelMessage << " ";
				}
				else {
					cout.width(messageLength);
					cout.fill(' ');
				}

				cout << right << l_frame[3] << endl;
			}

			// Outputting the last line of the frame
			cout << l_frame[6];

			cout.width(messageLength);
			cout.fill(l_frame[5]);

			cout << right << l_frame[4];
		}
		return cout;
	}
}