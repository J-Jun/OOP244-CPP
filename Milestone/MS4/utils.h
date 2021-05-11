/*
	Final Project Milestone 4
	Module:         utils
	Filename:       utils.h
	Author:         Jason Jun
	Student Number: 126 683 200
	Email:          jjun10@myseneca.ca
*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include <iostream>
namespace sdds {

	// making sdds::debug variable global to all the files
	// which include: "utils.h"
	extern bool debug; 

	// Returns the time of day in minutes
	int getTime(); 

	// Performs a fool-proof integer entry form the console
	int getInt(
		const char* prompt = nullptr   // User entry prompt
	);

	// Performs a fool-proof integer entry form the console (with range)
	int getInt(
		int min,   // minimum acceptable value
		int max,   // maximum acceptable value
		const char* prompt = nullptr,  // User entry prompt
		const char* errorMessage = nullptr, // Invalid value error message
		bool showRangeAtError = true    // display the range if invalud value entered 
	);

	// Receives a string, allocates a dynamic Cstring to the size of the string, and copies the value of the string into it
	char* getcstr(
		const char* prompt = nullptr,   // User entry prompt
		std::istream& istr = std::cin,  // the Stream to read from
		char delimiter = '\n'    // Delimiter to mark the end of data
	);
}
#endif // !SDDS_UTILS_H_

