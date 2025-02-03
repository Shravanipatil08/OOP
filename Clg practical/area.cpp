#include<iostream>
using namespace std;

class Area
{
	public:
	void area_of_circle(float r)
	{
		cout<<"Area of circle: "<<3.14*r*r<<endl;
	}
		void Area_of_triangle(float h,float b)
	{
		cout<<"Area of triangle: "<<0.5*h*b<<endl;
	}
		void Area_of_square(float side)
	{
		cout<<"Area of square: "<<side*side<<endl;
	}
		void Area_of_rectangle(float l,float b)
	{
		cout<<"Area of circle: "<<l*b<<endl;
	}
};

int main()
{
	Area a;
	a.area_of_circle(3);
	a.Area_of_triangle(3,4);
	a.Area_of_square(5);
	a.Area_of_rectangle(2,6);
	return 0;
}


