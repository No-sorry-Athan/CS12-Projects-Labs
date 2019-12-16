#include "ShoppingCart.h"
#include <iostream>
typedef unsigned int uint;

ShoppingCart::ShoppingCart() {
	customerName = "none";
	currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(const string& name, const string& date) : customerName(name), currentDate(date) {}

const string ShoppingCart::GetCustomerName() const {
	return customerName;
}

const string ShoppingCart::GetDate() const {
	return currentDate;
}

const int ShoppingCart::GetNumItemsInCart() const {
	int total = 0;
	for (uint i = 0; i < cartItems.size(); i++) {
		total += cartItems.at(i).GetQuantity();
	}
	return total;
}

const int ShoppingCart::GetCostOfCart() const {
	int total = 0;
	for (uint i = 0; i < cartItems.size(); i++) {
		total += cartItems.at(i).GetTotalPrice();
	}
	return total;
}

void ShoppingCart::AddItem(const ItemToPurchase& item) {
	cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(const string& itemName) {
	bool itemFound = false;
	for (uint i = 0; i < cartItems.size(); i++) {
		if (itemName == cartItems.at(i).GetName()) {
			cartItems.erase(cartItems.begin() + i);
			itemFound = true;
			break;
		}
	}
	if (!itemFound) {
		cout << "Item not found in cart. Nothing removed." << endl;
		cout << endl;
	}
	else
		cout << endl;
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item) {
	bool itemModified = false;
	for (uint i = 0; i < cartItems.size(); i++) {
		if (item.GetName() == cartItems.at(i).GetName()) {	
			if (item != ItemToPurchase()) {
				itemModified = true;
				cartItems.at(i) = item;
			}
		}
	}
	if (!itemModified) {
		cout << "Item not found in cart. Nothing modified." << endl;
		cout << endl;
	}
}

void ShoppingCart::PrintTotal() const {
	if (cartItems.size() < 1) {
		cout << customerName << "'s Shopping Cart - " << currentDate << endl;
		cout << "Number of Items: " << GetNumItemsInCart() << endl;
		cout << endl;
		cout << "SHOPPING CART IS EMPTY" << endl;
		cout << endl;
		cout << "Total: $" << GetCostOfCart() << endl;
		cout << endl;
		return;
	}
	cout << customerName << "'s Shopping Cart - " << currentDate << endl;
	cout << "Number of Items: " << GetNumItemsInCart() << endl;
	cout << endl;
	for (uint i = 0; i < cartItems.size(); i++){
		cartItems.at(i).PrintItemCost();
	}
	cout << endl;
	cout << "Total: $" << GetCostOfCart() << endl;
	cout << endl;
}

void ShoppingCart::PrintDescription() const{
	if (cartItems.size() < 1) {
		cout << "SHOPPING CART IS EMPTY" << endl;
		return;
	}
	cout << customerName << "'s Shopping Cart - " << currentDate << endl;
	cout << endl;
	cout << "Item Descriptions" << endl;
	for (uint i = 0; i < cartItems.size(); i++) {
		cartItems.at(i).PrintItemDescription();
	}
	cout << endl;
}

void ShoppingCart::PrintNameAndDate() const {
	cout << "Customer name: " << customerName << endl;
	cout << "Today's date: " << currentDate << endl;
}

const int ShoppingCart::GetPrice(const string& name) const {
	for (uint i = 0; i < cartItems.size(); i++) {
		if (cartItems.at(i).GetName() == name)
			return cartItems.at(i).GetPrice();
	}

	return -1;
}

const string ShoppingCart::GetDescription(const string& name) const {
	for (uint i = 0; i < cartItems.size(); i++) {
		if (cartItems.at(i).GetName() == name)
			return cartItems.at(i).GetDescription();
	}

	return "";
}