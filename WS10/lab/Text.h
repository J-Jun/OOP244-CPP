//==============================================
//Name:           Jason Jun
//Student Number: 126 683 200
//Email:          jjun10@myseneca.ca
//Section:        OOP244 NCC
//Workshop:       Workshop 10 - LAB
//==============================================

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {
   class Text {
      char* m_filename = nullptr; // Holds the name of the file dynamically
      char* m_content = nullptr;  // Holds the content of the text file dynamically
      int getFileLength()const; // Returns the length of the text file on the disk
   protected:
      const char& operator[](int index)const; // Provides read-only access to the content of the text for the derived classes of Text
   public:
      Text(const char* filename=nullptr);

      // implement rule of three here
      Text(const Text& text); // Copy contstructor
      Text& operator=(const Text& text); // Copy assignment operator
      ~Text(); // Destructor

      void read(); // Read the current content of the file 
      virtual void write(std::ostream& os)const; // Insert the content of the Text class
   };
   // prototype of insertion overload into ostream goes here
   std::ostream& operator<<(std::ostream& ostr, const Text& text);
}
#endif // !SDDS_TEXT_H__

