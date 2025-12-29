/*Functions that increment time*/

#include "AddOneFuncs.h"

/*Function increments seconds.*/
void addOneSecond(int& h, int& m, int& s) {

	/*Function increments seconds on 12 and 24 hour clocks*/

	if ((s >= 0) && (s <= 58)) {     //adds one second from 0 to 58
		s = s + 1;

	}
	else if (s == 59) {              //if second is added to 59, seconds wrap around back to 0
		s = 0;

		addOneMinute(h, m);          //calls function to add minute if second is added to 59
	}
}



/*Function increments minutes.*/
void addOneMinute(int& h, int& m) {

	/*Function increments minutes on 12 and 24 hour clocks*/

	if ((m >= 0) && (m <= 58)) {     //adds one minute from 0 to 58
		m = m + 1;

	}
	else if (m == 59) {              //if minute is added to 59, minutes wrap around back to 0
		m = 0;

		addOneHour(h);               //calls function to add hour if minute is added to 59
	}
}



/*Function increments hours.*/
void addOneHour(int& h) {

	/*Function increments hours on 12 and 24 hour clocks*/

	if ((h >= 0) && (h <= 22)) {     //adds one hour from 0 to 22
		h = h + 1;

	}
	else if (h == 23) {              //if hour is added to 23, hours wrap around back to 0
		h = 0;

	}
}