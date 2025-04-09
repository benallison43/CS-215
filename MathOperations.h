/* File: MathOperations.h
 * Course: CS215-00x
 * Project: Lab 9 (first part of Project 2)
 * Purpose: to declare the class named MathOperations
 * Author: (your name)
 */

#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAXDIGITS = 4;
const char DivisionSymbol = char(246);  // ASCII for ÷

class MathOperations
{
public:
    MathOperations();

    void setOperands(int op1, int op2);
    char getOperator() const;
    int getAnswer() const;

    void Addition();
    void Subtraction();
    void Multiplication();
    void Division();

    bool checkAnswer(int response) const;

    void print() const;

    int collectUserAnswer() const;

private:
    int operand1;
    int operand2;
    char theoperator;
    int answer;
};

#endif /* MATHOPERATIONS_H */












/* I accidentlly did both MathOperations.cpp and .h in the same file.
    I left the code below to copy and paste over and edit if needed



#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAXDIGITS = 4;    // the maximum digits of operands or answers
const char DivisionSymbol = char(246);      // ASCII code for "÷"

class MathOperations
{
public:
    // default constructor
    MathOperations()
    {
        operand1 = 1;
        operand2 = 0;
        theoperator = ' ';
        answer = 0; 
    }

    // set the private data members: operand1 and operand2
    // to op1 and op2 respectively
    void setOperands(int op1, int op2)
    {
        operand1 = op1;
        operand2 = op2;
    }

    // get the current value of the private data member: theoperator
    char getOperator() const
    {
        return theoperator;
    }

    // return the value of the data member: answer
    int getAnswer() const
    {
        return answer;
    }

    // set theoperator to '+'
    // apply the addition operation to operand1 and operand2
    // set the answer equal to operand1 + operand2
    void Addition()
    {
        theoperator = '+';
        answer = operand1 + operand2;
    }
        

    // set theoperator to '-'
    // apply the subtraction operation to operand1 and operand2
    // set the answer equal to operand1 - operand2
    void Subtraction()
    {
        theoperator = '-';
        answer = operand1 - operand2;
    }

    // set theoperator to '*'
    // apply the multiplication operation to operand1 and operand2
    // set the answer equal to operand1 * operand2
    void Multiplication()
    {
        theoperator = '*';
        answer = operand1 * operand2;
    }


    // set theoperator to const DivisionSymbol, it is ASCII code for obelus
    // apply the division operation to operand1 and operand2
    // set the answer equal to operand1 ÷ operand2
    void Division()
    {
        theoperator = '/';
        answer = operand1 / operand2;
    }

    // if answer == response, it returns true
    // otherwise it returns false
    bool checkAnswer(int response) const
    {
        return (answer == response);
    }

    //display the question in the format described in the problem statement
    // for example:
    //    135
    //  +  78
    //  _____
    //
    void print() const
    {
        cout << setw(MAXDIGITS+1) << operand1 << endl;
        cout << " " << theoperator << setw(MAXDIGITS-1) << operand2 << endl;
        cout << " ";
        for (int i = 0; i < MAXDIGITS+1; i++)
        {
            cout << "-";
        }

        cout << endl;
    }

    // display the question by calling print() first
    // then ask the user for the answer
    // it returns the valid user answer collected from the user input
    int collectUserAnswer() const
    {
    print();
    int response;

    while (true)
    {
        cout << "Please type your answer: " << flush;
        cin >> response;
        if (cin.fail()) // check if input failed
        {
         cout << "Invalid input! Please try again..." << endl;
            cin.clear(); // clear the error state
    
        }
        else if (response >= 0.0 && response <= 10000.0)
        {
            cin.ignore(1000, '\n');
            break;
        }
        else
        {
            cout << "Invalid input! Please try again..." << endl;
        }
        cin.ignore(1000, '\n'); // discard anything left on the line
        
        //Code I had before it kept failing on a not fail
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please try again..." << endl;
        }
        else
            break;
     
        
    
    }
    return response;
    }

private:
    int operand1;  // the first operand for basic math operation
    int operand2;  // the second operand for basic math operation
    char theoperator; // the current operator;
    int answer;    // the correct answer
};

#endif MATHOPERATIONS_H */




