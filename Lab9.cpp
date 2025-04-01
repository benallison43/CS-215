

#include <iostream>   
#include <iomanip>
#include <string>
#include <vector>
#include "FinalGrade.h"

using namespace std;

double calculateGradebook(const vector<FinalGrade>& gradebook, double& max_score, double& min_score)
{
    double total = 0;
    max_score = gradebook[0].getScore();
    min_score = gradebook[0].getScore();

    for (int i = 0; i < gradebook.size(); i++)
    {
        double score = gradebook[i].getScore();
        total += score; 


        if (score > max_score) max_score = score;
        if (score < min_score) min_score = score;
    }

    return total / gradebook.size();
}



