/*
 *Course: CS215-00x
 *Project: Lab 9
 *Purpose: to implement a Gradebook Report
 *         it allows the user to input students' scores
 *         until the user types "q" or "Q" to quit
 *         then displays all the valid scores from user input
 *                       and the corresponding letter grades;
 *                       the average score, highest score and lowest score.
 *Author: (your name)
 */

#include <iostream>   
#include <iomanip>
#include <string>
#include <vector>
#include "FinalGrade.h"

using namespace std;

 FinalGrade::FinalGrade()
{
    score = 0;
}

    // constructor: give the initial value to the private data member score 
    // to pass-in parameter in_score
FinalGrade::FinalGrade(double in_score)
{
    score=in_score;
}

    // set the private data member: score
    // to pass-in parameter in_score
void FinalGrade::setScore(double in_score)
{
    score=in_score;
}

    // return the value of the data member: score
double FinalGrade::getScore() const
{
    return score;
}

    // return the corresponding letter grade from score
    // based on the grading policy in CS215 syllabus
char FinalGrade::decideLetterGrade() const
{
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'E';
}

    // print the score and letter grade in the format: (for example)
    // Score: 88.00        Letter Grade: B
void FinalGrade::print() const
{
    cout << fixed << setprecision(2);
    cout << "Score: "<< setw(7) << score << "       Letter Grade: " << decideLetterGrade() << endl;
}




double calculateGradebook(const vector<FinalGrade>& gradebook, double& max_score, double& min_score);

int main()
{
    vector<FinalGrade> CS215gradebook;
    double input_score;

    while (true)
    {
        cout << "Please enter a score for CS215 (type 'Q' or 'q' to quit): " << endl;
        cin >> input_score;
        cin.ignore(256, '\n');

        // check if the user input is invalid
        if (cin.fail())
        {
            string check_input;
            cin.clear();
            cin >> check_input;
            cin.ignore(256, '\n');
            if (check_input == "Q" || check_input == "q")
                break;
            else {
                cout << "Invalid input, please try again..." << endl;
                continue;
            }
        }

        // check if the input score is in the correct range: [0,100]
        if (input_score < 0 || input_score > 100)
        {
            cout << "The score is not in the correct range, please try again..." << endl;
        }
        else  // valid user input, store into gradeList object
        {
            FinalGrade inputFG(input_score);
            CS215gradebook.push_back(inputFG);
        }
    }

    // Check if the gradebook is empty
    // If it is empty, report it then quit the program
    if (CS215gradebook.size() == 0)
    {
        cout << "The gradebook for CS215 is empty!" << endl;
        return 1;
    }

    // if the gradebook is not empty
    // Display each score and corresponding letter grade in the grade    
    // Display the average score, the highest and lowest scores from the gradebook
    cout << endl << endl;
    cout << "The gradebook for CS215:" << endl;
    for (int i = 0; i < CS215gradebook.size(); i++)
    {
        CS215gradebook[i].print();
    }

    double max_score = 0;
    double min_score = 0;
    double average = 0;
    average = calculateGradebook(CS215gradebook, max_score, min_score);
    cout << fixed << setprecision(2);
    cout << "The average score is: " << average << endl;
    cout << "The highest score is: " << max_score << endl;
    cout << "The lowest score is: " << min_score << endl;
    return 0;
}

/*
 * it finds the highest score and lowest score of the gradebook
 *    then returns the average score from the gradebook
 *@para gradebook vector<FinalGrade>: the vector of FinalGrade objects to represent the gradebook (const call by reference for efficiency and safety purpose)
 *@para max_score double (call by reference): stores the highest score in the gradebook
 *@para min_score double (call by reference): stores the lowest score in the gradebook
 *@return double: the average score from the gradebook
 */


