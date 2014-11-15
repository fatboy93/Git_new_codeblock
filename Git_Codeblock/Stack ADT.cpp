/*
Name: Nghia Nguyen
HW-2
Email: fatboy_dn_2193@yahoo.com
IDE: Visual Studio
*/
// change change
#include "Stack ADT.h"
#include <fstream>
#define MAX 100

void Hold();
bool ReadFiles(Stack<int> *stack);
void Track_item(Stack<int> *stack, int);
void pop_print_item(Stack<int> *stack, int);
void signature()
{
    cout<<right<<setw(47)<<"HW-2: Stack ADT \n\n";
    cout<<right<<setw(45)<<"Nghia Nguyen\n\n";
    cout<<right<<setw(54)<<"Email: fatboy_dn_2193@yahoo.com\n\n";
    cout<<right<<setw(43)<<"----------\n\n";
}
int main()
{
	signature();
	Stack<int> *stack = new Stack<int>;
	if(!ReadFiles(stack))
	{
		cout << "There's no data.\n";
		system("pause");
		return 1;
	}

	delete stack;
	system("pause");

	return 0;
}

/**************************************************
   The ReadFiles function reads items from an
   array holding the names of files and processes
   those files until it reaches QUIT. This function
   returns false if there is no file.
***************************************************/
bool ReadFiles(Stack<int> *stack)
{
	bool empty = true;
	string InputFile[] = { "numbers1.txt", "numbers2.txt", "numbers3.txt", "QUIT" };
	int numfile = sizeof(InputFile) / sizeof(InputFile[0]);
	char tempFile[MAX];
	int item;
	ifstream inFile;

	for(int i=0; i<numfile; i++)
	{
		if (i==0 && InputFile[i] == "QUIT")
			return false;

		if (i>0 && InputFile[i] == "QUIT")
		{
			cout << "Finished processing files.\n\n";
			return true;
		}//if
		strcpy(tempFile,InputFile[i].c_str());

		inFile.open(tempFile);
		if(!inFile)
		{
			cout << "->There's no such file " << InputFile[i] <<endl<<endl;
			Hold();
		}//if
		else
		{
			cout << "->Processing file " << InputFile[i] << endl << endl;
			while(inFile>>item)
				Track_item(stack, item);
			inFile.close();

			if (stack->isEmpty())
				cout << "\n->End of file " << InputFile[i] << ". Empty Stack\n";

			else
			{	//Pop every item from stack at the end of file and print them.
				cout << "\n->End of file " << InputFile[i] << ". The stack from top to bottom: ";
				pop_print_item(stack, stack->getCount());
			}//else
			Hold();
			empty = false;
		}//else
	}//for

	if(empty)
		return false;

	return true;
}

/**********************************************
   The Track_item function determine what need
   to be done with the item form the files.For
   example 0 number of elements, 1 emlement on
   top of stack and so forth.
**********************************************/
void Track_item(Stack<int> *stack, int item)
{
	if(item == 0)
		cout << "Number of elements in the stack: " << stack->getCount() << endl;

	else if (item == 1)
	{
		if (stack->getCount() == 0)
			cout << "Stack is empty.\n";
		else
		cout << "Element on top of the stack: " << stack->getTop() << endl;
	}//else if
	else if(item > 1)
		stack->push(item);

	else if(item < 0 && abs(item)>stack->getCount())
		cout << "Can't pop values because " <<abs(item)
			 << " is greater than the number of elements in stack\n";

	else if (item < 0 && abs(item) <= stack->getCount())
	{
		cout << "Pop and print " << abs(item) << " numbers: ";
		pop_print_item(stack, item);
	}//else if
}

/*********************************************
   The popItem function pops an item from the
   stack and print the item to black screen.
*********************************************/
void pop_print_item(Stack<int> *stack, int item)
{
	int temp_value;
		for(int j=0; j < abs(item); j++)
		{
			stack->pop(temp_value);
			if(j!=abs(item)-1)
			cout << temp_value << ", ";
			else cout << "and " << temp_value <<".";
		}//for
	cout<<endl;
}
/***********************************************
 The Hold function pauses the programs using cin.
***********************************************/
void Hold()
{
	string hold;
	cout << "\n->Press Enter to start processing the next file (if exist): ";
	getline(cin, hold);
	cout << "--------------------------------------------------------------------------------\n";
}
/*
HW-2: Stack ADT

Nghia Nguyen

Email: fatboy_dn_2193@yahoo.com

----------

->Processing file numbers1.txt

Element on top of the stack: 30
Number of elements in the stack: 4
Pop and print 2 numbers: 50, and 40.
Pop and print 3 numbers: 25, 15, and 30.

->End of file numbers1.txt. The stack from top to bottom: 70, 60, 20, and 10.

->Press Enter to start processing the next file (if exist):
--------------------------------------------------------------------------------

->Processing file numbers2.txt

Can't pop values because 6 is greater than the number of elements in stack
Pop and print 5 numbers: 50, 40, 30, 20, and 10.

->End of file numbers2.txt. Empty Stack

->Press Enter to start processing the next file (if exist):
--------------------------------------------------------------------------------

->Processing file numbers3.txt

Number of elements in the stack: 4
Element on top of the stack: 45
Number of elements in the stack: 4
Number of elements in the stack: 7
Element on top of the stack: 75
Number of elements in the stack: 7
Can't pop values because 50 is greater than the number of elements in stack
Number of elements in the stack: 7
Element on top of the stack: 75
Number of elements in the stack: 7
Pop and print 5 numbers: 75, 65, 55, 45, and 35.
Number of elements in the stack: 9
Element on top of the stack: 90
Number of elements in the stack: 9
Pop and print 3 numbers: 90, 80, and 70.
Pop and print 5 numbers: 54, 43, 33, 23, and 13.
Number of elements in the stack: 6
Element on top of the stack: 60
Number of elements in the stack: 6
Number of elements in the stack: 24
Element on top of the stack: 99
Pop and print 6 numbers: 99, 89, 79, 69, 59, and 49.
Number of elements in the stack: 18
Element on top of the stack: 39
Number of elements in the stack: 22
Can't pop values because 150 is greater than the number of elements in stack
Number of elements in the stack: 24

->End of file numbers3.txt. The stack from top to bottom: 64, 54, 44, 34, 24, 14
, 39, 29, 19, 97, 87, 77, 67, 57, 47, 37, 27, 17, 60, 50, 40, 10, 25, and 15.

->Press Enter to start processing the next file (if exist):
--------------------------------------------------------------------------------

Finished processing files.

'\\puma\home\20114898\Visual Studio 2013\Projects\HW - 2\HW - 2'
CMD.EXE was started with the above path as the current directory.
UNC paths are not supported.  Defaulting to Windows directory.
Press any key to continue . . .

*/
