#include<iostream>
using namespace std;

class Circle{
	private:
		float r,area;
	
	public:
		Circle()
		{
			cout<<"Enter Radius: ";
			cin>>r;
			area = 3.142*r*r;
			cout<<"Area of circle is "<<area<<endl;
		}
		Circle(float r1)
		{
			r = r1;
			area = 3.142*r*r;
			cout<<"Area of circle is "<<area<<endl;
		}
		Circle(Circle &obj)
		{
			r = obj.r;
			area = 2*3.142*r;
			cout<<"Circumference of circle is "<<area<<endl;
		}
		~Circle();
};

int main()
{
	Circle obj1;
    Circle obj2(5.5);
	Circle obj3(obj2);
	return 0;
}
Circle::~Circle()
{
	cout<<"Destructor runs"<<endl;
}
