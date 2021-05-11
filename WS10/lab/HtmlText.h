//==============================================
//Name:           Jason Jun
//Student Number: 126 683 200
//Email:          jjun10@myseneca.ca
//Section:        OOP244 NCC
//Workshop:       Workshop 10 - LAB
//==============================================

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__

#include <iostream>
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title = nullptr; // Holds the title of the HTML conversion dynamically
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);

      // Rule of three goes here
      HtmlText(const HtmlText& h_text); // Copy constructor
      HtmlText& operator=(const HtmlText& h_text); // Copy assignment operator
      ~HtmlText(); // Destructor
      
      void write(std::ostream& os)const; // Text::write override

   };
}
#endif // !SDDS_HTMLTEXT_H__
