// Ben Allison lab 1 CS 215
// Tuesday Jan 21st 2025

#include <iostream>

using namespace std;

int main() 
{
       cout << "Hello, Willow and Maryam" << endl;; 
       cout << "My name is Ben. Nice to meet you! \n" << endl;;

       cout <<" %%%%%%%%%%%%%%%%%" << endl;; //Curly Hair
       cout <<" |               |" << endl;; //Forehead
       cout <<" |    .     .    |" << endl;; //Eyes
       cout <<" |       .       |" << endl;; //Nose
       cout <<" |    \\_____/    |" << endl;; //Smile with '\\' to appear only one '\' as it is an escape command
       cout <<" |_______________| \n" << endl;;
       



    cout << "Please enter amount due: $ "; //Input
    double due = 0; //Storing Variable as double to work better with numbers
    cin >> due; 

    cout << "Please enter amount received: $ "; //Input
    double received = 0; //Storing Variable as double to work better with numbers
    cin >> received; 

    double change = received - due; // Change which is main variable 

    int dollar = static_cast<int>(change/1); //Getting Dollars in whole numbers with no rounding
    change -= dollar*1; // added *1 because it broke without it for me. no idea why. if this comment is deleted it might mess it up for all I know
    int quarter = static_cast<int>(change/0.25); //get quarters from remaining change
    change -= quarter*0.25; //remove quarters taken 
    int dime = static_cast<int>(change/0.1); //get dimes from remaining change
    change -= dime*0.1; //remove dimes
    int nickle = static_cast<int>(change/0.05); //get nickles from change
    change -= nickle*0.05; //remove nickles
    int penny = static_cast<int>(change/0.01+0.5); //get pennies //added .5 to fix rounding error
    cout <<"The change is: "<< endl;; //Print starting line nad below is printing how much is returned of each coin
    cout <<"Dollars: "<<dollar<< endl;; 
    cout <<"Quarters: "<<quarter<< endl;;
    cout <<"Dimes: "<<dime<< endl;;
    cout <<"Nickles: "<<nickle<< endl;;
    cout <<"Pennies: "<<penny<< endl;;
    
    


    return 0; // End Program
}
