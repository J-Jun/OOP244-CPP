//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 2 - Lab
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include "File.h"

namespace sdds {

    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // TODO: read functions go here
    bool read(char* employeeName) {

        return (fscanf(fptr, "%[^\n]\n", employeeName) == 1);
    }

    bool read(int& employeeNumber) {

        return (fscanf(fptr, "%d,", &employeeNumber) == 1);
    }

    bool read(double& employeeSalary) {

        return (fscanf(fptr, "%lf,", &employeeSalary) == 1);
    }
}
