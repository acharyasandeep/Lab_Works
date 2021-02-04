#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H
#include <vector>
#include <string>
using namespace std;

/* Type your code here */
class ItemToPurchase
{
	private:
		string itemName;
		double itemPrice;
		int itemQuantity;
		string itemDescription;
	public:
		ItemToPurchase();
		ItemToPurchase(string name,string description="none",double price=0,int quantity=0);
		void SetDescription(string description);
		string GetDescription();
		void PrintItemCost();
		void PrintItemDescription();
		void SetName(string name);
		string GetName();
		void SetPrice(double price);
		double GetPrice();
		void SetQuantity(int quantity);
		int GetQuantity();
   
};

#endif

