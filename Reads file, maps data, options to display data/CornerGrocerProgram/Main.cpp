#include "Grocer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <map>
using namespace std;



int main() {

	/*ifstream inFile;
	vector<string> groceryListVec;
	string itemName;
	map<string, int> dailyGroceryItems;
	int countItem;
	int tempItem;
	string _item;
	int menuChoice;*/


	


	/*for (int i = 0; i < groceryListVec.size(); ++i) {

		countItem = count(groceryListVec.begin(), groceryListVec.end(), groceryListVec.at(i));
        
		tempItem = dailyGroceryItems.count(groceryListVec.at(i));

		while (tempItem == 0) {

			dailyGroceryItems.emplace(groceryListVec.at(i), countItem);
			tempItem = 1;

			cout << groceryListVec.at(i) << " " << countItem << endl;
		}

	}*/


	/*string tempS;
	cin >> tempS;
	tempS[0] = toupper(tempS[0]);
	cout << dailyGroceryItems.at(tempS);*/
	
	DailyPurchasedItems itemSearch;
	
	itemSearch.CreateList();

	itemSearch.MainMenu();

	return 0;
}