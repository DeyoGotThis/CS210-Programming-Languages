#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main2() {

	ofstream outFile;

	outFile.open("FahrenheitTemperature.txt");

	outFile << "Toronto" << " " << 47 << endl;
	outFile << "Lima" << " " << 66 << endl;
	outFile << "Istanbul" << " " << 57 << endl;
	outFile << "Lagos" << " " << 81 << endl;
	outFile << "Shanghai" << " " << 61 << endl;
	outFile << "Sydney" << " " << 64 << endl;

	outFile.close();

	return 0;
}