/*********************************************************************
** Program Filename: main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-08
** Description: File with main() for CS162_400 Lab 10
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

void displayMenu();
int getInput();

long FibonacciIter(int n);
long FibonacciRecur(int n);
string addCommas(long n);
//string addCommas(double n);

//test
int fibFunction(int num);

int main() {
	bool done = false;
	int menuChoice = 0;
	int n = -1;
	clock_t t;
	long fib;

	while (done != true)
	{
		cout << "This program will compare the amount of time it takes" << endl;
		cout << "to find the N'th Fibonacci number, where you will enter N," << endl;
		cout << "using iterative and recursive algorithms." << endl;
		cout << endl;

		displayMenu();
		menuChoice = getInput();
		switch (menuChoice) {
		case 1:
			while (n < 0)
			{
				cout << "Enter a positive integer LESS THAN 46" << endl;
				cout << "(over 45 will exceed this programs limits)" << endl;
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
			//Iterative test
			cout << "Finding '" << addCommas(n) << " 'th " << "fibonacci number...." << endl;
			cout << "Calling Iterative Fibonacci implementation" << endl;
			t = clock();
			fib = FibonacciIter(n);
			t = clock() - t;
			//cout << "Value returned from FibonacciIter(): " << fib;
			cout << "Value returned from FibonacciIter(): " << addCommas(fib);
			cout << endl;
			cout << "It took " << addCommas(t) << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << endl;

			//Recursive test
			cout << "Finding '" << addCommas(n) << "'th " << "fibonacci number...." << endl;
			cout << "Calling Recursive Fibonacci implementation" << endl;
			t = clock();
			fib = FibonacciRecur(n);
			//fibFunction(n);
			cout << endl;
			//fibFunction(n);
			t = clock() - t;
			cout << "Value returned from FibonacciRecur:" << addCommas(fib);
			cout << endl;
			cout << "It took " << addCommas(t) << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << endl;
			n = -1;		//reset n
			break;
		case 2:
			done = true;
			break;
		default:
			std::cout << "Not a valid choice" << std::endl;
			break;
		}
	}
	return 0;
}

void displayMenu()		//displays user options
{
	cout << endl;
	cout << "Choose option and press enter" << endl;
	cout << "*************************" << endl;
	cout << "  1) Run the Fibonacci comparision" << endl;
	cout << "  2) Exit" << endl;
	cout << endl;
}

int getInput() {	//to collect user responses to menu
	int choice;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}

//used with permission from
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

		//cout << "Values at end of counter loop #: " << counter << endl;
		//cout << "first: " << first << endl;
		//cout << "second: " << second << endl;
		//cout << "temp: " << temp << endl;
		++counter;
	}
	if (num == 0)
		return 0;
	else
		return first + second;
}

//modified and used with permission from
//http://code.runnable.com/UqfN-4zVBhVwAAH9/solving-the-fibonacci-number-sequence-using-recursion-in-c%2B%2B-for-recursive
long FibonacciRecur(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	long result = FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
	return result;
}



string addCommas(int n)
{
	string output = to_string(n);
	int commaPlace = output.length() - 3;
	while (commaPlace > 0)
	{
		output.insert(commaPlace, ",");
		commaPlace -= 3;
	}
	return output;
}

string addCommas(double n)
{
	string output = to_string(n);
	int commaPlace = output.length() - 3;
	while (commaPlace > 0)
	{
		output.insert(commaPlace, ",");
		commaPlace -= 3;
	}
	return output;
}
string addCommas(long n)
{
	string output = to_string(n);
	int commaPlace = output.length() - 3;
	while (commaPlace > 0)
	{
		output.insert(commaPlace, ",");
		commaPlace -= 3;
	}
	return output;
}

//test
int fibFunction(int num)
{
	cout << "Finding the fib of " << num << endl;

	//The rules of Fibonacii states that F0 = 0 and F1 = 1.
	//These are our termination cases.
	if (num == 0)
	{
		cout << "We have reached the termination case of 0. Returning 0" << endl;
		return 0;
	}

	if (num == 1)
	{
		cout << "We have reached the termination case of 1. Returning 1" << endl;
		return 1;
	}

	int result = fibFunction(num - 1) + fibFunction(num - 2);
	cout << "Fib of " << num << " is " << result << endl;
	return result;
}