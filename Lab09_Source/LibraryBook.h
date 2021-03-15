#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>
using namespace std;

class LibraryBook
{
public:
	// Declaring the member functions for this class
	LibraryBook();
	LibraryBook(string titleName, string authorName, string ISBNName);
	string getTitle();
	string getAuthor();
	string getISBN();
	void checkOut();
	void checkIn();
	bool isCheckedOut();

private:
	// Declaring the private variable members of this class for use in member functions
	string title;
	string author;
	string ISBN;
	bool checkedOut;

};

#endif // !LIBRARY_BOOK_H