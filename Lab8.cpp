/*course: CS215 - 401
 *Project: Lab 8 
 *Purpose: 
 *         
 *Author: Ben Allison
 */

#include <iostream>
#include <string>

using namespace std;


void dropTWO(double scores[], int& size) //Removes lowest and highest score
{
    sort(scores,scores + size); //Sorts scores in order
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


}

int main ()
{





return 0;
}