#include "ItemToPurchase.h"
#include <vector>

class ShoppingCart {
private:
	string customerName;
	string currentDate;
	vector<ItemToPurchase> cartItems;
public:
	ShoppingCart();
	ShoppingCart(const string&, const string&);
	// Accessors
	const string GetCustomerName() const;
	const string GetDate() const;
	const int GetNumItemsInCart() const;
	const int GetCostOfCart() const;

	const int GetPrice(const string&) const;
	const string GetDescription(const string&) const;
	//Mutators
	void AddItem(const ItemToPurchase&);
	void RemoveItem(const string&);
	void ModifyItem(const ItemToPurchase&);

	void PrintNameAndDate() const;

	void PrintTotal() const;
	void PrintDescription()	const;
};