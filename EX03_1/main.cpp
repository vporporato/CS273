#include <iostream>
#include <stdexcept>
#include "readint.h"

using namespace std;

int main()

{
	int low, high;
	cout << "Enter the range of values to read.\n";
	cout << "high: ";
	cin >> high;
	cout << "low: ";
	cin >> low;
	do {
		//If the number is in the given range then the program will end. If not it will run through readint.cpp//
		try   
		{
			int number = read_int("Please enter a number within the range: ", low, high);

			cout << "You entered " << number << endl;
			return 0;
		}
		//First checks to see if the high end of the range is less than the low end which is an empty range and ends the program
		catch (invalid_argument &e) {

			cerr << "Exception: You supplied an invalid argument for read_int!\n";
			return 0;
		}
		//Lastly checks to see if the number is in the range, and if its not it asks the user to input a new number
		catch (range_error &e) {
			cerr << "The number is not in the range.\n";
		}
	} while (true);
}