/*
==============================================
Name:           Jason Jun
Student Number: 126 683 200
Email:          jjun10@myseneca.ca
Section:        OOP244 NCC
Workshop:       Workshop 9 - LAB
==============================================

search Function:
	
	I have used <typename T1, typename T2> to accept the templated objects and the keys. For the templated objects, it had reference to the Collection template class, so I have used the "typename". Then the T1 will be able to accept the classes (Car, Student, Employee). For the keys, the type of it gets different per classes as it is called, so "typename" was chosen to be used. 

listArrayElements Function:
	
	I used <typename L> because the "typename" accepts different types of array, instead of one specific type. Moreover, as main.cpp compiles, "typename" will determine what type of array the main.cpp had sent. Then the function will output the required fields.
*/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"

using namespace std;
namespace sdds {

	template <typename T1, typename T2>
	bool search(Collection<T1>& collectedObjects, const T1* arrayObjects, int numElement, const T2 key) {

		bool foundValue = false;

		for (int i = 0; i < numElement; i++) {

			if (arrayObjects[i] == key) {
				collectedObjects.add(arrayObjects[i]);
				foundValue = true;
			}
		}
		return foundValue;
	}

	template <typename L>
	void listArrayElements(const char* titleList, const L arrayObjects, int numElement) {

		cout << titleList << endl;
		for (int i = 0; i < numElement; i++) {

			cout << (i + 1) << ": " << arrayObjects[i] << endl;
		}
	}

}
#endif // !SDDS_SEARCHNLIST_H_