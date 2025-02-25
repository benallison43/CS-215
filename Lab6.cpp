/*course: CS215 - 401
 *Project: Lab 6 (As part of Project 1)
 *Purpose: Display the year of Super Bowl in Roman Numeral Representation
 *         The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)
 *         For testing purpose, this program displays the Super Bowls in two-group of 50 years
 *         (1) from year 2000 to year 2049;
 *         (2) from year 5916 to year 5965.
 *Author: Ben Allison
 */
#include <iostream>
#include <string>

using namespace std;

//Turns a digit into a Roman numeral
string roman_digit(int digit, string one, string five, string ten)
{
    switch (digit) 
    {
        case 0:
            return "";
        case 1:
            return one;
        case 2:
            return one + one;
        case 3:
            return one + one + one;
        case 4:
            return one + five;
        case 5:
            return five;
        case 6:
            return five + one;
        case 7:
            return five + one + one;
        case 8:
            return five + one + one + one;
        case 9:
            return one + ten;
        default:
            return "";
    }

}

//Returns a string form of a Roman Numeral.
//(n must be between 1 and 3999)
string roman_numeral(int n)
{
    int thousands = n / 1000; //Take thousands place
    int hundreds = (n % 1000) / 100; //Take hundreds place
    int tens = (n % 100) / 10; //Take tens place
    int ones = n % 10; //Take ones place

    string roman_thousand = roman_digit(thousands, "M","", "");
    string roman_hundred = roman_digit(hundreds, "C", "D", "M");
    string roman_ten = roman_digit(tens, "X","L","C");
    string roman_one = roman_digit(ones,"I","V","X");

    return roman_thousand + roman_hundred + roman_ten + roman_one;

}


int main()
{
    const int START_SUPERBOWL = 1967;  // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum) 
    const int FIRST_START = 2000;      // The first group displays Super Bowl starting in year 2000
    const int FIRST_END = 2049;        // The first group displays Super Bowl ending in year 2099
    const int SECOND_START = 5916;     // The second group displays Super Bowl starting in year 5616
    const int SECOND_END = 5965;       // The second group displays Super Bowl ending in year 5965
                                       
                                       // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    // The last Super Bowl which can be represented by Roman Numerals would be: START_SUPERBOWL + MAX_ROMAN - 1;
    const int GROUP = 10;                  // Layout the years in a group of 10

    cout << endl << "\t\t\tSuper Bowl Records" << endl;
    cout << "The first Super Bowl was hold at Los Angeles Memorial Coliseum on January 15, " << START_SUPERBOWL << endl;
    cout << "\tYear\t\tSuper Bowl" << endl;

    // display one group of 50 years of Super Bowl, starting at year 2000 to year 2049
    for (int i = FIRST_START; i <= FIRST_END; i++)
    {
        int year = i - START_SUPERBOWL + 1;
        if (i % GROUP == 0)
            cout << endl << "************************************" << endl << endl;
        cout << "\t" << i << "\t--->\t" << roman_numeral(year) << endl;
    }

    // display another group of 50 years of Super Bowl, starting at year 5916 to year 5965
    cout << endl << endl;
    cout << "Please step into the TIME Machine, aboard this flight, into the future..." << endl;
    cout << "\tYear\t\tSuper Bowl" << endl;
    for (int i = SECOND_START; i <= SECOND_END; i++)
    {
        int year = i - START_SUPERBOWL + 1;
        if (i % GROUP == 0)
            cout << endl << "************************************" << endl << endl;
        cout << "\t" << i << "\t--->\t" << roman_numeral(year) << endl;
    }

    return 0;
}

