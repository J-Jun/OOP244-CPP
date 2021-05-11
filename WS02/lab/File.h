//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 2 - Lab
//==============================================

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {

	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	// TODO: Declare read prototypes

	// Reads from the file the name of the employee and stores it in the parameter
	bool read(char* employeeName);

	// Reads from the file the employee number and stores it in the parameter
	bool read(int& employeeNumber);

	// Reads from the file the employee salaray and stores it in the parameter
	bool read(double& employeeSalary);

}
#endif // !SDDS_FILE_H_
