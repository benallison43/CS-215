// Ben Allison lab 4 CS 215
// Tuesday Feb 11th 2025


#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (true) 
	{
		string cardnum; //create string for card number and takes input for it
		do //Runs 
		{
			cout << "\nPlease enter the 8-digit credit card number (enter -1 to quit): ";
			cin >> cardnum;

			if (cardnum == "-1")  // Checks if user wants to quit
			{
				cout << "Thank you for using \"Credit Card Number Validation\"!" << endl; 
				return 0;
			}
		} while (cardnum.length() != 8); // Makes sure 8 digits are inputed or it repeats


		int odd = 0; 
		for (int i = 1; i < 7; i+=2)
		{
			odd += cardnum[i] - '0'; //Calculates sum of odd positions
		}
	
		int even = 0;
		for (int i = 0; i < 7; i += 2) //Calculates sum of even positions 
		{
			even += 2*(int(cardnum[i]) - '0') / 10; // Adds ones place digits
			even += 2*(int(cardnum[i]) - '0') % 10; // Adds tens place digits
		}

		int odd2 = 0; 
		for (int i = 1; i < 8; i+=2)
		{
			odd2 += cardnum[i] - '0'; //Calculates sum of odd positions
		}
	
		int even2 = 0;
		for (int i = 0; i < 8; i += 2) //Calculates sum of even positions 
		{
			even2 += 2*(int(cardnum[i]) - '0') / 10; // Adds ones place digits
			even2 += 2*(int(cardnum[i]) - '0') % 10; // Adds tens place digits
		}	

		int digit2 = odd2 + even2;
		int digit = odd + even; //Adds totals 
		cout << odd << endl;
		cout << even << endl;

		if (digit2 % 10 == 0) //Checks if totals end in 0, by dividing by 10 with a remainder
			{
			cout << "Number is valid" << endl;
			}
		else 
			{
			cout << "Number is invalid." << endl;
			int correction = ( 10 - (digit % 10)) % 10; //subtract remainder from 10 to get check digit
			cout << "Check digit should have been " << correction << endl;
			}

	
	}
	return 0;
}
