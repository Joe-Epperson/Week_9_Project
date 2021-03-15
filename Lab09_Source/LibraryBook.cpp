
#include <string>
#include "LibraryBook.h"

LibraryBook::LibraryBook()
{
	// Default constructor
	title = "";
	author = "";
	ISBN = "";
	checkedOut = false;
}

LibraryBook::LibraryBook(string titleName, string authorName, string ISBNName)
{
	// Assignment constructor
	title = titleName;
	author = authorName;
	ISBN = ISBNName;
	checkedOut = false;
}

// Assigning each member function with the correct code for the given purpose
string LibraryBook::getTitle()
{
	return title;
}

string LibraryBook::getAuthor()
{
	return author;
}

string LibraryBook::getISBN()
{
	return ISBN;
}

void LibraryBook::checkOut()
{
	checkedOut = true;
}

void LibraryBook::checkIn()
{
	checkedOut = false;
}

bool LibraryBook::isCheckedOut()
{
	return checkedOut;
}
