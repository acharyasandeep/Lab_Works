#include <iostream>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart()
{
	customerName="none";
	currentDate="January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date)
{
	customerName=name;
	currentDate=date;
}

string ShoppingCart::GetCustomerName()
{
	return customerName;
}

string ShoppingCart::GetDate()
{
	return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item)
{
	cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name)
{

	int j=0;
	int i=0;
	for(;i<cartItems.size();i++)
	{
		if(name!=cartItems.at(i).GetName())
		{
			cartItems.at(j)=cartItems.at(i);
			j++;
		}

	}
	if(i==j) //item not found if found j would not increase upto i
		cout<<"Item not found in cart. Nothing removed.";
	else
		cartItems.pop_back(); //item found so one last item remained in vector
}

void ShoppingCart::ModifyItem(ItemToPurchase item)
{
	int i=0;
	for(;i<cartItems.size();i++)
	{
		if(cartItems.at(i).GetName()==item.GetName())
		{
			if(cartItems.at(i).GetDescription()!="none")
			{
				cartItems.at(i).SetDescription(item.GetDescription());
			}
			
			if(cartItems.at(i).GetPrice()!=0)
			{
				cartItems.at(i).SetPrice(item.GetPrice());

			}

			if(cartItems.at(i).GetQuantity()!=0)
			{
				cartItems.at(i).SetQuantity(item.GetQuantity());
			}
			break;
		}
	}
	if(i==cartItems.size())
		cout<<"Item not found in cart. Nothing modified.";
			
}

int ShoppingCart::GetNumItemsInCart()
{
	int total=0;
	for(int i=0;i<cartItems.size();i++)
		total+=cartItems.at(i).GetQuantity();
	return total;
}

double ShoppingCart::GetCostOfCart()
{
	double total=0;
	for(int i=0;i<cartItems.size();i++)
		total+=cartItems.at(i).GetQuantity()*cartItems.at(i).GetPrice();
	return total;

}

void ShoppingCart::PrintTotal()
{
	cout<<customerName<<"'s Shopping Cart - "<<currentDate<<endl;
	cout<<"Number of items: "<<GetNumItemsInCart()<<endl<<endl;
	for(int i=0;i<cartItems.size();i++)
	{
		 cout<<cartItems.at(i).GetName() <<" "<<cartItems.at(i).GetQuantity()<<" @ $"<<cartItems.at(i).GetPrice()<<" = $"<<cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity()<<endl;

        }
        cout<<endl<<"Total: $"<<GetCostOfCart()<<endl;


}

void ShoppingCart::PrintDescriptions()
{
	cout<<customerName<<"'s Shopping Cart - "<<currentDate<<endl<<endl;
	cout<<"Item Descriptions"<<endl;

	for(int i=0;i<cartItems.size();i++)
		cout<<cartItems.at(i).GetName()<<": "<<cartItems.at(i).GetDescription()<<endl;





}



