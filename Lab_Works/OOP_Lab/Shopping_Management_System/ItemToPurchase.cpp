#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */
//default constructor
ItemToPurchase::ItemToPurchase()
{
   itemName="none";
   itemPrice=0;
   itemQuantity=0;
}

ItemToPurchase::ItemToPurchase(string name,string description,double price,int quantity)
{
	itemName = name;
	itemDescription = description;
	itemPrice = price;
	itemQuantity = quantity;
}

void ItemToPurchase::SetDescription(string description)
{
	itemDescription = description;
}

string ItemToPurchase::GetDescription()
{
	return itemDescription;
}

void ItemToPurchase::PrintItemCost()
{
	cout<<itemName<<" "<<itemQuantity<<" @  $"<<itemPrice<<" = $"<<itemPrice*itemQuantity<<endl;
}

void ItemToPurchase::PrintItemDescription()
{
	cout<<itemName<<": "<<itemDescription<<endl;

}

void ItemToPurchase::SetName(string name)
{
	itemName = name;
}

string  ItemToPurchase::GetName()
{
	return itemName;
}

void ItemToPurchase::SetPrice(double price)
{
	itemPrice = price;
}

double ItemToPurchase::GetPrice()
{
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity)
{
	itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity()
{
	return itemQuantity;
}

