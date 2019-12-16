#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string& str) {
	if (str.empty())
		return;
	string ss = str.substr(1);
	if (str.length() == 0 || str.length() == 1) 
		return;
	else 
		flipString(ss);
	str = ss + str[0];
}


