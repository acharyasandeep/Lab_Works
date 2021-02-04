#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include "ItemToPurchase.h"
#include <string>
using namespace std;

class ShoppingCart
{
	private:
		string customerName;
		string currentDate;
		vector<ItemToPurchase> cartItems;
	public:
		ShoppingCart();
		ShoppingCart(string name, string date);
		string GetCustomerName();
		string GetDate();
		void AddItem(ItemToPurchase item);
		void RemoveItem(string name);
		void ModifyItem(ItemToPurchase item);
		int GetNumItemsInCart();
		double GetCostOfCart();
		void PrintTotal();
		void PrintDescriptions();


};


#endif
