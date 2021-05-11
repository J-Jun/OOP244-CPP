//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - LAB
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <istream>
#include <iomanip>

#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"

using namespace std;
namespace sdds {

	// Global Variable:
	const double PI = 3.14159265;

	void Canister::setToDefault() {

		// set the content name pointer to null
		m_contentName = nullptr;

		// set the height to 13.0
		m_height = 13.0;

		// set the diameter to 10.0
		m_diameter = 10.0;

		// set the content volume to 0.0
		m_contentVolume = 0.0;

		// usable flag to true
		m_usable = true;
	}

	void Canister::setName(const char* Cstr) {

		// checking if Cstr is not null and the Canister is usable
		if (Cstr && m_usable) {
			// delete the current content name
			delete[] m_contentName;
			m_contentName = nullptr;
			// allocate memory to the length of Cstr
			m_contentName = new char[strLen(Cstr) + 1];
			// copies the Cstr into the newly allocated memory
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty()const {
		
		// returns true if content volume is less thatn 0.00001 CCs
		return (m_contentVolume < 0.00001);
	}

	bool Canister::hasSameContent(const Canister& C)const {

		// Variable:
		bool equal = false;

		// compare the content of the Canister with the received argument C
		if (strCmp(m_contentName, C.m_contentName) == 0 && m_contentName && C.m_contentName)
			equal = true;

		return equal;
	}

	Canister::Canister() {

		// sets the attribute to their default values
		setToDefault();
	}

	Canister::Canister(const char* contentName) {

		// sets the attributes to their default values
		setToDefault();
		// sets the Name to the given contentName argument
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName) {

		// sets the attributes to their default values
		setToDefault();

		// condition --> the dimensions are within acceptable values
		if (height < 10 || height > 40 || diameter < 10 || diameter > 30) {

			m_usable = false;
		}
		else {
			
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0;
			setName(contentName);
		}
	}

	Canister::~Canister() {

		delete[] m_contentName;
		m_contentName = nullptr;
	}

	void Canister::clear() {

		// deallocating the memory pointed by the content name attribute
		delete[] m_contentName;
		m_contentName = nullptr;

		// sets the content volume to 0.0
		m_contentVolume = 0.0;

		// set the usable flag attribute to true
		m_usable = true;
	}

	double Canister::capacity()const {

		// return the capacity
		return (PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2));
	}

	double Canister::volume()const {

		// return the volume attribute
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {

		if (contentName == nullptr)
			m_usable = false;
		else if (isEmpty()) {
			setName(contentName);
		}
		else if (!hasSameContent(contentName))
			m_usable = false;

		return *this;
	}

	Canister& Canister::pour(double quantity) {

		if (m_usable && quantity > 0.0 && (quantity + volume()) <= capacity())
			m_contentVolume += quantity;
		else
			m_usable = false;

		return *this;
	}

	Canister& Canister::pour(Canister& C) {

		setContent(C.m_contentName);

		if (C.volume() > (capacity() - volume())) {

			C.m_contentVolume -=  (capacity() - volume());
			m_contentVolume = capacity();
		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}

		return *this;
	}

	std::ostream& Canister::display()const {

		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";

		if (!m_usable)
			cout << " of Unusable content, discard!" ;
		
		if (m_contentName != nullptr && m_usable)
			cout << " of " << setw(7) << right << volume() << "cc   " << m_contentName;

		return cout;
	}
}