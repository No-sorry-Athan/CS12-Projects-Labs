#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned int _uint;

void convertFromAscii(int &temp) {
	temp -= 48; // (1 in Ascii is 49, -48 would give it proper value of 1, 50 - 48 = 2, etc)
}

int main(int argc, char* argv[]) {
	string inputFile;
	string outputFile;
	vector<int> vec;
	int temp;

	inputFile = argv[1];
	outputFile = argv[2];

	ifstream inSt(inputFile);
	//inSt.open(inputFile);
	if (!inSt.is_open()) {
		cout << "Error opening " << inputFile << endl;
		return 1;
	}
	//int prevTemp = 44;
	//for (;;) {
	//	//inSt >> temp;

	//	temp = inSt.get();
	//	
	//	if (inSt.fail())
	//		break;
	//	if (prevTemp != 44 && temp != 44) {
	//		convertFromAscii(temp);
	//		convertFromAscii(prevTemp);
	//		int convertToDoubleDigit = prevTemp * 10 + temp;
	//		vec.push_back(convertToDoubleDigit);           
	//		vec.erase(vec.begin() + vec.size() - 2);		
	//	}												
	//	else {
	//		prevTemp = temp;
	//		if (temp != 44) {
	//			convertFromAscii(temp);
	//			vec.push_back(temp);
	//		}
	//	}
	int num;
	char z;
	while (inSt >> num ){
		inSt >> z;
		vec.push_back(num);
	}

	inSt.close();

	int total = 0;
	for (_uint i = 0; i < vec.size(); i++) {
		total += vec.at(i);
	}
	
	int avg = total / vec.size();

	for (_uint i = 0; i < vec.size(); i++)
		vec.at(i) -= avg;
	

	ofstream ofStr;
	ofStr.open(outputFile);
	if (!ofStr.is_open()) {
		cout << "Error creating " << outputFile << endl;
		return 1;
	}
	
	for (_uint i = 0; i < vec.size(); i++) {
		if (i != vec.size() - 1)
			ofStr << vec.at(i) << ",";
		else
			ofStr << vec.at(i);
	}
	ofStr.close();
	
	return 0;
}