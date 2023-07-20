/**
 * Program       : A GPA calculator
 * File Name     : CommandCalc.h
 * Author        : Syrus Nelson
 * Last revision : 20 July 2023
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
    * Functions Called : menuInteract(), addCourseGPAs(), displayTotalGPA(), deleteGPA(), editGPA(),
    *                  :  importGPA(), writeToFile(), displayTranscript(), displayCredit(),
    *                  :  exit()
    */
   void sentinalFunction();

private:
   /**
    * Function         : void displayCredit();
    * Parameters       : none
    * Purpose          : To display the credit of this program
    * Pre-Condition    : Function is called in sentinalFunction()
    * Post-Condition   : Credit is displayed
    * Return Value     : void
    * Functions Called : none
    */
   void displayCredit();

   /**
    * Function         : void displayTranscript(GPATotal &gpaFunc);
    * Parameters       : gpaFunc which is used to grab the values for the transcript
    * Purpose          : To display the transcript
    * Pre-Condition    : Function is called in sentinalFunction()
    * Post-Condition   : Transcript is displayed
    * Return Value     : void
    * Functions Called : getCourses(), empty(), displayGPAs()
    */
   void displayTranscript(GPATotal &gpaFunc);

   /**
    * Function         : void importGPA(GPATotal &gpaFunc, string &optionHandler);
    * Parameters       : gpaFunc which is used to grab the values for the import
    *                  :  optionHandler which is used to handle the user's input
    * Purpose          : To import the GPAs
    * Pre-Condition    : Function is called in sentinalFunction()
    * Post-Condition   : GPAs are either imported or not
    * Return Value     : void
    * Functions Called : getCourses(), empty(), importFile()
    */
   void importGPA(GPATotal &gpaFunc, string &optionHandler);

   /**
    * Function         : int menuInteract(string &optionHandler, int &optionNum, CheckErr &check);
    * Parameters       : optionHandler which is used to handle the user's input
    *                  :  optionNum which is used to handle the number of the input
    *                  :  check which is used to check the input
    * Purpose          : To interact with the user on the menu
    * Pre-Condition    : Function is called in sentinalFunction()
    * Post-Condition   : User has entered their selection
    * Return Value     : int
    * Functions Called : checkInput(), stoi()
    */
   int menuInteract(string &optionHandler, int &optionNum, CheckErr &check);

   /**
    * Function         : int menuInteract(string &optionHandler, int &optionNum, CheckErr &check);
    * Parameters       : gpaFunc which is used to grab the values for the total GPA calculation
    * Purpose          : To display the total GPA
    * Pre-Condition    : Function is called in sentinalFunction()
    * Post-Condition   : The total GPA is displayed
    * Return Value     : void
    * Functions Called : getCourses(), empty(), getGPATotal()
    */
   void displayTotalGPA(GPATotal &gpaFunc);

   /**
    * Function         : void deleteGPA(GPATotal &gpaFunc, string &optionHandler, int &optionNum);
    * Parameters       : gpaFunc which is used to delete the GPA
    *                  :  optionHandler which is used to handle the user's input
    *                  :  optionNum which is used to handle the number of the input
    * Purpose          : To delete a course
    * Pre-Condition    : Function is called in sentinalFunction()
    * Post-Condition   : The course is deleted
    * Return Value     : void
    * Functions Called : getCourses(), empty(), displayGPAs(), isdigit(), at(), stoi(),
    *                  :  deleteCourse()
    */
   void deleteGPA(GPATotal &gpaFunc, string &optionHandler, int &optionNum);

   /**
    * Function         : void editGPA(GPATotal &gpaFunc, string &optionHandler, int &optionNum);
    * Parameters       : gpaFunc which is used to modify the GPA
    *                  :  optionHandler which is used to handle the user's input
    *                  :  optionNum which is used to handle the number of the input
    * Purpose          : To edit the specific course
    * Pre-Condition    : Function is called in sentinalFunction()
    * Post-Condition   : The course is revised
    * Return Value     : void
    * Functions Called : getCourses(), empty(), displayGPAs(), isdigit(), at(), stoi(),
    *                  :  editCourse()
    */
   void editGPA(GPATotal &gpaFunc, string &optionHandler, int &optionNum);
};