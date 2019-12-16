#include <iostream>
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int>&, const vector<int>&);
void addPlayer(vector<int>&, vector<int>&);
void removePlayer(vector<int>&, vector<int>&);
void updatePlayerRating(const vector<int>&, vector<int>&);
void outputPlayersAboveRating(const vector<int>&, const vector<int>&);

// just calls for the 5 initial players + outputs them
void initialRun(vector<int>&, vector<int>&);

void menu(vector<int>&, vector<int>&);

int main() {
	vector<int> jersey;
	vector<int> rating;

	initialRun(jersey, rating);

	menu(jersey, rating);
	return 0;
}

void initialRun(vector<int>& jersey, vector<int>& rating) {
	int tempNum;
	cout << "Enter player 1's jersey number:" << endl;
	cin >> tempNum;
	jersey.push_back(tempNum);

	cout << "Enter player 1's rating:" << endl;
	cout << "\n";
	cin >> tempNum;
	rating.push_back(tempNum);

	cout << "Enter player 2's jersey number:" << endl;
	cin >> tempNum;
	jersey.push_back(tempNum);

	cout << "Enter player 2's rating:" << endl;
	cout << "\n";
	cin >> tempNum;
	rating.push_back(tempNum);

	cout << "Enter player 3's jersey number:" << endl;
	cin >> tempNum;
	jersey.push_back(tempNum);

	cout << "Enter player 3's rating:" << endl;
	cout << "\n";
	cin >> tempNum;
	rating.push_back(tempNum);

	cout << "Enter player 4's jersey number:" << endl;
	cin >> tempNum;
	jersey.push_back(tempNum);

	cout << "Enter player 4's rating:" << endl;
	cout << "\n";
	cin >> tempNum;
	rating.push_back(tempNum);

	cout << "Enter player 5's jersey number:" << endl;
	cin >> tempNum;
	jersey.push_back(tempNum);

	cout << "Enter player 5's rating:" << endl;
	cout << "\n";
	cin >> tempNum;
	rating.push_back(tempNum);

	outputRoster(jersey, rating);
}

void outputRoster(const vector<int>& jersey, const vector<int>& rating)
{
	int rosterSize = jersey.size();
	cout << "ROSTER" << endl;
	for (int i = 0; i < rosterSize; i++) {
		cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << "\n";
	}
	cout << endl;
}

void addPlayer(vector<int>& jersey, vector<int>& rating) {
	int tempNum;
	cout << "Enter another player's jersey number:" << endl;

	cin >> tempNum;
	jersey.push_back(tempNum);

	cout << "Enter another player's rating:" << endl;
	cin >> tempNum;
	rating.push_back(tempNum);

	cout << endl;
}

void removePlayer(vector<int>& jersey, vector<int>& rating) {
	int rosterSize = jersey.size();
	int tempVal;
	cout << "Enter a jersey number: " << endl;
	cin >> tempVal;

	int index = -1;
	for (int i = 0; i < rosterSize; i++) {
		if (jersey.at(i) == tempVal) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		for (int i = index; i < rosterSize - 1; i++) {
			jersey.at(i) = jersey.at(i + 1);
			rating.at(i) = rating.at(i + 1);
		}
		jersey.pop_back();
		rating.pop_back();
	}
}

void updatePlayerRating(const vector<int>& jersey, vector<int>& rating) {
	int vectorSize = jersey.size();
	int tempJersey;
	cout << "Enter a jersey number: " << endl;
	cin >> tempJersey;

	int tempRating;
	cout << "Enter a new rating: " << endl;
	cin >> tempRating;

	for (int i = 0; i < vectorSize; i++) {
		if (jersey.at(i) == tempJersey) {
			rating.at(i) = tempRating;
		}
	}
}

void outputPlayersAboveRating(const vector<int>& jersey, const vector<int>& rating) {
	int tempRating;
	int vectorSize = jersey.size();

	cout << "Enter a rating: " << endl;
	cin >> tempRating;
	cout << "ABOVE " << tempRating << endl;

	for (int i = 0; i < vectorSize; i++) {
		if (rating.at(i) > tempRating)
			cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
	}
	cout << endl;
}

void menu(vector<int>& jersey, vector<int>& rating) {
	cout << "MENU";
	cout << endl;
	cout << "a - Add player" << endl;
	cout << "d - Remove player" << endl;
	cout << "u - Update player rating" << endl;
	cout << "r - Output players above a rating" << endl;
	cout << "o - Output roster" << endl;
	cout << "q - Quit";
	cout << "\n" << endl;

	cout << "Choose an option:" << endl;

	string str;
	cin >> str;
	while (str != "q")
	{
		if (str == "a") {
			addPlayer(jersey, rating);
			cout << "MENU" << endl;
			cout << "a - Add player" << endl;
			cout << "d - Remove player" << endl;
			cout << "u - Update player rating" << endl;
			cout << "r - Output players above a rating" << endl;
			cout << "o - Output roster" << endl;
			cout << "q - Quit";
			cout << "\n" << endl;
			cout << "Choose an option:" << endl;
			cin >> str;
		}
		else if (str == "d") {
			removePlayer(jersey, rating);
			cout << "MENU" << endl;
			cout << "a - Add player" << endl;
			cout << "d - Remove player" << endl;
			cout << "u - Update player rating" << endl;
			cout << "r - Output players above a rating" << endl;
			cout << "o - Output roster" << endl;
			cout << "q - Quit";
			cout << "\n" << endl;
			cout << "Choose an option:" << endl;
			cin >> str;
		}
		else if (str == "u") {
			updatePlayerRating(jersey, rating);
			cout << "MENU" << endl;
			cout << "a - Add player" << endl;
			cout << "d - Remove player" << endl;
			cout << "u - Update player rating" << endl;
			cout << "r - Output players above a rating" << endl;
			cout << "o - Output roster" << endl;
			cout << "q - Quit";
			cout << "\n" << endl;
			cout << "Choose an option:" << endl;
			cin >> str;
		}
		else if (str == "r") {
			outputPlayersAboveRating(jersey, rating);
			cout << "MENU" << endl;
			cout << "a - Add player" << endl;
			cout << "d - Remove player" << endl;
			cout << "u - Update player rating" << endl;
			cout << "r - Output players above a rating" << endl;
			cout << "o - Output roster" << endl;
			cout << "q - Quit";
			cout << "\n" << endl;
			cout << "Choose an option:" << endl;
			cin >> str;
		}
		else if (str == "o") {
			outputRoster(jersey, rating);
			cout << "MENU" << endl;
			cout << "a - Add player" << endl;
			cout << "d - Remove player" << endl;
			cout << "u - Update player rating" << endl;
			cout << "r - Output players above a rating" << endl;
			cout << "o - Output roster" << endl;
			cout << "q - Quit";
			cout << "\n" << endl;
			cout << "Choose an option:" << endl;
			cin >> str;
		}
		else if (str == "q") {
			break;
		}
		else {
			cin >> str;
		}
	}
}
