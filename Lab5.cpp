/*course: CS215 - 00x
 *Project: Lab 5
 *Purpose: First, it converts a sequence of numbers to its corresponding Roman Numerals
 *         Second, it repeatedly asks the user to input a triangle size until the user enters "Q" or "q" to quit the program
 *                 then displays a triangles using stars (asterisk symbol) and the total rows of stars is equal to the user input size, say n.
 *                 (The triangle contains one star at the first line, three little stars at the second line, and so on till 2*n-1 stars at the nth line, and it is symmetric.)
 *                 it displays the original triangle then roates the triangle 90-degree clockwise
 *
 *Author: Benjamin Allison
 */

#include <iostream>
#include <iomanip>
#include <limits>       // define numeric_limits
#include <cmath>        // define pow function

using namespace std;

// The compiler needs to see at least function prototype before the function can be called

// It turns a digit into a Roman numeral
/*string roman_digit(int digit, string one, string five, string ten) */
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
            return "";
    }

}

//Returns a string form of a Roman Numeral.
//(n must be between 1 and 3999)
string roman_numeral(int n)
{
 
    int tens = (n % 100) / 10; //Take tens place
    int ones = n % 10; //Take ones place

    
    string roman_ten = roman_digit(tens, "X","L","C");
    string roman_one = roman_digit(ones,"I","V","X");

    return roman_ten + roman_one; //Adds everything together to form roman numeral

}
// It returns a string form of a Roman Numeral.
// (n must be between 1 and 3999)
/*string roman_numeral(int n);*/

// It prints a triangle of n rows of asterisk, center alignment
// starting with one asterisk at the first row, three at the second row...

void printTri(int n)
{
    for (int i =1; i <= n; i++) //runs as many times as inputed
    {
        for (int space = 0; space < n - i; space++) // loop to add spaces seperate from stars
        {
            cout << " "; 
        }
        for (int star = 0; star < (2*i -1); star++) // adds stars in increasing order
        {
            cout << "*"; 
        }
        cout << endl; // goes down to next line
    }
}
// It prints a triangle of asterisk
// It rotates the pattern from printTri function, 90-degree clockwise
void printTriR90(int n)
{
    for (int stars = 0; stars <= n; stars++)
    {
        for (int j=0; j < stars; j++) //adds stars in increasing order
        {
            cout<<"*";
        }
        cout << endl; //skips line every time stars are outputed and creates triangle
    }

    for (int i= n-1; i > 0; i--) // does same as top for loop above but goes at a decreasing order
    {
        for (int j = 0; j < i; j++) //adds stars but decreasing every time
        {
            cout<<"*";
        }
        cout << endl; //once again gives triangle its shape but skipping down lines
    }



}

int main()
{
    const int START = 0;      // The minimum exponent
    const int END = 12;       // The maximum exponent
    const int BASE = 2;       // The base for the power function
    const int WIDTH = 10;     // formatted layout purpose: as WIDTH wide

    cout << "\tWelcome to CS215 Roman Numeral Converter!" << endl;
    cout << "\tDecimal\t\tRoman Numerals" << endl;

    for (int i = 1; i <= 99; i++) //Loop to run roman numeral function over and over till numbers 1-99 are shown
    {
        cout << setw(10) << right << i << "  -->  " << setw(10) << roman_numeral(i) << endl;
    }

    while (true) //repeats till program is quitted by q or crtl+c 
    {   
        cout << "Enter the size of your triangle (integer in [1,70])" << endl;
        cout << "Type Q to quit program: "; 

        //declares variables
        char input;
        int size;

        cin >> input; //input

        if (input == 'Q' || input == 'q') //quits program and ends while loop
        {
            cout << "Thank you, have a great day!" << endl;
            return 0; 
        }
        cin.putback(input);//Fixes Issue when program repeats in while loop


        if (!(cin>>size) || size < 1 || size > 70) //Makes sure it is in range
        {
        cout << "The size is not in the correct range!" << endl;
        // Clear error flags
        cin.clear();
        // Ignore rest of the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        // Clear any leftover characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "The triangle with size " << size << " (ROMAN NUMBER: " << roman_numeral(size) << " ) is: "<< endl;
        printTri(size); //executes functions defined above
        cout << "The rotation for 90 degrees clockwise:" << endl;
        printTriR90(size); //executes functions defined above
        
    }
    // complete the following block of code
    // to display the sequence of numbers in the range: (BASE to the power of START, BASE to the power of END)
    // at each line: one number      -->     its Roman Numeral
    // your code starts here...
    return 0;
}