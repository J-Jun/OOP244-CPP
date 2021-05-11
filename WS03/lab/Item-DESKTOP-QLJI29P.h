//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 3 - LAB
//==============================================

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_

namespace sdds {

   class Item {
      
      // Private Variables:
      char m_itemName[21]; // holds the item name up to 20 chars
      double m_price;
      bool m_taxed;

      // Private Member Function:
      void setName(const char* name);

   public:

      // Set the Item to arecognizable safe Empty State
      void setEmpty(); 

      // Sets the m_itemName attribute to the Cstring
      void set(const char* name, double price, bool taxed);

      // Prints an item in a format
      void display()const;

      // Returns true if the Item is not set to the empty state
      bool isValid()const;

      // Returns the m_price attribute
      double price()const;

      // Returns the tax attribute
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
