// File: MathOperations.cpp
#include "MathOperations.h"

// Default constructor
MathOperations::MathOperations()
{
    operand1 = 1;
    operand2 = 0;
    theoperator = ' ';
    answer = 0;
}

void MathOperations::setOperands(int op1, int op2)
{
    operand1 = op1;
    operand2 = op2;
}

char MathOperations::getOperator() const
{
    return theoperator;
}

int MathOperations::getAnswer() const
{
    return answer;
}

void MathOperations::Addition()
{
    theoperator = '+';
    answer = operand1 + operand2;
}

void MathOperations::Subtraction()
{
    theoperator = '-';
    answer = operand1 - operand2;
}

void MathOperations::Multiplication()
{
    theoperator = '*';
    answer = operand1 * operand2;
}

void MathOperations::Division()
{
    theoperator = '/';
    answer = operand1 / operand2;
}

bool MathOperations::checkAnswer(int response) const
{
    return (answer == response);
}

void MathOperations::print() const
{
    cout << setw(MAXDIGITS + 1) << operand1 << endl;
    cout << " " << theoperator << setw(MAXDIGITS - 1) << operand2 << endl;
    cout << " ";
    for (int i = 0; i < MAXDIGITS + 1; i++)
    {
        cout << "-";
    }
    cout << endl;
}

int MathOperations::collectUserAnswer() const
{
    print();
    int response;

    while (true)
    {
        cout << "Please type your answer: " << flush;
        cin >> response;

        if (cin.fail()) //Input validation
        {
            cout << "Invalid input! Please try again..." << endl;
            cin.clear();
        }
        else if (response >= 0.0 && response <= 10000.0) //If extra input after correct response it ignores and doesn't error it
        {
            cin.ignore(1000, '\n');
            break;
        }
        else
        {
            cout << "Invalid input! Please try again..." << endl;
        }
        cin.ignore(1000, '\n');
    }

    return response;
}
