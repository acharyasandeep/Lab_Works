#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   
   /* Type your code here */

	ItemToPurchase item[2];
	for(int i=0;i<2;i++)
	{
		cin.ignore();
		string name;
		double price;
		int quantity;
		cout<<"Item "<<i+1<<endl;
		cout<<"Enter the item name:"<<endl;
		getline(cin,name);
		item[i].SetName(name);
		cout<<"Enter the item price:"<<endl;
		cin>>price;
		item[i].SetPrice(price);
		cout<<"Enter the item quantity:"<<endl;
		cin>>quantity;
		item[i].SetQuantity(quantity);
		cout<<endl;		
	}

	cout<<"TOTAL COST"<<endl;
	double total=0;
	for(int i=0;i<2;i++)
	{
		
		cout<<item[i].GetName() <<" "<<item[i].GetQuantity()<<" @ $"<<item[i].GetPrice()<<" = $"<<item[i].GetPrice()*item[i].GetQuantity()<<endl;
		total+=item[i].GetPrice()*item[i].GetQuantity();

	}
	cout<<endl<<"Total: $"<<total<<endl;
   
   return 0;
}
