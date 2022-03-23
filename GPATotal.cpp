/**
 * Program       : A GPA calculator
 * File Name     : GPATotal.cpp
 * Author        : Syrus Nelson
 * Last revision : 23 March 2022
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "GPATotal.h"
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
   
   //This loop is to keep the session going for the user to add more courses
   while (2 == 2) {
      
   gpa:
      cout << "Enter the course GPA: ";
      cin >> temp;
      tempGPA = std::stod(temp);
      temp = "";
      
      if (tempGPA > 4.0 || tempGPA < 0.0) {
         cout << "Try Entering a value from 0.0 - 4.0" << endl;
         tempGPA = 0.0;
         goto gpa;
      }

      credits:
      cout << "Enter the course credits: ";
      cin >> temp;
      tempCredits = std::stoi(temp);
      temp = "";
      
      if (tempCredits > 10 || tempCredits < 1) {
         cout << "Try Entering a value from 1 - 10" << endl;
         tempCredits = 0;
         goto credits;
      }

      description:
      cout << "Enter the course name with only letters and/or numbers: ";
      cin >> tempDescription;
      
      //Check each character in the course name for valid characters
      for (int character = 0; character < tempDescription.size(); character++) {
         if (!(isalnum(tempDescription.at(character)))) {
            cout << "Please enter a valid course name." << endl;
            tempDescription = "";
            goto description;
         }
      }
      
      //If the course description happens to be empty, use a placeholder of X
      if (!tempDescription.empty()) {
         addCourse(Course(tempGPA, tempCredits, tempDescription));
      } else {
         addCourse(Course(tempGPA, tempCredits, "X"));
      }
      
      cout << "Continue? (1 for yes, any other character for no)" << endl;
      tempDescription = "";
      cin >> tempDescription;
      if (tempDescription != "1") {
         break;
      }
   }

}
void GPATotal::calculateNewGPA() 
{
   double tempGPA = 0.0;
   
   //Add up all of the GPAs in courses_
   for (int course = 0; course < courses_.size(); course++) {
      tempGPA += courses_.at(course).getGPA();
   }

   //Average out the total sum of the GPAs by number of courses
   tempGPA /= courses_.size();
   gpaTotal_ = tempGPA;
}
double GPATotal::getGPATotal() const 
{
   return gpaTotal_;
}
void GPATotal::displayGPAs() const
{
   
   if (courses_.size() == 0) {
      cout << "Add GPAs to show a transcript" << endl;
   } else {
      
      //Loop through to output each course
      for (int i = 0; i < courses_.size(); i++) {
         cout << (i + 1) << ". Course name: " 
            << courses_.at(i).getDescription()
            << "        Credits: " << courses_.at(i).getCredits() 
            << "        GPA in Course: "
            << courses_.at(i).getGPA() + 0.0 << endl;
      }

      cout << "Cumulative GPA: " << getGPATotal() <<"\n" << "\n";
   }

}
void GPATotal::deleteCourse(const int courseNumber) 
{
   
   if (courseNumber > courses_.size() || courseNumber < 1) {
      cout << "Try inputting a valid course number to delete." << endl;
   } else {
      courses_.erase(courses_.begin() + courseNumber - 1);
   }

}
void GPATotal::editCourse(const int courseNumber) 
{
   
   if (courseNumber > courses_.size() || courseNumber < 1) {
      cout << "Try inputting a valid course number to edit." << endl;
   } else {
      
      //This loop is to keep the session going for the user to revise a given course
      while (2 == 2) {
         string userInput;
         int selection;
         double gpaRevision;
         cout << "Which field would you like to edit?" << endl;
         cout << "1. Course Name" << "\n2. Number of credits" << "\n3. Course GPA"
            << "\n4. Exit" << endl;
         cin >> userInput;
         
         //Check input in case the user didn't input a valid int
         if (!std::isdigit(userInput.at(0))) {
            cout << "Please enter an integer." << endl;
            continue;
         }

         selection = stoi(userInput);
         
         //Use selection control to decide what option user wants based on their input
         switch (selection) {

         case 1:
         nameEdit:
            cout << "Enter the new course name with only letters and/or numbers: ";
            cin >> userInput;

            //Check for each character if there is an invalid character in the input course name
            for (int character = 0; character < userInput.size(); character++) {
               if (!(isalnum(userInput.at(character)))) {
                  cout << "Please enter a valid new course name." << endl;
                  userInput = "";
                  goto nameEdit;
               }
            }
            courses_.at(courseNumber - 1).setDescription(userInput);
            userInput = "";
            break;

         case 2:
         creditEdit:
            cout << "Enter the revised number of credits as an integer value from 1 - 10: ";
            cin >> userInput;
            
            if (!isdigit(userInput.at(0))) {
               cout << "Please enter an integer value, no non-integer characters." << endl;
               goto creditEdit;
            }

            selection = stoi(userInput);
            if (selection > 10 || selection < 1) {
               goto creditEdit;
            }
            courses_.at(courseNumber - 1).setCredits(selection);
            userInput = "";
            calculateNewGPA();
            break;

         case 3:
            gpaEdit:
            cout << "Enter the revised GPA as an decimal value from 0.0 - 4.0: ";
            cin >> userInput;
            
            if (!isdigit(userInput.at(0))) {
               cout << "Please enter an integer value, no non-digit characters." << endl;
               goto gpaEdit;
            }

            gpaRevision = stod(userInput);
            if (gpaRevision > 4.0 || gpaRevision < 0.0) {
               goto gpaEdit;
            }
            courses_.at(courseNumber - 1).setGPA(gpaRevision);
            userInput = "";
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
   
   if (courses_.size() == 0) {
      cout << "Add GPAs to generate a file" << endl;
   } else {
      std::ofstream newFile;
      newFile.open("GPACalculatorData.txt");
      
      /* Using ! to delimit an end for the course name
       * Using # to delimit an end for the credits
       * Using % to delimit an end for the GPA
       */
      for (int i = 0; i < courses_.size(); i++) {
         newFile << courses_.at(i).getDescription()
            << '!' << courses_.at(i).getCredits() << '#'
            << courses_.at(i).getGPA() << '%' << endl;
      }

      newFile.close();
   }

}
void GPATotal::importFile() 
{
   //Clear to get rid of existing contents
   courses_.clear();
   string line;
   string temp;
   string tempDescription;
   int tempInt = 0;
   double tempDouble = 0.0;
   
   try 
   {
      std::ifstream fileRead("GPACalculatorData.txt");
      if (fileRead.is_open()) {
         
         //Loop for each line/course to import
         while (std::getline(fileRead, line)) {
            
            /* Keep adding the characters of the line so long as input is valid
             *  and an end delimiter (!, #, or %) is not reached.
             * Once an end delimiter is reached, store the temp contents into
             *  the corresponding variable.
             * Once all three end delimiters have been reached, create a new course
             */
            for (int letter = 0; letter < line.size(); letter++) {
               
               if (line.at(letter) == '!') {
                  tempDescription = temp;
                  temp = "";
                  continue;
               } else if (line.at(letter) == '#') {
                  tempInt = stoi(temp);
                  temp = "";
                  continue;
               } else if (line.at(letter) == '%') {
                  tempDouble = stod(temp);
                  temp = "";
                  continue;
               } else if (!(isalnum(line.at(letter)) || line.at(letter) == '.')) {
                  throw 32;
               }

               temp += line.at(letter);
            }

            courses_.push_back(Course(tempDouble, tempInt, tempDescription));
            temp = "";
         }

      } else {
         throw 'f';
      }
      calculateNewGPA();

   } catch (int importError) {
      std::cerr << "Format does not match." << endl;
      courses_.clear();
   } catch (char fileNotFound) {
      std::cerr << "File not found." << endl;
   }
}