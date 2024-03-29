/**
 * Program       : A GPA calculator
 * File Name     : GPATotal.h
 * Author        : Syrus Nelson
 * Last revision : 20 July 2023
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "Course.h"
#include "CheckErr.h"
class GPATotal
{
   // Private Member variables
   double gpaTotal_;
   vector<Course> courses_;

public:
   // Public Functions

   /**
    * Function         : vector<Course> getCourses() const;
    * Parameters       : None
    * Purpose          : To function as a way to get the courses outside of this class
    * Pre-Condition    : This function is called
    * Post-Condition   : A vector of courses is returned
    * Return Value     : vector<Course>
    * Functions Called :
    */
   vector<Course> getCourses() const;

   /**
    * Function         : void calculateNewGPA();
    * Parameters       : None
    * Purpose          : To hide away the GPA calculation functionality
    * Pre-Condition    : at least one course has been enterered and this function is called
    * Post-Condition   : The new GPA will have been calculated
    * Return Value     : void
    * Functions Called : getGPA(), size()
    */
   void calculateNewGPA();

   /**
    * Function         : void addCourse(const Course course);
    * Parameters       : course which is the new course to be added to the transcript
    * Purpose          : To be able to add new courses and recalculate the total GPA
    * Pre-Condition    : A course has been created to be added and this function has been called
    * Post-Condition   : The total GPA is recalculated with the newly added course
    * Return Value     : void
    * Functions Called : push_back(), calculateNewGPA()
    */
   void addCourse(const Course course);

   // Public Functions
   /**
    * Function         : void addCourseGPAs();
    * Parameters       : None
    * Purpose          : To add multiple new courses to the transcript with user input
    * Pre-Condition    : Program has started and user selected option 1 in the sentinalFunction
    * Post-Condition   : New courses are added to the transcript
    * Return Value     : void
    * Functions Called : enterGPA(), enterCredits(), enterName(), empty(),
    *                  :  addCourse()
    */
   void addCourseGPAs();

   /**
    * Function         : double getGPATotal() const;
    * Parameters       : None
    * Purpose          : To return the current total GPA
    * Pre-Condition    : Program has started and user selected option 2 in the sentinalFunction
    * Post-Condition   : The total GPA is output
    * Return Value     : double
    * Functions Called : None
    */
   double getGPATotal() const;

   /**
    * Function         : void deleteCourse(const int courseNumber);
    * Parameters       : courseNumber which is the user selected course to delete
    * Purpose          : To remove a user selected course from the transcript
    * Pre-Condition    : Program has started and user selected option 3 in the sentinalFunction
    * Post-Condition   : The user selected course is deleted if valid
    * Return Value     : void
    * Functions Called : size(), erase(), begin()
    */
   void deleteCourse(const int courseNumber);

   /**
    * Function         : void importFile();
    * Parameters       : None
    * Purpose          : To load input that was exported in the same format
    * Pre-Condition    : A GPACalculatorData.txt file must be present with the exact formatting
    * Post-Condition   : The contents of the file are imported into the system
    * Return Value     : void
    * Functions Called : clear(), is_open(), getline(), size(), at(), stoi(), stod(),
    *                  :  isalnum(), push_back(), calculateNewGPA()
    */
   void importFile();

   /**
    * Function         : void writeToFile() const;
    * Parameters       : None
    * Purpose          : To export the current transcript into a file that can be later imported
    * Pre-Condition    : The current contents of courses_ is not empty
    * Post-Condition   : A new file is generated, or the current GPACalculatorData.txt is revised
    *                  :  according to the current state of the courses_.
    * Return Value     : void
    * Functions Called : size(), open(), at(), getDescription(), getCredits(), getGPA(), close()
    */
   void writeToFile() const;

   /**
    * Function         : void displayGPAs() const;
    * Parameters       : None
    * Purpose          : Display the current transcript to the user
    * Pre-Condition    : Program has started and user selected option 7 in the sentinalFunction
    * Post-Condition   : The transcript is displayed to the user
    * Return Value     : void
    * Functions Called : size(), at(), getDescription(), getCredits(), getGPA(), getGPATotal()
    */
   void displayGPAs() const;

   /**
    * Function         : void editCourse(const int courseNumber);
    * Parameters       : courseNumber which is the user selected course to edit
    * Purpose          : To edit a user selected course from the transcript
    * Pre-Condition    : At least one course entry exists and user
    *                  :  selected option 4 in the sentinalFunction
    * Post-Condition   : The course is revised to the user's input.
    *                  : The GPA is recalculated upon revision.
    * Return Value     : void
    * Functions Called : size(), stoi(), at(), enterCredits(), setCredits(), userEditSelection(),
    *                  :  setDescription(), enterGPA(), setGPA(), calculateNewGPA()
    */
   void editCourse(const int courseNumber);

private:
   /**
    * Function         : void enterGPA(string &temp, CheckErr &check, double &tempGPA);
    * Parameters       : temporary string to use for entering the GPA, an error checker, and the new GPA
    * Purpose          : To revise the GPA for a given Course
    * Pre-Condition    : The course already exists
    * Post-Condition   : The new GPA is entered and stored in tempGPA
    * Return Value     : void
    * Functions Called : checkInput(), checkValue(), stod()
    */
   void enterGPA(string &temp, CheckErr &check, double &tempGPA);

   /**
    * Function         : void enterCredits(string &temp, CheckErr &check, int &tempCredits);
    * Parameters       : temporary string to use for entering the credit amount, an error checker, and the new credit value
    * Purpose          : To revise the credit value for a given Course
    * Pre-Condition    : The course already exists
    * Post-Condition   : The new credit value is entered and stored in tempCredits
    * Return Value     : void
    * Functions Called : checkInput(), checkValue(), stoi()
    */
   void enterCredits(string &temp, CheckErr &check, int &tempCredits);

   /**
    * Function         : void enterName(string &tempDescription);
    * Parameters       : temporary string to use for the new name of the course
    * Purpose          : To revise the description of a given course
    * Pre-Condition    : The course already exists
    * Post-Condition   : The new description is entered and stored in tempDescription
    * Return Value     : void
    * Functions Called : isalnum(), at(), size()
    */
   void enterName(string &tempDescription);

   /**
    * Function         : int userEditSelection(string &userInput, CheckErr& check);
    * Parameters       : temporary string to use for the userInput
    *                  :  check to make sure the selection is valid
    * Purpose          : To select an edit option
    * Pre-Condition    : The course already exists
    * Post-Condition   : The user has selected the field to edit
    * Return Value     : int
    * Functions Called : isdigit(), at()
    */
   int userEditSelection(string &userInput, CheckErr &check);
};
