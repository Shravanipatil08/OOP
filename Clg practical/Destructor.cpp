#include<iostream>
using namespace std;

class Demo
{
	private:
		int *p;
	public:
		void getInfo()
		{
			cout<<*p<<endl;
		}
		void setInfo(int v)
		{
			*this->p=v;
		}
		Demo(int x)
		{
			p=new int(x);
		}
		Demo(const Demo &obj)
		{
			//p=obj.p;//Shallow copy
			p=new int(*(obj.p));//Deep copy
		}
		~Demo()
		{
			delete p;//deep copy
			cout<<"Destrustor is Called "<<endl;
		}
};
int main()
{
	//Demo(111)//Here , it creates a object automatically and destroy it and calls destructor
	Demo d1(111);
	d1.getInfo();
	Demo d2(d1);
	d2.getInfo();
	d2.setInfo(222);
	d2.getInfo();
	d1.getInfo();
	d2.~Demo();//object d2 will delete for deep copy but obj d1 will remain 
	//and for shallow copy it will delete d1 and d2 object 
	d1.getInfo();
	d2.getInfo();
	return 0;
	
}
