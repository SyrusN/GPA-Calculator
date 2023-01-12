/**
 * Program       : A GPA calculator
 * File Name     : GPATotal.cpp
 * Author        : Syrus Nelson
 * Last revision : 12 January 2023
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "GPATotal.h"
vector<Course> GPATotal::getCourses() const
{
   return courses_;
}
void GPATotal::addCourse(const Course course)
{
   courses_.push_back(course);
   calculateNewGPA();
}
void GPATotal::addCourseGPAs()
{
   double tempGPA;
   int tempCredits;
   string tempDescription = "";
   string temp;
   CheckErr check;

   // This loop is to keep the session going for the user to add more courses
   while (2 == 2)
   {

      // GPA loop
      while (3 == 3)
      {
         cout << '\n'
              << "Enter the course GPA: ";
         cin >> temp;

         string errorMessage = "Try Entering a value from 0.0 - 4.0";

         int successfulInput = check.checkInput(&temp, 3, errorMessage);
         if (successfulInput == -1)
         {
            continue;
         }

         successfulInput = check.checkValue(&temp, 0.0, 4.0, errorMessage);
         if (successfulInput == -1)
         {
            continue;
         }

         tempGPA = std::stod(temp);
         temp = "";
         break;
      }

      // Credits loop
      while (3 == 3)
      {
         cout << "Enter the course credits: ";
         cin >> temp;
         string errorMessage = "Try Entering a value from 1 - 10";

         int successfulInput = check.checkInput(&temp, 3, errorMessage);
         if (successfulInput == -1)
         {
            continue;
         }

         successfulInput = check.checkValue(&temp, 1, 10, errorMessage);
         if (successfulInput == -1)
         {
            continue;
         }

         tempCredits = std::stoi(temp);
         temp = "";
         break;
      }

      while (3 == 3)
      {
         cout << "Enter the course name with only letters and/or numbers: ";
         cin >> tempDescription;
         bool invalid = false;

         // Check each character in the course name for valid characters
         for (int character = 0; character < tempDescription.size(); character++)
         {
            if (!(isalnum(tempDescription.at(character))))
            {
               cout << "Please enter a valid course name." << endl;
               tempDescription = "";
               invalid = true;
            }
         }

         if (invalid)
         {
            continue;
         }
         break;
      }

      // If the course description happens to be empty, use a placeholder of X
      if (!tempDescription.empty())
      {
         addCourse(Course(tempGPA, tempCredits, tempDescription));
      }
      else
      {
         addCourse(Course(tempGPA, tempCredits, "X"));
      }
      cout << "Course added." << endl;
      cout << "Continue? (1 for yes, any other character for no)" << '\n'
           << endl;
      tempDescription = "";
      cin >> tempDescription;
      if (tempDescription != "1")
      {
         break;
      }
   }
}
void GPATotal::calculateNewGPA()
{
   double tempGPA = 0.0;

   // Add up all of the GPAs in courses_
   for (int course = 0; course < courses_.size(); course++)
   {
      tempGPA += courses_.at(course).getGPA();
   }

   // Average out the total sum of the GPAs by number of courses
   tempGPA /= courses_.size();
   gpaTotal_ = tempGPA;
}
double GPATotal::getGPATotal() const
{
   return gpaTotal_;
}
void GPATotal::displayGPAs() const
{

   if (courses_.size() == 0)
   {
      cout << "Add GPAs to show a transcript" << '\n'
           << endl;
   }
   else
   {

      // Loop through to output each course
      for (int i = 0; i < courses_.size(); i++)
      {
         cout << (i + 1) << ". Course name: "
              << courses_.at(i).getDescription()
              << "        Credits: " << courses_.at(i).getCredits()
              << "        GPA in Course: "
              << courses_.at(i).getGPA() + 0.0 << endl;
      }

      cout << "Cumulative GPA: " << getGPATotal() << "\n"
           << "\n";
   }
}
void GPATotal::deleteCourse(const int courseNumber)
{

   if (courseNumber > courses_.size() || courseNumber < 1)
   {
      cout << "Try inputting a valid course number to delete." << '\n'
           << endl;
   }
   else
   {
      courses_.erase(courses_.begin() + courseNumber - 1);
      cout << "Course deleted." << '\n'
           << endl;
   }
}
void GPATotal::editCourse(const int courseNumber)
{

   if (courseNumber > courses_.size() || courseNumber < 1)
   {
      cout << "Try inputting a valid course number to edit." << '\n'
           << endl;
   }
   else
   {

      // This loop is to keep the session going for the user to revise a given course
      while (2 == 2)
      {
         string userInput;
         int selection;
         double gpaRevision;
         cout << "Which field would you like to edit?" << endl;
         cout << "1. Course Name"
              << "\n2. Number of credits"
              << "\n3. Course GPA"
              << "\n4. Exit" << endl;
         cin >> userInput;

         // Check input in case the user didn't input a valid int
         if (!std::isdigit(userInput.at(0)))
         {
            cout << "Please enter an integer." << endl;
            continue;
         }

         selection = stoi(userInput);

         // Use selection control to decide what option user wants based on their input
         switch (selection)
         {

         case 1:
            while (2 == 2)
            {
               cout << "Enter the new course name with only letters and/or numbers: ";
               cin >> userInput;
               bool invalid = false;

               // Check for each character if there is an invalid character in the input course name
               for (int character = 0; character < userInput.size(); character++)
               {
                  if (!(isalnum(userInput.at(character))))
                  {
                     cout << "Please enter a valid new course name." << endl;
                     userInput = "";
                     invalid = true;
                  }
               }

               if (invalid)
               {
                  continue;
               }
               courses_.at(courseNumber - 1).setDescription(userInput);
               cout << "Updated course name." << '\n'
                    << endl;
               userInput = "";
               break;
            }
            break;

         case 2:
            while (2 == 2)
            {
               cout << "Enter the revised number of credits as an integer value from 1 - 10: ";
               cin >> userInput;
               bool invalid = false;

               if (!isdigit(userInput.at(0)))
               {
                  cout << "Please enter an integer value, no non-integer characters." << endl;
                  invalid = true;
               }

               if (invalid)
               {
                  continue;
               }
               selection = stoi(userInput);

               if (selection > 10 || selection < 1)
               {
                  invalid = true;
               }

               if (invalid)
               {
                  continue;
               }
               courses_.at(courseNumber - 1).setCredits(selection);
               userInput = "";
               cout << "Updated course credits." << '\n'
                    << endl;
               break;
            }
            break;
         case 3:
            while (2 == 2)
            {
               cout << "Enter the revised GPA as an decimal value from 0.0 - 4.0: ";
               cin >> userInput;
               bool invalid = false;

               if (!isdigit(userInput.at(0)))
               {
                  cout << "Please enter an integer value, no non-digit characters." << endl;
                  invalid = true;
               }
               if (invalid)
               {
                  continue;
               }

               gpaRevision = stod(userInput);
               if (gpaRevision > 4.0 || gpaRevision < 0.0)
               {
                  invalid = true;
               }

               if (invalid)
               {
                  continue;
               }
               courses_.at(courseNumber - 1).setGPA(gpaRevision);
               calculateNewGPA();
               userInput = "";
               cout << "Updated course GPA." << '\n'
                    << endl;
               break;
            }
            break;
         case 4:
            return;
            break;
         default:
            return;
            break;
         }
      }
   }
}
void GPATotal::writeToFile() const
{

   if (courses_.size() == 0)
   {
      cout << "Add GPAs to generate a file" << endl;
   }
   else
   {
      std::ofstream newFile;
      std::ifstream existFile("AppData/GPACalculatorData.txt");
      if (existFile.is_open())
      {
         char optionChar;
         string optionHandler;
         while (2 == 2)
         {
            cout << "File already exists. Overwrite existing file? (Y/N)" << endl;
            cin >> optionHandler;
            optionChar = optionHandler.at(0);

            if (optionChar == 'Y' || optionChar == 'y')
            {
               // Overwrite the existing file.
               break;
            }
            else if (optionChar == 'N' || optionChar == 'n')
            {
               cout << "Cancelling export." << '\n'
                    << endl;
               return;
            }
            else
            {
               // Iterate once more for user to enter a proper input.
               continue;
            }
         }
      }
      newFile.open("AppData/GPACalculatorData.txt");

      /* Using ! to delimit an end for the course name
       * Using # to delimit an end for the credits
       * Using % to delimit an end for the GPA
       */
      for (int i = 0; i < courses_.size(); i++)
      {
         newFile << courses_.at(i).getDescription()
                 << '!' << courses_.at(i).getCredits() << '#'
                 << courses_.at(i).getGPA() << '%' << endl;
      }

      newFile.close();
      cout << "File generated." << '\n'
           << endl;
   }
}
void GPATotal::importFile()
{
   // Clear to get rid of existing contents
   courses_.clear();
   string line;
   string temp;
   string tempDescription;
   int tempInt = 0;
   double tempDouble = 0.0;

   try
   {
      std::ifstream fileRead("AppData/GPACalculatorData.txt");
      if (fileRead.is_open())
      {

         // Loop for each line/course to import
         while (std::getline(fileRead, line))
         {

            /* Keep adding the characters of the line so long as input is valid
             *  and an end delimiter (!, #, or %) is not reached.
             * Once an end delimiter is reached, store the temp contents into
             *  the corresponding variable.
             * Once all three end delimiters have been reached, create a new course
             */
            for (int letter = 0; letter < line.size(); letter++)
            {

               if (line.at(letter) == '!')
               {
                  tempDescription = temp;
                  temp = "";
                  continue;
               }
               else if (line.at(letter) == '#')
               {
                  tempInt = stoi(temp);
                  temp = "";
                  continue;
               }
               else if (line.at(letter) == '%')
               {
                  tempDouble = stod(temp);
                  temp = "";
                  continue;
               }
               else if (!(isalnum(line.at(letter)) || line.at(letter) == '.'))
               {
                  throw 32;
               }

               temp += line.at(letter);
            }

            courses_.push_back(Course(tempDouble, tempInt, tempDescription));
            temp = "";
         }

         calculateNewGPA();
         cout << "File successfully imported." << '\n'
              << endl;
      }
      else
      {
         throw 'f';
      }
   }
   catch (int importError)
   {
      std::cerr << "Format does not match." << '\n'
                << endl;
      courses_.clear();
   }
   catch (char fileNotFound)
   {
      std::cerr << "File not found." << '\n'
                << endl;
   }
}