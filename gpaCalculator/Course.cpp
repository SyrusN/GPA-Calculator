/**
 * Program       : A GPA calculator
 * File Name     : Course.cpp
 * Author        : Syrus Nelson
 * Last revision : 23 March 2022
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "Course.h"
double Course::getGPA() const 
{
   return gpa_;
}
void Course::setGPA(const double gpaInput) 
{
   gpa_ = gpaInput;
}
int Course::getCredits() const 
{
   return credits_;
}
void Course::setCredits(const int creditInput) 
{
   credits_ = creditInput;
}
string Course::getDescription() const 
{
   return description_;
}
void Course::setDescription(const string descriptionInput) 
{
   description_ = descriptionInput;
}