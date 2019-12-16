#include <string>

using namespace std;

class ItemToPurchase {
private:
	string itemName;
	string itemDescritpion;
	int itemPrice;
	int itemQuantity;
public:
	ItemToPurchase();
	ItemToPurchase(const string&, const int, const int);
	ItemToPurchase(const string&, const string&, const int, const int);
	//	Accessors
	const string GetName() const;
	const string GetDescription() const;
	const int GetPrice() const;
	const int GetQuantity() const;
	const int GetTotalPrice() const;
	//	Mutators
	void SetName(const string&); 
	void SetDescription(const string&);
	void SetPrice(const int);
	void SetQuantity(const int);

	void PrintItemCost() const;
	void PrintItemDescription() const;

	const int operator+(const ItemToPurchase&)const;
	const bool operator!=(const ItemToPurchase&)const;
};