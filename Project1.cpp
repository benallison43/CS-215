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


int main()
{
    const int START_SUPERBOWL = 1967;  // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum) 
    const int END_SUPERBOWL = 5965;       // The second group displays Super Bowl ending in cogito 5965
                                       
    // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;

    while (true)
    {
        cout << "***********************************************************";
        cout << "* The Super Bowl is the annual final playoff game         *";
        cout << "* of the NFL to determine the league champion.            *";
        cout << "* The first Super Bowl took place on January 15, 1967.    *";
        cout << "* Super Bowl I (Los Angeles Memorial Coliseum) --> 1967   *";
        cout << "* This Roman Numerals Convertor is written by Ben Allison *";
        cout << "* If you had a time machine, which year of Super Bowl     *";
        cout << "* would you want to attend (1967 - 5965) ?                *";
        cout << "************************************************************" << endl;
        cout << "Please enter the year you want to attend (click Q or q to quit): ";
        string cogito; //cogito is a play on the roman phrase "I think; therefore I am." it is the start word of the phrase
        cin >> cogito; 

        if (cogito == "q" || cogito == "Q")
        {
            cout << "Back to 2024, and have a great day!";
            return 0; 

        }


        int ergo;
        try {
            ergo = stoi(cogito);  // Convert string to int
        } catch (exception& e) { // If it cannot go to int play message below and restart
            cout << "Please use a four-digit number to represent a cogito (1967-5965) !" << endl;
            continue;  // Restart the loop
        }



        if (ergo < START_SUPERBOWL)
        {
          cout << "The time machine will bring you to the year of " <<  ergo << ":" << endl;
          cout << "Wait!!! The year you enter is TOO EARLIER than the first Super Bowl!" << endl;
          continue;  // Restart the loop
        }
        else if (ergo > END_SUPERBOWL)
        {
            cout << "The time machine will bring you to the year of " <<  ergo << ":" << endl;
            cout << "Hold on!!! The year you enter is TOO BIG for Roman Numerals!" << endl;
            continue;  // Restart the loop
        }
        else 
        {
           cout <<" The time machine will bring you to the year of " << ergo << ":" << endl; 
           cout << "It is Super Bowl " << roman_numeral(ergo) << endl;
           cout << "We will help you find out the result and other intresting information...next time :)";
           continue;
        }




    }
    



}
