// Ben Allison lab 3 CS 215
// Tuesday Feb 4th 2025

#include <iostream>

using namespace std;

int main ()
{
    cout << "Your Wish is my command" << endl;
    cout << "I will sort three numbers under your wish:" << endl;
    cout << "Enter 'I' for increasing order, 'D' for decreasing order ( I or D ): " << endl;
    char magic_letter; //Saved as char because that is the only value I will be working with it 
    cin >> magic_letter; //Takes in letter for increasing or decreasing 

    //Makes sure input is letter 'i' or 'd' 
    if (magic_letter == 'i')
    {
       magic_letter = 'I' ; //Fixes case
    }
    else if (magic_letter == 'd')
    {
        magic_letter = 'D'; //Fixes case
    }
    else if (magic_letter == 'I')
    {
        // already uppercase 
    }
    else if (magic_letter == 'D')
    {
        // already uppercase 
    }
    else  // Rejects any value that isn't i or d and ends program
    {
        cout << "Invalid choice, quitting the program..." << endl;
        return 0;
    }

    cout << "Please enter 3 integer numbers: ";
    //Saving as A,B, and C because variables are unknown 
    int A;
    int B;
    int C;
    cin >> A >> B >> C; //Input command

    //Sorts them in order using if statements 
    if (A>B) 
    {
        int temp =A;
        A=B;            //Swaps places to be in order
        B= temp;
    }
    if ( A>C)
    {
        int temp =A;
        A = C;
        C = temp;
    }
    if (B>C)
    {
        int temp = B;
        B = C;
        C = temp;
    }
    
    //After it is sorted, the code below puts it in order depending on increasing or decreasing was inputted

    if (magic_letter == 'I')
        {
            cout << "Numbers are sorted in increasing order: " << endl;
            cout << A << " --> " << B << " --> " << C << endl;
                if  (A == B||A==C||B==C)                //((B == A+1) && (C == B+1))
                {           //defines if numbers are in a certain order or not and tells user
                    cout << "Numbers are in leniently increasing order !" << endl;
                    return 0;
                 }
                else
                {         
                     cout << "Numbers are in strictly increasing order !" << endl;
                     return 0;
                }
        }       
        //Same as for i above but now for d
    if (magic_letter == 'D')
        {
            cout << "Numbers are sorted in decreasing order: " << endl;
            cout << C << " <-- " << B << " <-- " << A << endl;
        }

                if (A == B||A==C||B==C)             //((B == C-1) && (A == B-1))
                  {             //defines if numbers are in a certain order or not and tells user
                       cout << "Numbers are in  leniently decreasing order !" << endl;
                  }
                  else
                   {
                      cout << "Numbers are in strictly decreasing order !" << endl;
                  }
    return 0;

}