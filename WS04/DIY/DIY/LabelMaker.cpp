//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - DIY
//==============================================

#include <iostream>

#include "LabelMaker.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {

		if (noOfLabels > 0) {
			lm_noOfLabels = noOfLabels;
			lm_Label = new Label[lm_noOfLabels];
		}
	}

	void LabelMaker::readLabels() {

		cout << "Enter " << lm_noOfLabels << " labels:" << endl;

		for (int i = 0; i < lm_noOfLabels; i++) {
			cout << "Enter label number " << (i + 1) << endl;
			cout << "> ";
			lm_Label[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {

		for (int i = 0; i < lm_noOfLabels; i++) {
			lm_Label[i].printLabel();
			cout << endl;
		}

		delete[] lm_Label;
		lm_Label = nullptr;
		lm_noOfLabels = 0;
	}

	LabelMaker::~LabelMaker() {

		delete[] lm_Label;
		lm_Label = nullptr;
		lm_noOfLabels = 0;
	}
}