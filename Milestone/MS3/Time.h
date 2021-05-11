/*
    Final Project Milestone 3
    Module:         Time
    Filename:       Time.h
    Author:         Jason Jun
    Student Number: 126 683 200
    Email:          jjun10@myseneca.ca
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <iostream>

namespace sdds {

   class Time {
      unsigned int m_min;

   public:

      // Sets the "Time" to the current time using "getTime()", then returns the reference of the current object
      Time& setToNow();

      // Sets the number of minutes held in the object or set the time to zero by default
      Time(unsigned int min = 0);

      // Write the time into a stream in "HH:MM" format 
      std::ostream& write(std::ostream& ostr) const;

      // Reads the time from a stream in "H:M" format
      std::istream& read(std::istream& istr);

      // Designing the subtraction in the "Time" as if you are turning a 24-hour clock backwards
      Time& operator-=(const Time& D);

      // Modify the left operandand returns a Time object that is the result of the calculation
      Time operator-(const Time& D)const;

      // Add the minute value of the right operand to the value of the left operandand then returns the reference of the left operand
      Time& operator+=(const Time& D);

      // Creates a Time object with the minute value that is the sum of the minute values of the left and right operands and then returns it
      Time operator+(const Time& D)const;

      // Sets the minute value of the left operand to the value of the right operandand then returns the reference of the left operand
      Time& operator=(unsigned int val);

      // Multiplies the minutes' value of the left operand by the value of the right operand and then returns the reference of the left operand
      Time& operator *= (unsigned int val);

      // Divides the minutes' value of the left operand by the value of the right operand and then returns the reference of the left operand
      Time& operator /= (unsigned int val);

      //Creates a Time object with the minutes value being the product of the minutes' value of the left operand by the value of the right operand and returns the object.
      Time operator *(unsigned int val)const;

      // Creates a Time object with the minutes value being the division of the minutes' value of the left operand by the value of the right operand and returns the object
      Time operator /(unsigned int val)const;

      // Return the number of minutes as an unsigned integer
      operator unsigned int()const;

      // Return the number of minutes as an integer
      operator int()const;
   };

   // Insert a Time object into an ostream object
   std::ostream& operator<<(std::ostream& ostr, const Time& D);

   // Extract data from an istream object into the Time object
   std::istream& operator>>(std::istream& istr, Time& D);
}
#endif // !SDDS_TIME_H

