// Joe Epperson, IV
// jee4cf@umsystem.edu
// 3/15/2021
// CS201L Lab 09

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "LibraryBook.h"


int main() 
{
	// Declaring the temporary string variables
	string inpTitle;
	string inpAuthor;
	string inpISBN;
	string checkISBN;

	// Declaring the file input and output variables
	ifstream fin;
	ifstream fISBN;
	ofstream finalReport;

	// Declaring the vector to store all of the books taken from the input file
	vector<LibraryBook> allBooks;

	// Opening the books.txt file
	fin.open("books.txt");
	while (!fin.eof())
	{
		// Assigning temporary values with the title, author, and ISBN from the file
		getline(fin, inpTitle);
		getline(fin, inpAuthor);
		getline(fin, inpISBN);

		// Putting the temporary values into a temporary variable of the same class type
		LibraryBook currVal(inpTitle, inpAuthor, inpISBN);

		// Storing the variable of LibraryBook class type into the last element of the vector allBooks
		allBooks.push_back(currVal);
	}
	// Closing the input file
	fin.close();

	// Opening the isbns.txt file
	fISBN.open("isbns.txt");
	while (!fISBN.eof())
	{
		// Getting the value for the currently being checked ISBN number
		getline(fISBN, checkISBN);

		// Looping through all values within vector allBooks until the correlating ISBN number is found
		for (int i = 0; i < allBooks.size(); ++i)
		{
			if (allBooks.at(i).getISBN() == checkISBN)
			{
				// Once the correct number is found, determining whether to check the book in or out and then doing the appropriate action
				if (allBooks.at(i).isCheckedOut() == false)
				{
					allBooks.at(i).checkOut();
				}
				else if (allBooks.at(i).isCheckedOut() == true)
				{
					allBooks.at(i).checkIn();
				}
			}
			else
			{
				continue;
			}
		}
	}
	// Closing the input file
	fISBN.close();

	// Opening the output file
	finalReport.open("checkedout.txt");

	// Outputting the standard items before entering the loop
	finalReport << "Books checked out:" << endl;
	finalReport << "------------------" << endl << endl << endl;
	finalReport << "Title    Author    ISBN" << endl << endl;

	// Looping through the vector allBooks searching for every book that has been checked out
	for (int i = 0; i < allBooks.size(); ++i)
	{
		// Assigning the output file with the title, author, and ISBN of all of the books that are currently checked out
		if (allBooks.at(i).isCheckedOut() == true)
		{
			finalReport << allBooks.at(i).getTitle() << "    " << allBooks.at(i).getAuthor() << "    " << allBooks.at(i).getISBN() << endl << endl;
		}
		else
		{
			continue;
		}
	}

	return 0;
}