/*course: CS215 - 401
 *Project: Lab 8 
 *Purpose: 
 *         
 *Author: Ben Allison
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream> 
using namespace std;


void dropTWO(double scores[], int& size) //Removes lowest and highest score
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
         {
            if (scores[j] > scores[j + 1]) 
            {
                // Swap the elements
                double temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
    int remove_end = size;

    for (int i = 0; i < size - 1; ++i) //Remove starting value
    {
        scores[i] = scores[i+1];
    }
    size--; //adjusts size after removing first value

    size--; //removes largest value
}

double final_score(double scores[], int size) //Calculates Average
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    { 
        sum = sum + scores[i]; //Adds each number to the sum
    }

    double mean = sum/size; //divides sum by the total number leaving the average

    return mean; 

}





int main ()
{
//Define Varibles
double score[6];
int size = 0;
string input;


while (size < 6) //Main command to run at least 6 times but will repeat if an incorrect input is put in. 
{
    cout << "Please enter your score for the gymnast:" << endl; //Takes entire line
    getline(cin, input);
    stringstream ss(input);
    double ballot;

    if (ss >> ballot) // successfully read a number and blocks out non number values with stream string
    {
        if (ballot >= 0.0 && ballot <= 10.0) //If there is a 
        {
            score[size] = ballot;
            size++; //Adds to count for while loop to end
        }
        else //Rejects input that doesn't start with the double
        {
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }
    }
    else //Rejects input that doesn't start with the double
    {
        cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
    }
}

    
    cout << "The scores from the judges are:" << endl;

    for (int i = 0; i < 6; ++i) //produces each judge score
    {
        cout << fixed << setprecision(2) << score[i] << " ";
    }
    cout << endl;

    cout << "The scores after dropping the highest and lowest scores:" << endl;
    int modified_size = 6;
    dropTWO(score, modified_size); //runs function and produces new scores
    
    for (int i = 0; i < modified_size; ++i) //displays modified scores
    {
        cout << fixed << setprecision(2) << score[i] << " ";
    }
    cout << endl;
    //Produces final line with everything intact
    cout << "Final Execution Score is: " << fixed << setprecision(2) << final_score(score, modified_size) << endl;

    return 0;
}