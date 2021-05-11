//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 6 - LAB
//==============================================

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
    class Text;
    class Line {

        // Holds the address of the dynamically allocated Cstring (to hold a line of the text file)
        char* m_value{ nullptr };

        // Returns the address held in the "m_value" attribute
        operator const char* ()const;

        // Initializes the "m_value" attribute to nullptr
        Line() {};

        // Dynamically allocates memory in "m_value" and copies the Cstring into it
        Line& operator=(const char*);

        // Making sure all the allocated memory is freed
        ~Line();

        // copy and copy assignment prevention goes here
        friend class TextFile;
    };

    class TextFile {

        // A pointer to hold the dynamic array of "Lines"
        Line* m_textLines{ nullptr };

        // A pointer to hold the dynamic Cstring, holding the name of the file
        char* m_filename{ nullptr };

        // An unsigned integer to be set to the number of lines in the file
        unsigned m_noOfLines;

        // The number of lines that should be displayed on the screen before the display is paused
        unsigned m_pageSize;

        // Copies the contentof the "fname" argument into the "m_filename"
        void setFilename(const char* fname, bool isCopy = false);

        // Counts the number of lines in the file
        void setNoOfLines();

        // Loads the text file "m_filename" into the dynamic array of Lines pointed by m_textLines
        void loadText();

        // Saves the content of the TextFile under a new name
        void saveAs(const char* fileName)const;

        // Empty out the data
        void setEmpty();

    public:

        // Creates an empty "TextFile" and initializes the m_pageSize attribute using the pageSize argument
        TextFile(unsigned pageSize = 15);

        // Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero
        TextFile(const char* filename, unsigned pageSize = 15);

        // Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object and all the other attributes to nullptr and zero
        TextFile(const TextFile&);

        // Copy assignment
        TextFile& operator=(const TextFile&);

        // Deletes all the dynamic data
        ~TextFile();

        // Prints the filename and then the content of the file "m_pageSize" lines at a time
        std::ostream& view(std::ostream& ostr)const;

        // Receives a filename from istr to set the file name of the TextFile
        std::istream& getFile(std::istream& istr);

        // Returns true if the TextFile is not in an empty state and returns false if it is
        operator bool()const;

        // Returns m_noOfLines
        unsigned lines()const;

        // Returns the filename
        const char* name()const;

        // Returns the element in the m_textLine array corresponding to the index argument
        const char* operator[](unsigned index)const;
    };

    // Uses the view() method to print the TextFile
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);

    // Uses the getFile() method to get the file name from console and load the content from the file
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__