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

double final_score(double scores[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    { 
        sum = sum + scores[i];
    }

    double mean = sum/size;

    return mean; 

}





int main ()
{
double score[6];
int size = 0;
string input;


while (size < 6)
{
    cout << "Please enter your score for the gymnast:" << endl;
    getline(cin, input);
    stringstream ss(input);
    double ballot;

    if (ss >> ballot) // successfully read a number
    {
        if (ballot >= 0.0 && ballot <= 10.0)
        {
            score[size] = ballot;
            size++;
        }
        else
        {
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }
    }
    else
    {
        cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
    }
}

    
    cout << "The scores from the judges are:" << endl;

    for (int i = 0; i < 6; ++i)
    {
        cout << fixed << setprecision(2) << score[i] << " ";
    }
    cout << endl;

    cout << "The scores after dropping the highest and lowest scores:" << endl;
    int modified_size = 6;
    dropTWO(score, modified_size);
    
    for (int i = 0; i < modified_size; ++i)
    {
        cout << fixed << setprecision(2) << score[i] << " ";
    }
    cout << endl;

    cout << "Final Execution Score is: " << fixed << setprecision(2) << final_score(score, modified_size) << endl;

    return 0;
}