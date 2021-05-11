//==============================================
//Name:           Jason Jun
//Student Number: 126 683 200
//Email:          jjun10@myseneca.ca
//Section:        OOP244 NCC
//Workshop:       Workshop 10 - LAB
//==============================================

#include <fstream>

#include "Text.h"
#include "cstring.h"

using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index)const {

       return m_content[index];
   }

   Text::Text(const char* filename) {

       if (filename) {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }

   Text::Text(const Text& text) {

       m_filename = nullptr;
       m_content = nullptr;
       *this = text;
   }

   Text& Text::operator=(const Text& text) {

       if (this != &text) {

           delete[] m_filename;
           m_filename = nullptr;
           delete[] m_content;
           m_content = nullptr;

           if (text.m_filename) {

               m_filename = new char[strLen(text.m_filename) + 1];
               strCpy(m_filename, text.m_filename);

               if (text.m_content) {
                   m_content = new char[strLen(text.m_content) + 1];
                   strCpy(m_content, text.m_content);
               }
           }
           else {
               m_filename = nullptr;
               m_content = nullptr;
           }
       }
       return *this;
   }

   Text::~Text() {

       delete[] m_filename;
       m_filename = nullptr;

       delete[] m_content;
       m_content = nullptr;
   }

   void Text::read() {

       char temp;
       ifstream readContent(m_filename);
       
       if (m_content) {
           delete[] m_content;
           m_content = nullptr;
       }
       
       if (readContent.is_open()) {

           int index = 0;

           m_content = new char[getFileLength() + 1];

           while (readContent.get(temp)) {
               m_content[index] = temp;
               index++;
           }
           m_content[index] = '\0';
       }
       else
           m_content = nullptr;
   }

   void Text::write(std::ostream& os)const {

       if (m_content)
           os << m_content;
   }

   std::ostream& operator<<(std::ostream& ostr, const Text& text) {

       text.write(ostr);
       return ostr;
   }
}