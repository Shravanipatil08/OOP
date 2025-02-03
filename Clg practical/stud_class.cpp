#include<iostream>
using namespace std;

class student
{
	private:
	  int roll_no;
	  string name;
	  string address;
	public:
	  void getInfo()  
      {
      	cout<<"Enter Roll No: ";
      	cin>>roll_no;
      	cout<<"Enter Name: ";
      	cin>>name;
      	cout<<"Enter Address: ";
      	cin>>address;
	  }
	  void displayInfo()
	  {
	  	cout<<"Roll no: "<<roll_no<<endl<<"Name: "<<name<<endl<<"Address: "<<address<<endl;
	  	//cout<<roll_no<<endl<<name<<endl<<address<<endl;
	  }
};

int main()
{
	student s1;
	s1.getInfo();
	s1.displayInfo();
	return 0;
}
