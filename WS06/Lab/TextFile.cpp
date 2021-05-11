//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 6 - LAB
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {

        if (m_value) {
            delete[] m_value;
        }
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {

        if (isCopy) {

            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else {

            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {

        // Variable:
        char newLine;

        ifstream fileRead(m_filename);

        if (fileRead.is_open()) {
            while (fileRead) {

                newLine = fileRead.get();
                if (newLine == '\n')
                    m_noOfLines++;
            }
            m_noOfLines++;
        }
        else {
            delete[] m_filename;
            m_filename = nullptr;
        }

        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText() {

        if (m_filename) {

            // Variables:
            unsigned indexCount = 0;
            string textLine;

            if (m_textLines) {
                delete[] m_textLines;
                m_textLines = nullptr;

            }
            m_textLines = new Line[m_noOfLines];

            ifstream fileRead(m_filename);

            if (fileRead.is_open()) {
                while (getline(fileRead, textLine)) {
                    m_textLines[indexCount].m_value = new char[strLen(textLine.c_str()) + 1];
                    strCpy(m_textLines[indexCount].m_value, textLine.c_str());
                    indexCount++;
                }
            }
            m_noOfLines = indexCount;
        }
    }

    void TextFile::saveAs(const char* fileName)const {

        ofstream fout(fileName);

        if (fout.is_open()) {
            for (unsigned i = 0; i < m_noOfLines; i++) {
                fout << m_textLines[i] << endl;
            }
        }
    }

    void TextFile::setEmpty() {

        if (m_textLines) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfLines = 0;
    }

    TextFile::TextFile(unsigned pageSize) {

        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {

        setEmpty();
        m_pageSize = pageSize;

        if (filename && filename[0] != '\0') {

            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);

            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& src) {


        setEmpty();
        m_pageSize = src.m_pageSize;

        if (src.m_filename && src.m_noOfLines > 0) {
            setFilename(src.m_filename, true);

            m_textLines = new Line[src.m_noOfLines];

            for (unsigned i = 0; i < src.m_noOfLines; i++) {
                m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
            }
            m_noOfLines = src.m_noOfLines;
            saveAs(m_filename);
        }
    }

    TextFile& TextFile::operator=(const TextFile& src) {

        if (this != &src) {

            delete[] m_textLines;
            m_textLines = nullptr;

            if (src.m_textLines) {

                m_noOfLines = src.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                // Variable:
                unsigned i = 0;

                while (i < m_noOfLines) {
                    m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
                    i++;
                }
                saveAs(m_filename);
            }
        }
        return *this;
    }

    TextFile::~TextFile() {

        delete[] m_filename;
        m_filename = nullptr;

        delete[] m_textLines;
        m_textLines = nullptr;
    }

    unsigned TextFile::lines()const {

        return m_noOfLines;
    }

    std::ostream& TextFile::view(std::ostream& ostr)const {

        if (m_filename && m_filename[0] != '\0') {

            // Variable:
            unsigned fileLine = 0;
            char x;

            ostr << m_filename << endl;
            for (int fileLine = 0; fileLine < strLen(m_filename); fileLine++) {
                ostr << '=';
            }
            ostr << endl;

            for (fileLine = 0; fileLine < m_noOfLines && fileLine < m_pageSize; fileLine++) {
                ostr << m_textLines[fileLine] << endl;
            }

            if (fileLine < m_noOfLines) {
                do {
                    ostr << "Hit ENTER to continue...";
                    cin.get(x);

                    for (unsigned j = 0; j < m_pageSize && fileLine < m_noOfLines; j++) {
                        ostr << m_textLines[fileLine] << endl;
                        fileLine++;
                    }
                } while (fileLine < m_noOfLines);
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {

        // Variable:
        string n_fileName;

        istr >> n_fileName;

        m_filename = new char[strLen(n_fileName.c_str()) + 1];
        strCpy(m_filename, n_fileName.c_str());
        istr.ignore(30000, '\n');

        setNoOfLines();
        loadText();

        return istr;
    }

    const char* TextFile::operator[](unsigned index)const {

        if (m_filename && m_filename[0] != '\0') {

            if (index >= m_noOfLines)
                index -= m_noOfLines;
        }
        return (m_textLines[index].m_value);
    }

    TextFile::operator bool()const {

        return (m_textLines);
    }

    const char* TextFile::name()const {

        return m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {

        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {

        text.getFile(istr);
        return istr;
    }
}