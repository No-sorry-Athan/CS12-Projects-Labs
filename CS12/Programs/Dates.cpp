#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string mn) const;
};


// Implement the Date member functions here

Date::Date() {
	this->month = 1;
	this->day = 1;
	this->year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
	this->month = m;
	this->day = d;
	this->year = y;
	this->monthName = name(this->month);

	bool temp = false;
	if (this->month > 12) {
		this->month = 12;
		temp = true;
	}
	if (this->month < 1) {
		this->month = 1;
		temp = true;
	}
	unsigned dpm = daysPerMonth(this->month, y);
	if (this->day < 1) {
		this->day = 1;
		temp = true;
	}
	if (this->day > dpm) {
		this->day = dpm;
		temp = true;
	}
	if (this->day == 29 && !isLeap(this->year) && this->month == 2) {
		this->day = 28;
		temp = true;
	}

	if (temp)
		cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
}

Date::Date(const string& m, unsigned d, unsigned y) {
	this->monthName = m;
	this->month = number(m);
	this->day = d;
	this->year = y;

	if (m != "January" && m != "january" && m != "February" && m != "february" && m != "March" && m != "march" && m != "April" && m != "april" && m != "May" && m != "may" && m != "June" && m != "june" && m != "July"
		&& m != "july" && m != "August" && m != "august" && m != "September" && m != "september" && m != "October" && m != "october" && m != "November" && m != "november" && m != "December" && m != "december") {

		this->month = 1;
		this->day = 1;
		this->year = 2000;
		this->monthName = "January";
		cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
	}
	
	bool temp = false;
	if (this->month > 12) {
		this->month = 12;
		temp = true;
	}
	if (this->month < 1) {
		this->month = 1;
		temp = true;
	}
	unsigned dpm = daysPerMonth(this->month, y);

	if (this->day < 1) {
		this->day = 1;
		temp = true;
	}
	if (this->day > dpm) {
		this->day = dpm;
		temp = true;
	}
	if (this->day == 29 && !isLeap(this->year) && this->month == 2) {
		this->day = 28;
		temp = true;
	}
	if (temp)
		cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
}

void Date::printNumeric() const {
	cout << this->month << "/" << this->day << "/" << this->year;
}

void Date::printAlpha() const {
	string mn = name(this->month);
	cout << mn << " " << this->day << ", " << this->year;
}

bool Date::isLeap(unsigned y) const {
	return (y % 4 == 0) && (!(y % 100 == 0) || y % 400 == 0);
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
	if (m == 1U)
		return 31U;
	else if (m == 2U)
		return isLeap(y) ? 29U : 28U;
	else if (m == 3U)
		return 31U;
	else if (m == 4U)
		return 30U;
	else if (m == 5U)
		return 31U;
	else if (m == 6U)
		return 30U;
	else if (m == 7U)
		return 31U;
	else if (m == 8U)
		return 31U;
	else if (m == 9U)
		return 30U;
	else if (m == 10U)
		return 31U;
	else if (m == 11U)
		return 30U;
	else if (m == 12U)
		return 31U;

	return -1;
}

string Date::name(unsigned m) const {
	if (m == 1U)
		return "January";
	else if (m == 2U)
		return "February";
	else if (m == 3U)
		return "March";
	else if (m == 4U)
		return "April";
	else if (m == 5U)
		return "May";
	else if (m == 6U)
		return "June";
	else if (m == 7U)
		return "July";
	else if (m == 8U)
		return "August";
	else if (m == 9U)
		return "September";
	else if (m == 10U)
		return "October";
	else if (m == 11U)
		return "November";
	else if (m == 12U)
		return "December";

	return "AHH";
}

unsigned Date::number(const string mn) const {
	if (mn == "January" || mn == "january")
		return 1U;
	else if (mn == "February" || mn == "february")
		return 2U;
	else if (mn == "March" || mn == "march")
		return 3U; 
	else if (mn == "April" || mn == "april")
		return 4U;
	else if (mn == "May" || mn == "may")
		return 5U;
	else if (mn == "June" || mn == "june")
		return 6U;
	else if (mn == "July" || mn == "july")
		return 7U;
	else if (mn == "August" || mn == "august")
		return 8U;
	else if (mn == "September" || mn == "september")
		return 9U;
	else if (mn == "October" || mn == "october")
		return 10U;
	else if (mn == "November"|| mn == "november")
		return 11U;
	else if (mn == "December"|| mn == "december")
		return 12U;

	return -1;
}



// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
