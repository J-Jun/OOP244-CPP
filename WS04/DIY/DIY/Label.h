//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - DIY
//==============================================

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

#include <iostream>

namespace sdds {

	class Label {

	// Private member variables:
		char l_frame[9];
		char* l_labelMessage;

	// Private member functions:
		void setToDefault();

	public:
		// Creates an empty label 
		Label();

		// Creates an empty label and sets the frame to the "frameArg" argument
		Label(const char* frameArg);

		// Creates a Lable with the "frame" set to "frameArg" and the content of the Label set to the corresponding argument
		Label(const char* frameArg, const char* content);

		// Making sure that there is no memory leak
		~Label();

		// Reads the label from the console (up to 70 characters) and stores it in the Label
		void readLabel();

		// Prints the label by drawing the frame around the content
		std::ostream& printLabel()const;
	};
}
#endif // !SDDS_LABLE_H_