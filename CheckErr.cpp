/**
 * Program       : A GPA calculator
 * File Name     : CheckErr.cpp
 * Author        : Syrus Nelson
 * Last revision : 12 January 2023
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "CheckErr.h"
int CheckErr::checkInput(string *input, const int maxInputSize, const string errorMessage)
{
   if ((*input).size() > maxInputSize)
   {
      cout << errorMessage << '\n'
           << endl;
      *input = "";
      return -1;
   }
   for (int character = 0; character < (*input).size(); character++)
   {
      if (isalpha((*input)[character]))
      {
         cout << errorMessage << endl;
         *input = "";
         return -1;
      }
   }

   return 1;
}
int CheckErr::checkValue(string *input, const double minValue, const double maxValue, const string errorMessage)
{
   double inputVal = std::stod(*input);
   if (inputVal > maxValue || inputVal < minValue)
   {
      cout << errorMessage << endl;
      *input = "";
      return -1;
   }

   return 1;
}