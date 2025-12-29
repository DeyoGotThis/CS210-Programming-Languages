/*Functions that increment time*/

#ifndef ADDONEFUNCS_H
#define ADDONEFUNCS_H

/*Function takes in an integer and adds an hour to both 12 and 24 hour clocks.
If hours exceed 23, they wrap around to zero.*/
void addOneHour(int& h);


/*Function takes in two integers and adds a minute to both 12 and 24 hour clocks.
If minutes exceed 59, they wrap around to zero and addOneHour() function is called.*/
void addOneMinute(int& h, int& m);


/*Function takes in three integers and adds a second to both 12 and 24 hour clocks.
If seconds exceed 59, they wrap around to zero and addOneMinute() function is called.*/
void addOneSecond(int& h, int& m, int& s);



#endif 