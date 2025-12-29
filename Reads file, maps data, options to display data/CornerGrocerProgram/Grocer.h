#ifndef GROCER_H_
#define GROCER_H_

#include <string>
#include <map>
#include <vector>
#include <fstream>

class DailyPurchasedItems {

private:

	int menuChoice;
	std::map<std::string, int> dailyGroceryItems;
	int countItem;
	int tempItem;
	std::string _item;
	std::ifstream inFile;
	std::vector<std::string> groceryListVec;
	std::string itemName;

public:

	void CreateList();
	int ScreenOne();
	int MainMenu();
	
};


#endif //GROCER_H_ 