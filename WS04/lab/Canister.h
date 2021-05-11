//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 4 - LAB
//==============================================

#ifndef SDDS_BOX_H
#define SDDS_BOX_H

#include <iostream>

namespace sdds {

   class Canister {

       // Private member variables:
      char* m_contentName; // points to a dynamically allocated Cstring
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable;

      // Private member functions
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;

   public:

       // Public member functions
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter, const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister&);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
}
#endif // !SDDS_BOX_H
