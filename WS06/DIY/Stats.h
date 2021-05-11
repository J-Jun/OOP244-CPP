//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 6 - DIY
//==============================================

#include <iostream>

namespace sdds {
   class Stats {

	   unsigned s_noOfColumns;
	   unsigned s_columnWidth;
	   unsigned s_precision;

	   char* s_fileName;
 
	   void setFilename(const char* fname);
	   void saveAs(const char* fileName)const;
	   void loadText();

	   void setNoOfOccurence();
	   void loadStats();

   public:

	   Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
	   Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);

	   Stats(const Stats&);
	   Stats& operator=(const Stats&);
	   ~Stats();

	   std::ostream& view(std::ostream& ostr)const;
	   std::istream& getFile(std::istream& istr);

	   double& operator[](unsigned idx);
	   double operator[](unsigned idx)const;

	   operator bool()const;

	   void sort(bool ascending);
	   unsigned size()const;
	   const char* name()const;
	   unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);

	   
   };

   std::ostream& operator<<(std::ostream& ostr, const Stats& text);
   std::istream& operator>>(std::istream& istr, Stats& text);
}
