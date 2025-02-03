#include<iostream>
using namespace std;
int main()
{
	int n,fact=1;
	cout<<"Enter number for factorial ="<<endl;
	cin>>n;
	int i;
	for (i=n; i>0; i--)
	{
	 fact = fact*i;
	}
	cout<<"factorial of given number is:"<<fact<<endl;
	
	return 0;
}

