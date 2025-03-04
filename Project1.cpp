/*course: CS215 - 401
 *Project: Project 1
 *Author: Ben Allison
 */


#include <iostream>
#include <string>

using namespace std;


//Functions are imported in from Lab 6
//Turns a digit into a Roman numeral
string roman_digit(int digit, string one, string five, string ten)
{
    switch (digit) //Same switch case as last lab
    {

        //Runs a seperate case for every number 0-9 no matter how big overall number my be, as it will all be broken up
        case 0:
            return ""; //Blank due to it being 0 and returning nothing. 
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
            return ""; //Returns nothing as default is needed for function properly
    }

}

    //Returns a string form of a Roman Numeral.
    //(n must be between 1 and 3999)
string roman_numeral(int n)
{
    //Breaks up the main number into individual places to work
    int thousands = n / 1000; //Take thousands place
    int hundreds = (n % 1000) / 100; //Take hundreds place
    int tens = (n % 100) / 10; //Take tens place
    int ones = n % 10; //Take ones place


    //Strings with one, five, and ten value for each digit as each will add and subtract from those to form the numerals
    //Calls previously defined function and has sub values needed to work for each number
    string roman_thousand = roman_digit(thousands, "M","", ""); //2 blank spots are there due to cap of numerals
    string roman_hundred = roman_digit(hundreds, "C", "D", "M");
    string roman_ten = roman_digit(tens, "X","L","C");
    string roman_one = roman_digit(ones,"I","V","X");

    return roman_thousand + roman_hundred + roman_ten + roman_one; //Adds everything together to form roman numeral

}
