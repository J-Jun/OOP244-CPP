//==============================================
//Name:           Jason Jun
//Student Number: 126 683 200
//Email:          jjun10@myseneca.ca
//Section:        OOP244 NCC
//Workshop:       Workshop 10 - LAB
//==============================================

#include "HtmlText.h"
#include "cstring.h"

namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename){

		if (title) {

			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	HtmlText::HtmlText(const HtmlText& h_text) : Text(h_text){

		m_title = nullptr;
		*this = h_text;
	}

	HtmlText& HtmlText::operator=(const HtmlText& h_text) {

		if (this != &h_text) {

			delete[] m_title;
			m_title = nullptr;

			if (h_text.m_title) {

				Text::operator=(h_text);

				m_title = new char[strLen(h_text.m_title) + 1];
				strCpy(m_title, h_text.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

	HtmlText::~HtmlText() {

		delete[] m_title;
		m_title = nullptr;
	}

	void HtmlText::write(std::ostream& os)const {

		// Variables:
		bool MS = false;
		int index = 0;

		os << "<html><head><title>";
		if (m_title)
			os << m_title;
		else
			os << "No Title";
		os << "</title></head>\n<body>\n";

		if (m_title) {

			os << "<h1>" << m_title << "</h1>\n";
			while (Text::operator[](index) != '\0') {
				switch (Text::operator[](index)) {

				case ' ':
					if (MS)
						os << "&nbsp;";
					else {
						MS = true;
						os << " ";
					}
					break;

				case '<':
					os << "&lt;";
					MS = false;
					break;

				case '>':
					os << "&gt;";
					MS = false;
					break;

				case '\n':
					os << "<br />\n";
					MS = false;
					break;

				default:
					MS = false;
					os << Text::operator[](index);
				}
				index++;
			}
		}
		os << "</body>\n</html>";
	}
}