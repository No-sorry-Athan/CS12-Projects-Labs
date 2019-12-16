#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here

int fileSum(string);

int main() {
	string filename;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;

	cout << "Sum: " << fileSum(filename) << endl;

	return 0;
}

// Place fileSum implementation here

int fileSum(string flName) {
	ifstream fileReader;
	fileReader.open(flName);
	int temp;
	int sum = 0;

	if (!fileReader.is_open()) {
		cout << "Error opening " << flName << endl;
		fileReader.close();
		exit(1);
	}

	for (;;) {
		fileReader >> temp; 
		if (fileReader.fail()) // end of file wouldn't be checked until the full loop goes through, therefore instead of doing while (!fileReader.eof()), we should use an if statement
			break;            // after reading the next line in order to see if the file actually reached its end
		sum += temp;
		/*cout << "Temp: " << temp << endl;
		cout << "Sum: " << sum << endl;*/
	}
	fileReader.close();
	return sum;
}