/**
 * Program       : A GPA calculator
 * File Name     : Course.h
 * Author        : Syrus Nelson
 * Last revision : 23 March 2022
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::endl;
class Course
{
   //Member variables
   double gpa_;
   int credits_;
   string description_;
public:
    //Constructors
   /**
    * Constructor      : Course(double gpa, int credits) : gpa_(gpa), credits_(credits) {}
    * Purpose          : To create and initialize a Course object with gpa and credits
    * Pre-Condition    : This Constructor has been called
    * Post-Condition   : A new course is created without a course name
    * Return Value     : None
    * Functions Called : None
    */
   Course(double gpa, int credits) : gpa_(gpa), credits_(credits) {}

   /**
    * Constructor      : Course(double gpa, int credits, string description) : gpa_(gpa), 
    *                  :  credits_(credits), description_(description) {}
    * Purpose          : To create and initialize a Course object with a course name, gpa, and credits
    * Pre-Condition    : This Constructor has been called
    * Post-Condition   : A new course is created
    * Return Value     : None
    * Functions Called : None
    */
   Course(double gpa, int credits, string description) : gpa_(gpa), credits_(credits), description_(description) {}

   /**
    * Function         : double getGPA() const;
    * Parameters       : None
    * Purpose          : To return the given course GPA
    * Pre-Condition    : The invoking course has been created
    * Post-Condition   : The course GPA is returned
    * Return Value     : double
    * Functions Called : None
    */
   double getGPA() const;

   /**
    * Function         : void setGPA(const double gpaInput);
    * Parameters       : gpaInput to update the course GPA with a new GPA
    * Purpose          : To update a given course with a user input new GPA
    * Pre-Condition    : A course has been already created to edit the GPA
    * Post-Condition   : The course's GPA is updated
    * Return Value     : void
    * Functions Called : None
    */
   void setGPA(const double gpaInput);

   /**
    * Function         : int getCredits() const;
    * Parameters       : None
    * Purpose          : To return the number of credits in a given course
    * Pre-Condition    : The invoking course has been created
    * Post-Condition   : The course credits are returned
    * Return Value     : int
    * Functions Called : None
    */
   int getCredits() const;

   /**
    * Function         : void setCredits(const int creditInput);
    * Parameters       : creditInput to update the course credits with user input credits
    * Purpose          : To update the invoking course with user input credits
    * Pre-Condition    : A course has been created prior to it invoking this function
    * Post-Condition   : The course credits are updated with the user input value
    * Return Value     : void
    * Functions Called : None
    */
   void setCredits(const int creditInput);

   /**
    * Function         : string getDescription() const;
    * Parameters       : None
    * Purpose          : To return the description of a given course
    * Pre-Condition    : A course has been created prior to it invoking this function
    * Post-Condition   : The course name is returned
    * Return Value     : string
    * Functions Called : None
    */
   string getDescription() const;

   /**
    * Function         : void setDescription(const string descriptionInput);
    * Parameters       : descriptionInput to update the course name with the user's input
    * Purpose          : To update a given course's name
    * Pre-Condition    : A course has been created prior to it invoking this function
    * Post-Condition   : The course is updated with a the user's input course name
    * Return Value     : void
    * Functions Called : None
    */
   void setDescription(const string descriptionInput);
};

