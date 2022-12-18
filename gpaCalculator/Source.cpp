/**
 * Program       : A GPA calculator
 * File Name     : Source.cpp
 * Author        : Syrus Nelson
 * Last revision : 6 April 2022
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "GPATotal.h"

/**
 * Function         : int main();
 * Parameters       : None
 * Purpose          : To act as the driver method for the entire program
 * Pre-Condition    : Program is started by the user
 * Post-Condition   : Program has ended and any unsaved data is lost
 * Return Value     : int
 * Functions Called : sentinalFunction()
 */
int main() 
{
   GPATotal total;
   total.sentinalFunction();
}
