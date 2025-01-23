#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	string getItemname[5];
	float price[5];
	float total;
	int i;
//	int n;
//	cout<<"Enter number of items :";
//	cin>>n;
	cout<<"Enter Items and price :"<<endl;
	for(i=0;i<5;i++)
	{
		cin>>getItemname[i];
		cin>>price[i];
	}
	cout<<"Items"<<"\t"<<"Price"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<getItemname[i]<<'\t'<<setw(5)<<price[i]<<endl;
		total+=price[i];
	}
	cout<<"-------------------"<<endl;
	cout<<"Total :"<<"\t"<<setw(5)<<total;//setw is used to align prices to right for lib[iomanip]
	//setfill
	return 0;
}