/*
    Final Project Milestone 1
    Module:         utils
    Filename:       utils.cpp
    Author:         Jason Jun
    Student Number: 126 683 200
    Email:          jjun10@myseneca.ca
    -----------------------------------------------------------
    Date      Reason
    2020/?/?  Preliminary release
    2020/?/?  Debugged DMA
    -----------------------------------------------------------

    - if (cin.fail()) {
        cout << "Bad integer value, try again: ";
        // Clears the leftover error buffer of the cin
        cin.clear();
        // Ignoring until the newline is found
        cin.ignore(5000, '\n');
        ...
       }

       This portion of my code was brought from:
         https://www.hackerearth.com/practice/notes/validating-user-input-in-c/#:~:text=these%20methods%20are%20%3A-,cin.,kept%20in%20an%20error%20state.
    -----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include "utils.h"
#include "Time.h"

using namespace std;
namespace sdds {

   bool debug = true;  // made global in utils.h

   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   } 

   int getInt(const char* prompt) {

       // Variables:
       int inputInteger = 0;
       bool escapeFlag = false;
       char lastChar;

       if (prompt != nullptr)
           // Displaying prompt before the user inputs in a value
           cout << prompt;

       do {
           escapeFlag = false;

           // Take in the user's inputted value
           cin >> inputInteger;

           // Checking if the value is integer or not
           if (cin.fail()) {
               cout << "Bad integer value, try again: ";
               // Clears the leftover error buffer of the cin
               cin.clear();
               // Ignoring until the newline is found
               cin.ignore(5000, '\n');
               escapeFlag = true;
           }
           else {
               cin.get(lastChar);
               if (lastChar != '\n') {
                   cout << "Enter only an integer, try again: ";
                   // Clears the leftover error buffer of the cin
                   cin.clear();
                   // Ignoring until the newline is found
                   cin.ignore(5000, '\n');
                   escapeFlag = true;
               }
           }
       } while (escapeFlag);

       return inputInteger;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {

       // Variables:
       int inputInteger = 0;
       bool escapeFlag = false;
       char lastChar;

       if (prompt != nullptr) 
           // Displaying prompt before the user inputs in a value
           cout << prompt;

       do {
           escapeFlag = false;

           // Take in the user's inputted value
           cin >> inputInteger;

           // Checking if the value is integer or not
           if (cin.fail()) {

               if (errorMessage != nullptr)
                   cout << "Bad integer value, try again: ";
               // Clears the leftover error buffer of the cin
               cin.clear();
               // Ignoring until the newline is found
               cin.ignore(5000, '\n');
               escapeFlag = true;
           }
           else {
               cin.get(lastChar);

               if (lastChar != '\n') {
                   if (errorMessage != nullptr)
                       cout << "Enter only an integer, try again: ";
                   // Clears the leftover error buffer of the cin
                   cin.clear();
                   // Ignoring until the newline is found
                   cin.ignore(5000, '\n');
                   escapeFlag = true;
               } 
               else {
                   // Checking if the inputted value is within a range
                   if (inputInteger < min || inputInteger > max) {

                       if (errorMessage != nullptr)
                           cout << errorMessage;

                       if (showRangeAtError)
                           cout << "[" << min << " <= value <= " << max << "]: ";
                       escapeFlag = true;
                   }
               }
           }
       } while (escapeFlag);

       return inputInteger;
   }

   char* getcstr(const char* prompt, std::istream& istr, char delimiter) {

       // Variable:
       string unknownString;
       char* copiedString;

       if (prompt != nullptr)
           // Displaying prompt before the user inputs in a value
           cout << prompt;

       // Receiving an unknown size string
       getline(istr, unknownString, delimiter);

       // Allocating the string
       copiedString = new char[strlen(unknownString.c_str()) + 1];
       // Copying the value of the string
       strcpy(copiedString, unknownString.c_str());

       return copiedString;
   }
} 