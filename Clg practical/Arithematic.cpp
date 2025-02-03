#include<iostream>
using namespace std;
int Add(int a, int b)
{
	return a+b;
}
int Sub(int a, int b)
{
	return a-b;
}
int Div(int a, int b)
{
	return a/b;
}
int Mul(int a, int b)
{
	return a*b;
}
int main()
{
   	cout<<"Additin="<<Add(8,5)<<endl;
   	cout<<"Substraction="<<Sub(95,87)<<endl;
   	cout<<"Multiplication="<<Mul(14,54)<<endl;
  	cout<< "Division="<<Div(76,87)<<endl;
	 
	return 0;	
}
