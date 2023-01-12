/**
 * Program       : A GPA calculator
 * File Name     : CommandCalc.cpp
 * Author        : Syrus Nelson
 * Last revision : 12 January 2023
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "CommandCalc.h"
void CommandCalc::sentinalFunction()
{
   string optionHandler;
   int optionNum;
   char optionChar;
   GPATotal gpaFunc;
   CheckErr check;

   // This loop is to keep the session going for the user to continue interaction
   while (1 == 1)
   {
      cout << "Enter an option from 1 - 8" << endl;
      cout << "1 - Enter course GPAs" << endl;
      cout << "2 - Get the total GPA" << endl;
      cout << "3 - Delete an entry" << endl;
      cout << "4 - Edit an entry" << endl;
      cout << "5 - Import GPAs" << endl;
      cout << "6 - Export GPAs" << endl;
      cout << "7 - Output unofficial transcript" << endl;
      cout << "8 - Creator acknowledgement" << endl;
      cout << "9 - Exit" << endl;

      cin >> optionHandler;

      if (check.checkInput(&optionHandler, 9, "Value is not within 1-9 integer range, please re-enter.") == -1)
      {
         continue;
      }
      optionNum = std::stoi(optionHandler);

      switch (optionNum)
      {
      case 1:
      {
         gpaFunc.addCourseGPAs();
         break;
      }
      case 2:

         if (gpaFunc.getCourses().empty())
         {
            cout << "Try adding some courses to generate a total GPA." << '\n'
                 << endl;
            break;
         }

         cout << "GPA: " << gpaFunc.getGPATotal() << '\n'
              << endl;
         break;
      case 3:
         if (gpaFunc.getCourses().empty())
         {
            cout << "Try adding some courses before deleting any." << '\n'
                 << endl;
            break;
         }
         while (2 == 2)
         {
            gpaFunc.displayGPAs();
            cout << "Choose a course to delete by its number" << endl;
            cin >> optionHandler;

            if (!std::isdigit(optionHandler.at(0)))
            {
               cout << "Please enter a valid course number." << endl;
               continue;
            }

            optionNum = std::stoi(optionHandler);
            gpaFunc.deleteCourse(optionNum);
            break;
         }
         break;

      case 4:
         if (gpaFunc.getCourses().empty())
         {
            cout << "Try adding some courses before editing any." << '\n'
                 << endl;
            break;
         }
         while (2 == 2)
         {
            gpaFunc.displayGPAs();
            cout << "Choose a course to edit by its number" << endl;
            cin >> optionHandler;

            if (!std::isdigit(optionHandler.at(0)))
            {
               cout << "Please enter a valid course number." << endl;
               continue;
            }

            optionNum = std::stoi(optionHandler);
            gpaFunc.editCourse(optionNum);
            break;
         }
         break;

      case 5:
         while (2 == 2)
         {
            if (!gpaFunc.getCourses().empty())
            {
               cout << "Overwrite current data? (Y/N)" << endl;
               cin >> optionHandler;
               optionChar = optionHandler.at(0);

               if (optionChar == 'Y' || optionChar == 'y')
               {
                  gpaFunc.importFile();
               }
               else if (optionChar == 'N' || optionChar == 'n')
               {
                  cout << "Cancelling import." << endl;
               }
               else
               {
                  continue;
               }
            }
            else
            {
               gpaFunc.importFile();
            }

            break;
         }
         break;

      case 6:
         gpaFunc.writeToFile();
         break;
      case 7:

         if (gpaFunc.getCourses().empty())
         {
            cout << "Try adding some courses to see their related information." << '\n'
                 << endl;
            break;
         }

         gpaFunc.displayGPAs();
         break;
      case 8:
         cout << "Credit for creating and maintaining this software goes to Syrus Nelson" << '\n'
              << endl;
         break;
      case 9:
         exit(0);
         break;
      default:
         exit(0);
         break;
      }
   }
}