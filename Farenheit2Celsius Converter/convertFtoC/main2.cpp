#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main() {

	ifstream inFile;
	ofstream outFile;
	string cityName;
	int cityTemp;
	vector<double> cityTempsVec{};
	vector<string> cityNamesVec{};

	inFile.open("FahrenheitTemperature.txt");

	if (inFile.is_open()) {

		while (inFile.good()) {

			inFile >> cityName;
			cityNamesVec.push_back(cityName);
			inFile >> cityTemp;
			cityTempsVec.push_back(cityTemp);


		}
		inFile.close();
		
	}

	for (int i = 0; i < cityTempsVec.size() - 1; ++i) {

		cityTempsVec.at(i) = (cityTempsVec.at(i) - 32) * (5.0 / 9.0);
	}

	outFile.open("CelsiusTemperature.txt");

	if (outFile.is_open()) {

		for (int i = 0; i < cityNamesVec.size() - 1; ++i) {

			outFile << cityNamesVec.at(i) << " ";
			outFile << cityTempsVec.at(i) << endl;
		}
		outFile.close();

	}
	

	return 0;
}