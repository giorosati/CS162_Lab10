/*********************************************************************
** Program Filename: main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-08
** Description: File with main() for CS162_400 Lab 10
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::setprecision;


//function prototypes
//displays user options to console
void displayMenu();

//gets user input
int getInput();

//fibonacci iteration algorithm from
//http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
long FibonacciIter(int n);

//fibonacci recursive algorithm modified and from
//http://code.runnable.com/UqfN-4zVBhVwAAH9/solving-the-fibonacci-number-sequence-using-recursion-in-c%2B%2B-for-recursive
long FibonacciRecur(int n);

//from Professor Rooker
//Not Tail Recursive factorial function
long rfactorial(int n);

//from Professor Rooker
//Tail Recursive factorial function & helper function
long factorialHelper(int n, long result);
long factorial(int n);

//creates and returns a string with commas for displaying large numbers 
string addCommas(long n);

int main() {
	bool done = false;	//for menu
	int menuChoice = 0;	//for menu/user inputs
	int n = -1;			//user selectable # for fibonacci # and factorial tests
	clock_t t1;			//used to capture time at start of test
	clock_t t2;			//used to capture time as end of test
	long fib;			//used for fibonacci result
	long fact;			//used for factorial result

	while (done != true)
	{
		displayMenu();
		menuChoice = getInput();
		switch (menuChoice) {
		case 1:		//fibonacci tests
			cout << "This program will compare the amount of time it takes" << endl;
			cout << "to find the N'th Fibonacci number, using iterative and " << endl;
			cout << "recursive algorithms. You will enter N." << endl;
			cout << endl;
			while (n < 0)
			{
				cout << "Enter a positive integer 'N' LESS THAN 46!" << endl;
				cout << "(N of over 45 will exceed programs limits," << endl;
				cout << " and N of 19 or more will take over a minute to complete...)" << endl;
				cout << "Your entry: ";
				cin.ignore();
				cin >> n;
				if (n < 0 || n > 45)
				{
					cout << "Invalid entry..." << endl;
					n = -1;
					cout << endl;
				}
			}
			//fibonacci iteration
			cout << "Finding " << addCommas(n) << "'th " << "fibonacci number...." << endl;
			cout << "Calling Iterative Fibonacci implementation" << endl;
			t1 = clock();
			for (int i = 0; i < 1000000; i++)
			{
				fib = FibonacciIter(n);
			}
			t1 = clock() - t1;
			cout << endl;
			cout << "Value returned from FibonacciIter(): " << addCommas(fib);
			cout << endl;
			cout << "It took " << addCommas(t1) << " clicks (" << setprecision(9) << ((float)t1) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << endl;

			//fibonacci recursive
			cout << "Finding " << addCommas(n) << "'th " << "fibonacci number...." << endl;			
			cout << "Calling Recursive Fibonacci implementation" << endl;
			t2 = clock();
			for (int i = 0; i < 1000000; i++)
			{
				fib = FibonacciRecur(n);
			}
			t2 = clock() - t2;
			cout << endl;
			cout << "Value returned from FibonacciRecur: " << addCommas(fib);
			cout << endl;
			cout << "It took " << addCommas(t2) << " clicks (" << setprecision(9) << ((float)t2) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << endl;
			n = -1;		//reset n
			break;

		case 2:		//factorial tests
			cout << "This program will compare the amount of time it takes" << endl;
			cout << "to find the factorial of N, using recursive and " << endl;
			cout << "tail recursive algorithms. You will enter N." << endl;
			cout << endl;
			while (n < 0)
			{
				cout << "Enter a positive integer 'N' LESS THAN 17!" << endl;
				cout << "(over 16 will exceed program limits in a Windows 10 64 bit system" << endl;
				cout << "and N of 16 will require over 15 seconds to complete." << endl;
				cout << "Your entry: ";
				cin.ignore();
				cin >> n;
				if (n < 0 || n > 16)
				{
					cout << "Invalid entry..." << endl;
					n = -1;
					cout << endl;
				}
			}
			//non tail recursive factorial test
			cout << "Finding factorial of " << addCommas(n) << endl;
			cout << "Calling non tail recursive factorial method" << endl;
			t1 = clock();
			for (int i = 0; i < 100000000; i++)
			{
				fact = rfactorial(n);   
			}
			t1 = clock() - t1;
			cout << endl;
			cout << "Value returned from rfactorial(): " << addCommas(fact);
			cout << endl;
			cout << "It took " << addCommas(t1) << " clicks (" << setprecision(9) << ((float)t1) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << endl;

			//tail recursive factorial test
			cout << "Finding factorial of " << addCommas(n) << endl;
			cout << "Calling tail recursive factorial method" << endl;
			t2 = clock();
			for (int i = 0; i < 100000000; i++)
			{
				fact = factorial(n);
			}
			t2 = clock() - t2;
			cout << endl;
			cout << "Value returned from factorial(): " << addCommas(fact);
			cout << endl;
			cout << "It took " << addCommas(t2) << " clicks (" << setprecision(9) << ((float)t2) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << endl;
			n = -1;		//reset n
			break;
		case 3:
			done = true;
			break;
		default:
			std::cout << "Not a valid choice" << std::endl;
			break;
		}
	}
	return 0;
}

//displays user options to console
void displayMenu()
{
	cout << endl;
	cout << "Choose option and press enter" << endl;
	cout << "*****************************" << endl;
	cout << "  1) Run the Fibonacci comparision" << endl;
	cout << "  2) Run the Factorial tests" << endl;
	cout << "  3) Exit" << endl;
	cout << endl;
}

int getInput() {	//to collect user responses to menu
	int choice;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}

//fibonacci iteration algorithm from
//http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
long FibonacciIter(int num)
{
	long first = 0;
	long second = 1;
	int counter = 2;
	while (counter < num)
	{
		long temp = second;
		second = first + second;
		first = temp;
		++counter;
	}
	if (num == 0)
		return 0;
	else
		return first + second;
}

//fibonacci recursive algorithm modified and from
//http://code.runnable.com/UqfN-4zVBhVwAAH9/solving-the-fibonacci-number-sequence-using-recursion-in-c%2B%2B-for-recursive
long FibonacciRecur(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	long result = FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
	return result;
}


//from Professor Rooker
//Not Tail Recursive factorial function
long rfactorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n* rfactorial(n - 1);
}

//from Professor Rooker
//Tail Recursive factorial function & helper function
long factorialHelper(int n, long result)
{
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}

long factorial(int n)
{
	return factorialHelper(n, 1);
}


//original addCommas function, didn't compile on FLIP
//string addCommas(long n)
//{
//	string output = to_string(n);
//	int commaPlace = output.length() - 3;
//	while (commaPlace > 0)
//	{
//		output.insert(commaPlace, ",");
//		commaPlace -= 3;
//	}
//	return output;
//}

//creates and returns a string with commas for displaying large numbers 
string addCommas(long n)
{
	ostringstream ss;
	ss << n;
	string output = ss.str();
	int commaPlace = output.length() - 3;
	while (commaPlace > 0)
	{
		output.insert(commaPlace, ",");
		commaPlace -= 3;
	}
	return output;
}