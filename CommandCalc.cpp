/**
 * Program       : A GPA calculator
 * File Name     : CommandCalc.cpp
 * Author        : Syrus Nelson
 * Last revision : 20 July 2023
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
      int valid = menuInteract(optionHandler, optionNum, check);
      if (valid == -1)
      {
         continue;
      }

      switch (optionNum)
      {
      case 1:
      {
         gpaFunc.addCourseGPAs();
         break;
      }
      case 2:
         displayTotalGPA(gpaFunc);
         break;
      case 3:
         deleteGPA(gpaFunc, optionHandler, optionNum);
         break;
      case 4:
         editGPA(gpaFunc, optionHandler, optionNum);
         break;
      case 5:
         importGPA(gpaFunc, optionHandler);
         break;
      case 6:
         gpaFunc.writeToFile();
         break;
      case 7:
         displayTranscript(gpaFunc);
         break;
      case 8:
         displayCredit();
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
void CommandCalc::displayCredit()
{
   cout << "Credit for creating and maintaining this program goes to Syrus Nelson" << '\n'
        << endl;
}
void CommandCalc::displayTranscript(GPATotal &gpaFunc)
{
   if (gpaFunc.getCourses().empty())
   {
      cout << "Try adding some courses to see their related information." << '\n'
           << endl;
      return;
   }

   gpaFunc.displayGPAs();
}
void CommandCalc::importGPA(GPATotal &gpaFunc, string &optionHandler)
{
   char optionChar;
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
}
int CommandCalc::menuInteract(string &optionHandler, int &optionNum, CheckErr &check)
{
   cout << "Enter an option from 1 - 9" << endl;
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

   if (check.checkValue(&optionHandler, 1, 9, "Value is not within 1-9 integer range, please re-enter.") == -1)
   {
      return -1;
   }
   optionNum = std::stoi(optionHandler);
   return 1;
}
void CommandCalc::displayTotalGPA(GPATotal &gpaFunc)
{
   if (gpaFunc.getCourses().empty())
   {
      cout << "Try adding some courses to generate a total GPA." << '\n'
           << endl;
      return;
   }

   cout << "GPA: " << gpaFunc.getGPATotal() << '\n'
        << endl;
}
void CommandCalc::deleteGPA(GPATotal &gpaFunc, string &optionHandler, int &optionNum)
{
   if (gpaFunc.getCourses().empty())
   {
      cout << "Try adding some courses before deleting any." << '\n'
           << endl;
      return;
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
}
void CommandCalc::editGPA(GPATotal &gpaFunc, string &optionHandler, int &optionNum)
{
   if (gpaFunc.getCourses().empty())
   {
      cout << "Try adding some courses before editing any." << '\n'
           << endl;
      return;
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
}