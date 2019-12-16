#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string, char);


int main() {

	string filename;
	char ch;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;
	cout << "Enter a character: ";

	cin.ignore(); // ignores newline left in stream after previous input statement
	cin.get(ch);
	cout << endl;

	cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;

	return 0;
}

int charCnt(string flName, char ch) {
	ifstream fileReader;
	char temp;
	int cnt = 0;

	fileReader.open(flName);
	if (!fileReader.is_open()) {
		cout << "Error opening " << flName << endl;
		fileReader.close();
		exit(1);
	}

	for (;;) {
		temp = fileReader.get(); // >> would get rid of blank spaces (could be seen in last lab where it didn't add ' ', whereas get just gets the next thing no matter what it is
		if (fileReader.fail()) // same thing to make sure its still in file
			break;
		if (temp == ch)
			cnt++;
	}
	fileReader.close();
	return cnt;
}

// Place charCnt implementation here