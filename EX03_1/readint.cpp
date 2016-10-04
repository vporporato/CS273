#include "readint.h"
#include <iostream>
#include <stdexcept>
using namespace std;


int read_int(const string &prompt, int low, int high)

{
	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) {

		if (high <= low)
		{
			throw invalid_argument("Invalid range, The high is less than the low resulting in an empty range.");
		}

		try {
			cout << prompt;
			cin >> num;
				//std exception error for when the user enters a number that is not between the high and low vlaues that the user entered.
		if (num < low || num> high)
			{
				throw range_error("The number was not between the given range\n");
				
			}
				return num;
			}
		catch (ios_base::failure& ex) {
			cout << "Bad numeric string. Try again.\n";
			//reset error flag
			cin.clear();
			//skip current input line
			cin.ignore(numeric_limits<int>::max(), '\n');
		}

		catch (range_error &ex)
		{
			cerr << "The number you entered is not in the range.\n";
		}

	}	
}