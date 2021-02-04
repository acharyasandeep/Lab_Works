#include <iostream>
#include "ShoppingCart.h"
using namespace std;

void PrintMenu(ShoppingCart &cart)
{
	char option='r';//random character doesn't matter asked for input later;
	
	while (option!='q')
	{
		cout<<"MENU"<<endl;
		cout<<"a - Add item to cart"<<endl;
		cout<<"d - Remove item from cart"<<endl;
		cout<<"c - Change item quantity"<<endl;
		cout<<"i - Output items' descriptions"<<endl;
		cout<<"o - Output shopping cart"<<endl;
		cout<<"q - Quit"<<endl;


		cout<<"Choose an option:"<<endl;
		cin>>option;
		


		
		switch(option)
		{
			case 'o':
				cout<<"OUTPUT SHOPPING CART"<<endl;
				cart.PrintTotal();
				break;
			
			case 'i':
				cout<<"OUTPUT ITEM\'S DESCRIPTIONS"<<endl;
				cart.PrintDescriptions();
				break;

			case 'a':{
					cout<<"ADD ITEM TO CART"<<endl;
					string iname;
					cin.ignore();
					cout<<"Enter the item name:"<<endl;
					getline(cin,iname);
					string description;
					cout<<"Enter the item description:"<<endl;
					getline(cin,description);
					double price;
					cout<<"Enter the item price:"<<endl;
					cin>>price;
					
					double quantity;
					cout<<"Enter the item quantity:"<<endl;
					cin>>quantity;
					ItemToPurchase item(iname,description,price,quantity);

					cart.AddItem(item);
					break;
				  }

			case 'd':
				 {
					 string name;
					 cout<<"REMOVE ITEM FROM CART"<<endl;
					 cout<<"Enter name of item to remove:"<<endl;
					 cin>>name;
					 cart.RemoveItem(name);

				 }
			case 'c':
				 {
					 cout<<"CHANGE ITEM QUANTITY"<<endl;
					 cout<<"Enter the item name:"<<endl;
					 string name;
					 cin>>name;
					 cout<<"Enter the new quantity:"<<endl;
					 int quantity;
					 cin>>quantity;
					 ItemToPurchase it(name);
					 it.SetQuantity(quantity);
					 cart.ModifyItem(it);				 
				 }
			 default:
				 break;
		}
	}
}




int main()
{
	string cname;
	string date;
	cout<<"Enter customer\'s name:"<<endl;
	getline(cin,cname);
	cout<<"Enter today\'s date:"<<endl;
	getline(cin,date);
	
	ShoppingCart cart(cname,date);

	cout<<endl;
	cout<<"Customer name: "<<cart.GetCustomerName()<<endl;
	cout<<"Today\'s date: "<<cart.GetDate()<<endl;

	PrintMenu(cart);

}
