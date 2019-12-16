#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <sstream>

typedef unsigned int uint;
using namespace std;

void readData(const string&, vector<double>&, vector<double>&);
double interpolation(double, const vector<double>&, const vector<double>&);
bool isOrdered(const vector<double>&);
void reorder(vector<double>&, vector<double>&);
void printVector(const vector<double>&, const vector<double>&);
bool isValidAng(vector<double>&, vector<double>&, double);
uint indexNewAng(double, const vector<double>&, const vector<double>&);
bool angExisting(double, const vector<double>&, const vector<double>&);
void addIntoVector(double, double, int, vector<double>&, vector<double>&);

int main(int argc, char* argv[]) {
	vector<double> flightAng;
	vector<double> coeffLift;
	string inputFile;
	
	inputFile = argv[1];

	readData(inputFile, flightAng, coeffLift);
	printVector(flightAng, coeffLift);

	if (!isOrdered(flightAng)) {
		cout << "Not ordered... reordering now" << endl;
		reorder(flightAng, coeffLift);
		printVector(flightAng, coeffLift);
	}
	else
		cout << "Ordered properly" << endl;

	cout << "Enter a flight path angle: " << endl;
	double tempAng;
	cin >> tempAng;
	if (isValidAng(flightAng, coeffLift, tempAng)) {
		uint index = indexNewAng(tempAng, flightAng, coeffLift);
		double newCoeff = interpolation(tempAng, flightAng, coeffLift);
		cout << "New Angle Index: " << index << endl;
		cout << "New Coeff Lift: " << newCoeff << endl;
		addIntoVector(tempAng, newCoeff, index, flightAng, coeffLift);
		printVector(flightAng, coeffLift);
	}
	else
		cout << "Not a valid angle " << endl;

	cout << "Would you like to enter another angle? " << endl;
	string str;
	while (cin >> str){
		if (str == "No" )
			break;
		else if (str == "Yes") {
			cout << "Enter a flight path angle: " << endl;
			double tempAng;
			cin >> tempAng;
			if (isValidAng(flightAng, coeffLift, tempAng)) {
				uint index = indexNewAng(tempAng, flightAng, coeffLift);
				double newCoeff = interpolation(tempAng, flightAng, coeffLift);
				cout << "New Angle Index: " << index << endl;
				cout << "New Coeff Lift: " << newCoeff << endl;
				addIntoVector(tempAng, newCoeff, index + 1, flightAng, coeffLift);
				printVector(flightAng, coeffLift);
			}
			else
				cout << "Not a valid angle " << endl;

			cout << "Would you like to enter another angle? " << endl;
		}
		else {
			cout << "Not a valid response, please enter again" << endl;
		}
		
	}
	return 0;
}

void readData(const string& str, vector<double>& angles, vector<double>& lift) {
	ifstream fIn;
	fIn.open(str);

	if (!fIn.is_open()) { //standard check for file being open
		cout << "Error opening " << str << endl;
		fIn.close();
		exit(1);
	}

	double n, m;
	istringstream iss;
	while (fIn >> n >> m) {
		angles.push_back(n);
		lift.push_back(m);
	}
	fIn.close();
}

double interpolation(double val, const vector<double>& angles, const vector<double>& lift) {
	//dont need to do order check because that is already done in valid ang
	uint index = indexNewAng(val, angles, lift);
	if (index < 0 || index >= angles.size()) {
		cout << "Out of bounds error" << endl;
		exit(1);
	}
		
	if (!angExisting(val, angles, lift)) {
		double a, c, fofA, fofC;
		a = angles.at(index - 1);
		c = angles.at(index);

		fofA = lift.at(index - 1);
		fofC = lift.at(index);

		return fofA + ((val - a) / (c - a)) * (fofC - fofA);
	}
	return lift.at(index);

	// f(b) = f(a) + ( ( b - a ) / ( c - a ) ) ( f ( c ) - f ( a ) )

	// f(a) = lift at index a
	// f(c) = lift at index c
	// a = angle at index a
	// b = val
	// c = angle at index c
}

bool isOrdered(const vector<double>& angles) {
	for (uint i = 1; i < angles.size(); i++) {
		if (angles.at(i) < angles.at(i - 1))
			return false;
	}
	return true;
}

void reorder(vector<double>& angles, vector<double>& lift) {
	for (uint i = 0; i < angles.size(); i++) {
		int minIndex = i;
		for (uint j = i + 1; j < angles.size(); j++) {
			if (angles.at(j) < angles.at(minIndex))
				minIndex = j;
		}
		auto tempAng = angles.at(i);
		auto tempLift = lift.at(i);

		angles.at(i) = angles.at(minIndex);
		lift.at(i) = lift.at(minIndex);

		angles.at(minIndex) = tempAng;
		lift.at(minIndex) = tempLift;
	}
}

void printVector(const vector<double>& angles, const vector<double>& lift) {
	for (uint i = 0; i < angles.size(); i++) {
		cout << angles.at(i) << "\t" << lift.at(i) << endl; // test to see if file corrrectly read to vectors
	}
}

bool isValidAng(vector<double>& ang, vector<double>& lift, double val) {
	if (!isOrdered(ang))
		reorder(ang, lift);
	return (val >= ang.at(0) && val <= ang.back());
	
}

uint indexNewAng(double val, const vector<double>& angles, const vector<double>& lift) {
	if (!angExisting(val, angles, lift)) {
		uint index = -1;
		for (uint i = 1; i < angles.size(); i++) {
			if (val >= angles.at(i - 1) && val <= angles.at(i)) {
				index = i;
				break;
			}
		}
		return index;
	}
	for (uint i = 0; i < angles.size(); i++) {
		if (val == angles.at(i))
			return i;
	}
	return -1;
}

bool angExisting(double val, const vector<double>& angles, const vector<double>& lift) {
	for (uint i = 0; i < angles.size(); i++) {
		if (val == angles.at(i))
			return true;
	}
	return false;
}

void addIntoVector(double angVal, double coeff, int index, vector<double>& angles, vector<double>& lift) {
	if (!angExisting(angVal, angles, lift)) {
		angles.insert(angles.begin() + index, angVal);
		lift.insert(lift.begin() + index, coeff);
		if (!isOrdered(angles))
			reorder(angles, lift);
	}
}
