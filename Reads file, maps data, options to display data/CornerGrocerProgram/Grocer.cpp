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


void DailyPurchasedItems::CreateList() {

	inFile.open("CS210_Project_Three_Input_File.txt");

	if (inFile.is_open()) {

		while (inFile.good()) {

			inFile >> itemName;
			groceryListVec.push_back(itemName);

		}
		inFile.close();

	}

}


int DailyPurchasedItems::ScreenOne() {

	for (int i = 0; i < groceryListVec.size(); ++i) {

		countItem = count(groceryListVec.begin(), groceryListVec.end(), groceryListVec.at(i));

		tempItem = dailyGroceryItems.count(groceryListVec.at(i));

		while (tempItem == 0) {

			dailyGroceryItems.emplace(groceryListVec.at(i), countItem);
			tempItem = 1;

			cout << groceryListVec.at(i) << " " << countItem << endl;
		}

	}


	while ((_item != "M") && (_item != "E")) {

		cout << "Search for an item:     (M for Main Menu, E for Exit)" << endl;

		cin >> _item;
		_item[0] = toupper(_item[0]);
		
		if (_item[-1] != 's') {
			_item.append("s");
		}

		cout << dailyGroceryItems.at(_item) << endl;

		cout << "Enter to search again";

		_getwch();
		system("CLS");

	}

	if (_item == "M") {

		system("CLS");
		MainMenu();
	}
	else if (_item == "E") {

		return 0;
		
	}

}


int DailyPurchasedItems::MainMenu() {

	cout << "____________________________" << endl << endl << "Choose from the menu" << endl << "____________________________" << endl << endl;

	cout << "[1] Look up item" << endl;
	cout << "[2] List of items" << endl;
	cout << "[3] Histogram of items" << endl;
	cout << "[4] Exit Program" << endl;

	cin >> menuChoice; 

	if (menuChoice == 1) {

		system("CLS");
		ScreenOne();
	}
	else if (menuChoice == 4) {

		return 0;
	}

}