// Ben Allison lab 4 CS 215
// Tuesday Feb 11th 2025


#include <iostream>
#include <string>

using namespace std;

int main()
{

	string creditcardnum;

	cout << "Please enter the 8-digit credit card number: ";
	cin >> creditcardnum;

	int step1 = 0;

	for (int i = 1; i < 8; i+=2)
	{
		step1 += int(creditcardnum[i]) - 48;
	}
	int step2 = 0;
	for (int i = 0; i < 8; i += 2)
	{
		step2 += 2*(int(creditcardnum[i]) - 48) / 10;
		step2 += 2*(int(creditcardnum[i]) - 48) % 10;
	}

	int digitcheck = step1 + step2;
	int newdigitcheck = int(creditcardnum[creditcardnum.size()-1]) - 48;

	if (digitcheck % 10 == 0)
	{
		cout << "Number is valid" << endl;
	}
	else 
	{
		cout << "Number is invalid." << endl;
		int right = (newdigitcheck + ( 10 - digitcheck % 10)) % 10;
		cout << "Check digit should have been " << right << endl;
	}

	system("pause");
	return 0;
}