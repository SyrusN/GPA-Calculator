/**
 * Program       : A GPA calculator
 * File Name     : CheckErr.h
 * Author        : Syrus Nelson
 * Last revision : 12 January 2023
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class CheckErr
{
   // Allow access
public:
   /**
    * Function         : int checkInput(string *input, const int maxInputSize, const string errorMessage);
    * Parameters       : input which is to be checked, maxInputSize which is the max chars/digits, errorMessage
    *                  :  which is the corresponding error message.
    * Purpose          : To check for any invalid input that would cause the program to crash
    * Pre-Condition    : The user has input some value
    * Post-Condition   : The input is validated, otherwise the corresponding error message is displayed
    *                  :  and the program asks the user to re-enter a valid value
    * Return Value     : void
    * Functions Called : size(), isalpha()
    */
   int checkInput(string *input, const int maxInputSize, const string errorMessage);

   /**
    * Function         : int checkValue(string *input, const double minValue, const double maxValue, const string errorMessage);
    * Parameters       : input which is to be checked, minValue which is the minimum input value, maxValue which is the maximum
    *                  :  input value, errorMessage which is the corresponding error message
    * Purpose          : To check for any invalid input beyond the bounds of the intended use
    * Pre-Condition    : The user has input some value
    * Post-Condition   : The input is validated, otherwise the corresponding error message is displayed
    *                  :  and the program asks the user to re-enter a valid value
    * Return Value     : void
    * Functions Called : stod()
    */
   int checkValue(string *input, const double minValue, const double maxValue, const string errorMessage);
};