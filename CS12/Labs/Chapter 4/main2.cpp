#include <iostream>

#include "ShoppingCart.h"


using namespace std;

void PrintMenu(ShoppingCart&);
int main() {
	string tempName;
	string tempDate;
	cout << "Enter customer's name:" << endl;
	getline(cin, tempName);
	cout << "Enter today's date:" << endl;
	getline(cin, tempDate);
	cout << endl;
	ShoppingCart cart1(tempName, tempDate);
	cart1.PrintNameAndDate();
	cout << endl;
	PrintMenu(cart1);
	
	return 1;
}

void PrintMenu(ShoppingCart& cart) {
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuant;
	cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	string ch;
	cout << "Choose an option:" << endl;
	cin >> ch;
	while (ch != "q") {
		cin.ignore();
		if (ch == "a") {
			cout << "ADD ITEM TO CART" << endl;
			cout << "Enter the item name:" << endl;
			getline(cin, itemName);
			cout << "Enter the item description:" << endl;
			getline(cin, itemDescription);
			cout << "Enter the item price:" << endl;
			cin >> itemPrice;
			cout << "Enter the item quantity:" << endl;
			cin >> itemQuant;
			cout << endl;
			cart.AddItem(ItemToPurchase(itemName, itemDescription, itemPrice, itemQuant));

			cout << "MENU" << endl;
			cout << "a - Add item to cart" << endl;
			cout << "d - Remove item from cart" << endl;
			cout << "c - Change item quantity" << endl;
			cout << "i - Output items' descriptions" << endl;
			cout << "o - Output shopping cart" << endl;
			cout << "q - Quit" << endl;
			cout << endl;
			cout << "Choose an option:" << endl;
			cin >> ch;
		}
		else if (ch == "d") {
			cout << "REMOVE ITEM FROM CART" << endl;
			cout << "Enter name of item to remove:" << endl;
			getline(cin, itemName);
			
			cart.RemoveItem(itemName);
			cout << "MENU" << endl;
			cout << "a - Add item to cart" << endl;
			cout << "d - Remove item from cart" << endl;
			cout << "c - Change item quantity" << endl;
			cout << "i - Output items' descriptions" << endl;
			cout << "o - Output shopping cart" << endl;
			cout << "q - Quit" << endl;
			cout << endl;
			cout << "Choose an option:" << endl;
			cin >> ch;
		}
		else if (ch == "c") {
			cout << "CHANGE ITEM QUANTITY" << endl;
			cout << "Enter the item name:" << endl;
			getline(cin, itemName);	
			cout << "Enter the new quantity:" << endl;
			cin >> itemQuant;
			itemPrice = cart.GetPrice(itemName);
			itemDescription = cart.GetDescription(itemName);
			cart.ModifyItem(ItemToPurchase(itemName, itemDescription, itemPrice, itemQuant));

			cout << "MENU" << endl;
			cout << "a - Add item to cart" << endl;
			cout << "d - Remove item from cart" << endl;
			cout << "c - Change item quantity" << endl;
			cout << "i - Output items' descriptions" << endl;
			cout << "o - Output shopping cart" << endl;
			cout << "q - Quit" << endl;
			cout << endl;
			cout << "Choose an option:" << endl;
			cin >> ch;
		}
		else if (ch == "i") {
			cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
			cart.PrintDescription();

			cout << "MENU" << endl;
			cout << "a - Add item to cart" << endl;
			cout << "d - Remove item from cart" << endl;
			cout << "c - Change item quantity" << endl;
			cout << "i - Output items' descriptions" << endl;
			cout << "o - Output shopping cart" << endl;
			cout << "q - Quit" << endl;
			cout << endl;
			cout << "Choose an option:" << endl;
			cin >> ch;

		}
		else if (ch == "o") {
			//cin.ignore();
			cout << "OUTPUT SHOPPING CART" << endl;
			cart.PrintTotal();

			cout << "MENU" << endl;
			cout << "a - Add item to cart" << endl;
			cout << "d - Remove item from cart" << endl;
			cout << "c - Change item quantity" << endl;
			cout << "i - Output items' descriptions" << endl;
			cout << "o - Output shopping cart" << endl;
			cout << "q - Quit" << endl;
			cout << endl;
			cout << "Choose an option:" << endl;
			cin >> ch;
		}
		else if (ch == "q") {
			break;
		}
		else
		{
			cout << "Choose an option:" << endl;
			cin >> ch;
		}
		//cout << "Choose an option:" << endl;
		if (ch == "q")break;
	}
}