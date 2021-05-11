//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - DIY
//==============================================

#ifndef SDDS_MAKER_H_
#define SDDS_MAKER_H_

#include "Label.h"

namespace sdds {

	class LabelMaker {

		// Private variables:
		Label* lm_Label;
		int lm_noOfLabels = 0;
		
	public:

		// Creates a dynamic array of Lables to the size of the argument
		LabelMaker(int noOfLabels);

		// Gets the contents of the Labels
		void readLabels();

		// Prints the Labels
		void printLabels();

		// Deallocates the memory
		~LabelMaker();

	};
}
#endif // !SDDS_MAKER_H_