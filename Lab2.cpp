// Ben Allison lab 2 CS 215
// Tuesday Jan 28th 2025

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{


    cout << "Convert CAD to USD service." << endl;
    cout << "Please enter amount of Canadian Dollars you want to exchange: C$"; //Input
    double cad = 0; //Storing Variable as double to work better with non-whole numbers
    cin >> cad; 

    double change = (cad*0.69);// converts to USD and defines Change, which is main variable for calculations below
    change = static_cast<int>(change *100 + 0.5)/100.0; // made change an int to avoid rounding erros

    cout << fixed << setprecision(2); //set at 2 decimals to clean up 
    cout << "The exchange for C$" << cad << " --> $" << change << " :" << endl;


    int dollar = static_cast<int>(change/1); //Getting Dollars in whole numbers with no rounding
    change -= dollar*1; // added *1 because it broke without it for me. no idea why. if this comment is deleted it might mess it up for all I know
    int quarter = static_cast<int>(change/0.25); //get quarters from remaining change
    change -= quarter*0.25; //remove quarters taken 
    int dime = static_cast<int>(change/0.1); //get dimes from remaining change and + the .05 to avoid rounding error
    change -= dime*0.1; //remove dimes
    int nickle = static_cast<int>(change/0.05 + 0.05); //get nickles from change added + .05 to fix rounding error
    change -= nickle*0.05; //remove nickles
    int penny = static_cast<int>(change/0.01+0.5); //get pennies //added .5 to fix rounding error
    cout <<"Dollars: "<<dollar<< endl;; 
    cout <<"Quarters: "<<quarter<< endl;;
    cout <<"Dimes: "<<dime<< endl;;
    cout <<"Nickles: "<<nickle<< endl;;
    cout <<"Pennies: "<<penny<< endl;;



    return 0;
}