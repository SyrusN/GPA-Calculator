/**
 * Program       : A GPA calculator
 * File Name     : Source.cpp
 * Author        : Syrus Nelson
 * Last revision : 23 March 2022
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "GPATotal.h"
/**
 * Function         : void sentinalFunction(GPATotal& total);
 * Parameters       : total which is the object used throughout the program
 * Purpose          : To act as the main function behind the driver method (main())
 * Pre-Condition    : Program has started and this function is called in main()
 * Post-Condition   : Program has ended
 * Return Value     : void
 * Functions Called : stoi(), addCourseGPAs(), getGPATotal(), displayGPAs(), isdigit(), at(),
 *                  :  deleteCourse(), editCourse(), importFile(), writeToFile(), displayGPAs(),
 *                  :  exit()
 */
void sentinalFunction(GPATotal& total);

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
   sentinalFunction(total);
}
void sentinalFunction(GPATotal& total) {
   string optionHandler;
   int optionNum;
   char optionChar;
   
   //This loop is to keep the session going for the user to continue interaction
   while (1 == 1) {
      cout << "Enter an option from 1 - 8" << endl;
      cout << "1 - Enter course GPAs" << endl;
      cout << "2 - Get the total GPA" << endl;
      cout << "3 - Delete an entry" << endl;
      cout << "4 - Edit an entry" << endl;
      cout << "5 - Import GPAs" << endl;
      cout << "6 - Export GPAs" << endl;
      cout << "7 - Output unofficial transcript" << endl;
      cout << "8 - Exit" << endl;

      cin >> optionHandler;
      optionNum = std::stoi(optionHandler);
      
      switch (optionNum) {
      case 1:
      {
         total.addCourseGPAs();
         break;
      }
      case 2:
         cout << "GPA: " << total.getGPATotal() << endl;
         break;
      case 3:
         deletion:
         total.displayGPAs();
         cout << "Choose a course to delete by its number" << endl;
         cin >> optionHandler;
         
         if (!std::isdigit(optionHandler.at(0))) {
            cout << "Please enter a valid course number." << endl;
            goto deletion;
         }

         optionNum = std::stoi(optionHandler);
         total.deleteCourse(optionNum);
         break;
      case 4:
         revision:
         total.displayGPAs();
         cout << "Choose a course to edit by its number" << endl;
         cin >> optionHandler;
         
         if (!std::isdigit(optionHandler.at(0))) {
            cout << "Please enter a valid course number." << endl;
            goto revision;
         }

         optionNum = std::stoi(optionHandler);
         total.editCourse(optionNum);
         break;
      case 5:
         importFile:
         cout << "Confirm any overwrite? (Y/N)" << endl;
         cin >> optionHandler;
         optionChar = optionHandler.at(0);
         
         if (optionChar == 'Y' || optionChar == 'y') {
            total.importFile();
         } else if (optionChar == 'N' || optionChar == 'n') {
            cout << "Cancelling import..." << endl;
         } else {
            goto importFile;
         }

         break;
      case 6:
         total.writeToFile();
         break;
      case 7:
         total.displayGPAs();
         break;
      case 8:
         exit(0);
         break;
      default:
         exit(0);
         break;
      }

   }
}
