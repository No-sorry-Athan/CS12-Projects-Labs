#include "ItemToPurchase.h"
#include <iostream>

using namespace std;

int main() {
	string tempStr;
	int tempPrice;
	int tempQuant;
	ItemToPurchase item1;
	
	cout << "Item 1" << endl;
	cout << "Enter the item name:" << endl;
	//cin >> tempStr;
	getline(cin, tempStr);
	item1.SetName(tempStr);
	cout << "Enter the item price:" << endl;
	cin >> tempPrice;
	item1.SetPrice(tempPrice);
	cout << "Enter the item quantity:" << endl;
	cin >> tempQuant;
	item1.SetQuantity(tempQuant);

	cout << endl; 

	cin.ignore();
	ItemToPurchase item2;
	cout << "Item 2" << endl;
	cout << "Enter the item name:" << endl;
	//cin >> tempStr;
	getline(cin, tempStr);
	item2.SetName(tempStr);
	cout << "Enter the item price:" << endl;
	cin >> tempPrice;
	item2.SetPrice(tempPrice);
	cout << "Enter the item quantity:" << endl;
	cin >> tempQuant;
	item2.SetQuantity(tempQuant);
	cin.ignore();

	cout << endl;

	cout << "TOTAL COST" << endl;
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetTotalPrice() << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetTotalPrice() << endl;
	cout << endl;
	cout << "Total: $" << item1 + item2 << endl;
}