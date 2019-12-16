#include "ItemToPurchase.h"
#include <iostream>
typedef unsigned int uint;
ItemToPurchase::ItemToPurchase() {
	itemName = "0";
	itemDescritpion = "none";
	itemPrice = 0;
	itemPrice = 0;
}

ItemToPurchase::ItemToPurchase(const string& name, const int price, const int quantity) : itemName(name), itemPrice(price), itemQuantity(quantity) {}

ItemToPurchase::ItemToPurchase(const string& name, const string& description, const int price, const int quantity) : itemName(name), itemDescritpion(description), itemPrice(price), itemQuantity(quantity) {}

void ItemToPurchase::PrintItemCost() const {
	cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << GetTotalPrice() << endl;
}

void ItemToPurchase::PrintItemDescription() const {
	cout << itemName << ": " << itemDescritpion << endl;
}

const string ItemToPurchase::GetName() const {
	return itemName;
}

const string ItemToPurchase::GetDescription() const {
	return itemDescritpion;
}

const int ItemToPurchase::GetPrice() const {
	return itemPrice;
}

const int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}

const int ItemToPurchase::GetTotalPrice() const {
	return itemPrice * itemQuantity;
}

void ItemToPurchase::SetName(const string& name) {
	itemName = name;
}

void ItemToPurchase::SetDescription(const string& description) {
	itemDescritpion = description;
}

void ItemToPurchase::SetPrice(const int price) {
	itemPrice = price;
}

void ItemToPurchase::SetQuantity(const int quantity) {
	itemQuantity = quantity;
}

const int ItemToPurchase::operator+(const ItemToPurchase& item2) const {
	return (this->GetTotalPrice()) + (item2.GetTotalPrice());
}

const bool ItemToPurchase::operator!=(const ItemToPurchase& item2) const {
	return (this->GetDescription() != item2.GetDescription() || this->GetPrice() != item2.GetPrice() || this->GetQuantity() != item2.GetQuantity());
}