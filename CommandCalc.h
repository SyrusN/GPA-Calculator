/**
 * Program       : A GPA calculator
 * File Name     : CommandCalc.h
 * Author        : Syrus Nelson
 * Last revision : 12 January 2023
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "GPATotal.h"
class CommandCalc
{
public:
   /**
    * Function         : void sentinalFunction();
    * Parameters       : total which is the singleton object
    * Purpose          : To act as the main function behind the driver method (main())
    * Pre-Condition    : Program has started and this function is called in main()
    * Post-Condition   : Program has ended
    * Return Value     : void
    * Functions Called : stoi(), addCourseGPAs(), getGPATotal(), displayGPAs(), isdigit(), at(),
    *                  :  deleteCourse(), editCourse(), importFile(), writeToFile(), displayGPAs(),
    *                  :  exit()
    */
   void sentinalFunction();
};