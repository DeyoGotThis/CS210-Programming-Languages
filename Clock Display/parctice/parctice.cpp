// parctice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void addHun(int& h) {
	h = h + 100;

}

void dubFun(int& h) {
	h = h * 2;
	addHun(h);
	cout << h << endl;

}

int main()
{
	int h = 5;
	dubFun(h);
	cout << h << endl;

	dubFun(h);
	cout << h << endl;






}
