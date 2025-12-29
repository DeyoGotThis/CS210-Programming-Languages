/*****************************************************************************************************
**File        :  Clock Display.cpp
**Description :  Program sets and increments time on 12 and 24 hour clocks.
**Author      :  Daniel Leon
**Date        :  03-25-23

**This program converts 24 hour military time to 12 hour time format and displays both as clocks which
are set by a user.  It then displays an interactive menu where a user can choose from menu options to 
increment clock times**
******************************************************************************************************/

#include <iostream>
#include <string>
#include <windows.h>
#include "AddOneFuncs.h"
using namespace std;


/*Function takes in integers to set times, set maximum menu choices, and loop through
menu choices that increment seconds, minutes and hours on clocks.  It takes user input 
for menu choices, and gives an error message if input is out of range of choices given.*/
int getMenuChoice(int h, int m, int s, int maxChoice);


/*Function takes in an integer and a character, then appends the character
as a string the length of the integer*/
string nCharString(size_t n, char c);


/*Function takes in an integer.  If integer is single digit, function appends a zero at the
front of it and returns as a string.  If double digit, it returns as a string*/
string twoDigitString(int n);


/*Function takes in three integers, one for hours, one for minutes, and one for seconds.
It returns in 24 hour clock format with double digits separated by colons.*/
string formatTime24(int h, int m, int s);


/*Function takes in three integers, one for hours, one for minutes, and one for seconds.
It returns in 12 hour clock format with double digits separated by colons.  Military times
are converted to 12 hour clock times.*/
string formatTime12(int h, int m, int s);


/*Function displays a 12 hour and a 24 hour clock surrounded by a given character, 
with clock titles for each clock.*/
void displayClocks(int h, int m, int s);


/*Function prints a menu of choices for the user.  Choices include adding an hour,
minute or second to displayed clocks.  Last option is to exit program.*/
void printMenu(char* strings[], int numStrings, char width);





/*Function is main function where other functions are called and program
is executed.*/
int main() {
	int h = 0;                              //integer used for hours
	int m = 0;                              //integer used for minutes
	int s = 0;                              //integer used for seconds

	cout << "Set Clocks:" << endl;          //Prompts user to set times on clocks
	cout << "Hour: ";
	cin >> h;                               //hour is set
	cout << "Minute: ";
	cin >> m;                               //minutes are set
	cout << "Second: ";
	cin >> s;                               //seconds are set

	system("cls");                          //clears screen for cleaner display

	displayClocks(h, m, s);                 //displays 12 and 24 hour clocks with times set by user

	getMenuChoice(h,m,s,4);                 //defines menu choices, displays menu, takes user input, loops through choices
	                                        //of incrementing clock times until program is exited.

	

}



/*Function gets user input to choose from menu.*/
int getMenuChoice(int h, int m, int s, int maxChoice) {

	/*Function defines menu array, prints menu, then enters menu choice loop
	which takes user input and increments clock values until maxChoice is selected, 
	which then exits program.  If user input is out of range of choices given, function
	sends error message.*/

	char* strings[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };  //menu array,list of options

	printMenu(strings, 4, 26);               //prints menu options

	int input = 0;                           //for user input to be taken

	while (input != maxChoice) {             //enters menu choice loop and takes input from user

		cout << "Choose from the menu:  ";
		cin >> input;

		while (input != maxChoice) {         //enters inner loop to break after each choice without breaking out of main loop until prompted

			if (input == 1) {                //input to increment hours, clears screen and displays new time
				addOneHour(h);
				system("cls");
				displayClocks(h, m, s);
				printMenu(strings, 4, 26);
				break;
			}
			else if (input == 2) {           //input to increment minutes, clears screen and displays new time
				addOneMinute(h, m);
				system("cls");
				displayClocks(h, m, s);
				printMenu(strings, 4, 26);
				break;
			}
			else if (input == 3) {           //input to increment seconds, clears screen and displays new time
				addOneSecond(h, m, s);
				system("cls");
				displayClocks(h, m, s);
				printMenu(strings, 4, 26);
				break;
			}
			else if (input < 1 || input > 4) {                      //displays error message for invalid inputs
				cout << "Error, try again. Options are 1 - 4. ";
				break;
			}
		}
	}
	system("cls");                                                  //loop is broken, clears screen, displays goodbye message and exits program
	cout << "Goodbye, until next time!\n\n\n\n\n";
	return 0;
}



/*Function creates character string with length of integer.*/
string nCharString(size_t n, char c) {

	/*Function takes in a character and an integer, returns a string of said character
	with the length of the given integer*/

	string charStr;                               //string to be returned

	for (int i = 1; i <= n; ++i) {                //loops and appends given character until loop number is equal to integer
		charStr.push_back(c);
	}
	return charStr;                               //returns character string the length of the given integer
}



/*Function converts one digit to two, returns as string.*/
string twoDigitString(int n) {

	/*Function takes in a single digit integer and appends it to the end of a zero, returns as a string */

	if (n < 10) {                                           //defines integers to be appended
		std::string zeroStr = "0" + std::to_string(n);      //appends zero to single digit as string
		return zeroStr;                                     //returns double digit "zero" string
	}
	else {
		std::string nonZeroStr = std::to_string(n);         //converts double digit integers to string
		return nonZeroStr;                                  //returns double digit "non-zero" string
	}
}



/*Function returns time in 24 hour format.*/
string formatTime24(int h, int m, int s) {

	/*Function returns time in military format*/

	return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);   //calls function to return double digit strings
}



/*Function returns time in 12 hour format.*/
string formatTime12(int h, int m, int s) {

	/*Function returns time in 12-hour format */


	if (h > 12) {                                                                                //converts military times to 12-hour format
		h -= 12;
		return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";   //returns said format as pm times of day
	}
	else if (h == 12) {                                                                          //12 noon is defined as a pm time
		return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
	}
	else if (h == 0) {                                                                            
		h = 12;                                                                                  //0 hour converted to 12 am
		return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";   
	}
	else {                                                                                       //other times of day remain same and are am
		return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
	}
}



/*Function displays 12 and 24 hour interactive clocks.*/
void displayClocks(int h, int m, int s) {

	/*Function takes in integers and calls multiple functions to display clocks in 12 and 24 hour formats*/

	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;                                                         //displays top character string

	cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');  //displays 12 hour clock title
	 
	cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;                 //displays 24 hour clock title

	cout << endl;

	cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');  //displays 12 hour clock

	cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;                 //displays 24 hour clock

	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;                                                               //displays bottom character string

}



/*Function prints menu options.*/
void printMenu(char * strings[], int numStrings, char width) {

	/*Function displays menu choices listed 1 through 4 with character string design*/

	int lengthOfStrings[4] = { 12,14,14,12 };      //array of lengths of menu option strings, used to calculate trailing whitespace

	cout << nCharString(width, '*') << endl;       //prints string of character across top of menu

	for (int i = 1; i <= numStrings; ++i) {        //enters loop for menu option printing
		if (i < numStrings) {
			cout << "* " << i << " - " << strings[i - 1] << nCharString(width - lengthOfStrings[i - 1] - 7, ' ') << "*" << endl << endl;  //prints numbered menu options and newline
		}
		else {
			cout << "* " << i << " - " << strings[i - 1] << nCharString(width - lengthOfStrings[i - 1] - 7, ' ') << "*" << endl;          //prints last menu option without newline
		}
	}
	cout << nCharString(width, '*') << endl;       //prints string of characters across bottom of menu
}


