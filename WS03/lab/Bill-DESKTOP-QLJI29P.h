//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - LAB
//==============================================

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_

#include "Item.h"

namespace sdds {

   class Bill {

      // Private Variables:

      // Title of the shopping list
      char m_title[37]; 

      // Pointer to the dynamically allocated array of Items
      Item* m_items; 

      // Size of the dynamically allocated array of Items
      int m_noOfItems; 

      // Number of the Items added by the add method
      int m_itemsAdded; 


      // Private Member Functions:

      // Returns the total tax applied to the Items
      double totalTax()const; 

      // Returns the sum of prices of Items
      double totalPrice()const; 

      // Prints the title of the shipping list
      void Title()const; 

      // Prints the footer containing total tax, price and total price after tax
      void footer()const; 

      // Sets the Bill to an empty state
      void setEmpty(); 

      // Returns true if the Bill and all of its Items are valid
      bool isValid()const; 

   public:

      // Dynamically allocate an array of Items if the arguments are valid
      void init(const char* title, int noOfItems);
      
      // Set the next available subject to the given argument values
      bool add(const char* item_name, double price, bool taxed);

      // Prints the title, m_items elements, and the footer
      void display()const;

      // Deallocates the m_items arraus and sets the pointers to null
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
