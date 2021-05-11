//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 8 - LAB
//==============================================

#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__

#include <iostream>

#include "Shape.h"

namespace sdds {

	class LblShape : public Shape {

		// Character pointer 
		char* m_label = nullptr;

	protected:

		// Returns the unmodifiable value of "m_label" member variable
		const char* label()const;

	public:

		// ======================== Constructor =======================
		LblShape(); // Sets the label pointer to null
		LblShape(const char* n_string); // Copies the argument to the newly allocated memory

		// ======================== Destructor ========================
		~LblShape();

		// ================ Copy Constructor (Deleted) ================
		LblShape(const LblShape& src) = delete;

		// ============= Assignment Operator (Deleted) ================
		LblShape& operator= (const LblShape& src) = delete;

		// =================== Overriding Function ====================
		void getSpecs(std::istream& istr);
	};
}
#endif // !SDDS_LBLSHAPE_H__