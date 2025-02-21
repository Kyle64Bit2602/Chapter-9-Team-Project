#pragma once
#include <string>
#include <iostream>

using namespace std;

inline void validate_int(int& varToValidate, string InvalidInputPhrase = "\nEnter a valid input: ", int min = INT_MIN, int max = INT_MAX)
{
    //Checks inputted int is valid

    while (true) {
        if (!(cin >> varToValidate) || varToValidate < min || varToValidate > max)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << InvalidInputPhrase;
        }
        else
        {
            return;
        }
    }
}

inline void validate_double(double& varToValidate, string InvalidInputPhrase = "\nEnter a valid input: ", double min = INT_MIN, double max = INT_MAX)
{
    //Checks inputted int is valid
    while (true) {
        if (!(cin >> varToValidate) || varToValidate < min || varToValidate > max)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << InvalidInputPhrase;
        }
        else
        {
            return;
        }
    }
}

inline void validate_char(char& varToValidate, char check1, char check2 = NULL, string InvalidInputPhrase = "\nEnter a valid input: ")
{
    while (true) {
        if (!(cin >> varToValidate) || (varToValidate != check1 && varToValidate != check2))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << InvalidInputPhrase;
        }
        else
        {
            return;
        }
    }
}

inline void validate_char_ranges(char& varToValidate, char range1[], char range2[], string InvalidInputPhrase = "\nEnter a valid input: ")
{
    bool valid = false;
    //Checks inputted int is valid
    do {
        cin >> varToValidate;
        if (cin.fail() || !(varToValidate >= range1[0] && varToValidate <= range1[1]) || !(varToValidate >= range2[0] && varToValidate <= range2[1]))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << InvalidInputPhrase;
        }
        else
        {
            valid = true;
        }
    } while (!valid);
    return;
}