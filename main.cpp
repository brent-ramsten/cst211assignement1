/*
Brent Ramsten

cst211

assignment #1
*/


#include <iostream>
#include "exception.h"
#include "array.h"


using namespace std;


int main()
{
	//everything up to the user menu is merely a test situations to show what my program can do


	//variables with initial values used to illustrate what type of information you will be inserting into the new arrays
	//specifically: length and the begining index
	int length = 10;
	int beginingIndex = -5;
	int length2 = 3;
	

	//this sends the length & begining index into the Array class
	//it then establishes the array which is known as the m_values
	Array<int> theArray(length, beginingIndex);
	

	//this inserts a value into the array through the operator[] and stores it.
	theArray[0] = 5;
	//then it is referanced again to output it
	cout << theArray[0];
	
	theArray[3] = 4;
	cout << theArray[3];


	//a new array is established
	Array<int> newArray(length2, beginingIndex);
	
	//the array is smaller in length but is filled with all the values in "theArray" until it is full by means of the operator=
	newArray = theArray;
	cout << newArray[0];




	//below used as example for incorrect bounds checking, will cause program to output error and fail during runtime
	//cout << theArray[-6];
	//cout << theArray[10];


	//beyond this point is my user oriented data
	Array<int> menuArray(1, 1);

	int choice = 0;
	int newEntry = 0;


	cout << "\nthis array is filled with integers\ntype 'q' to end program\n";
	while (choice != 'q')
	{
		cout << "\n\nenter 1 to change length enter 2 to changed the begining index enter press 3 to enter in a cell of the array 4 to insert information into a cell\n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nenter new length: ";
			cin >> newEntry;
			//i got very strange unresolved external errors, so this stays out for now
			menuArray.setLength(newEntry);
		}

		else if (choice == 2)
		{
			cout << "\nenter new start index: ";
			cin >> newEntry; 
			//i got very strange unresolved external errors, so this stays out for now
			menuArray.setStartIndex(newEntry);
		}

		else if (choice == 3)
		{
			cout << "\nenter in cell and integer";
			cin >> newEntry, choice;
			menuArray[newEntry] = choice;
		}

		else if (choice == 4)
		{
			cout << "enter the cell you wish to show onscreen\n";
			cin >> newEntry;
			cout << menuArray[newEntry];
		}

	}
	


	return 0;
}

