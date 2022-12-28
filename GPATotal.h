/**
 * Program       : A GPA calculator
 * File Name     : GPATotal.h
 * Author        : Syrus Nelson
 * Last revision : 17 December 2022
 * Purpose       : To have a GPA calculator that saves your input for later calculations
 * User Input    : Integers for option selection.
 *               : Strings for various operations.
 * Output        : A file that is formatted to be read from this program.
 *               : The current transcript of the user.
 */
#include "Course.h"
class GPATotal
{
   // Member variables
   double gpaTotal_;
   vector<Course> courses_;

   // Private Functions
   /**
    * Function         : void calculateNewGPA();
    * Parameters       : None
    * Purpose          : To hide away the new GPA calculation functionality
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
    * Functions Called : stod(), stoi(), isalnum(), empty(), addCourse()
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
    * Function         : int checkInput(string *input, const int maxInputSize, const string errorMessage);
    * Parameters       : input which is to be checked, maxInputSize which is the max chars/digits, errorMessage
    *                  :  which is the corresponding error message.
    * Purpose          : To check for any invalid input that would cause the program to crash
    * Pre-Condition    : The user has input some value
    * Post-Condition   : The input is validated, otherwise the corresponding error message is displayed
    *                  :  and the program asks the user to re-enter a valid value
    * Return Value     : void
    * Functions Called : size(), isalpha()
    */
   int checkInput(string *input, const int maxInputSize, const string errorMessage);

   /**
    * Function         : int checkValue(string *input, const double minValue, const double maxValue, const string errorMessage);
    * Parameters       : input which is to be checked, minValue which is the minimum input value, maxValue which is the maximum
    *                  :  input value, errorMessage which is the corresponding error message
    * Purpose          : To check for any invalid input beyond the bounds of the intended use
    * Pre-Condition    : The user has input some value
    * Post-Condition   : The input is validated, otherwise the corresponding error message is displayed
    *                  :  and the program asks the user to re-enter a valid value
    * Return Value     : void
    * Functions Called : stod()
    */
   int checkValue(string *input, const double minValue, const double maxValue, const string errorMessage);

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
    * Functions Called : size(), isdigit(), at(), stoi(), isalnum(), stod(),
    *                  :  setDescription(), setGPA(), setCredits(), calculateNewGPA()
    */
   void editCourse(const int courseNumber);

public:
   /**
    * Function         : void sentinalFunction(GPATotal& total);
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
