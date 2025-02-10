#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount 
{
	private:
    	string accountHolder;
    	int accountNumber;
    	string accountType;
    	double balance;

	public:
    	// Default constructor
    	BankAccount()
    	{
    		accountHolder = "Neha Patil";
    		accountNumber = 987656;
    		accountType = "saving";
    		balance = 3000;
		}

    	// Parameterized constructor
    	BankAccount(string holder, int number, string type, double bal) 
		{
			accountHolder = holder;
    		accountNumber = number;
    		accountType = type;
    		balance = bal;
		}

    	// Accessor methods
    	string getAccountHolder() 
		{ 
			return accountHolder; 
		}
    	int getAccountNumber() 
		{ 
			return accountNumber; 
		}
    	string getAccountType() 
		{ 
			return accountType; 
		}
    	double getBalance() 
		{ 
			return balance; 
		}

    	// method for account type
    	void setAccountType(string newType) { accountType = newType; }

    	// Deposit method with validation
    	void deposit(double amount) 
		{
        	if (amount > 0) 
			{
            	balance += amount;
            	cout << "Depositing "<< amount << "..." << endl;
            	cout << "New Balance: "<< balance << endl;
        	} 
			else 
			{
            	cout << "Invalid deposit amount!" << endl;
       		}
    	}

    	// Withdraw method with validation
    	void withdraw(double amount) 
		{
        	if (amount > 0 && amount <= balance) 
			{
            	balance -= amount;
            	cout << "Withdrawing " << amount << "..." << endl;
            	cout << "New Balance: "<< balance << endl;
        	} 
			else 
			{
        	    cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        	}
    	}

    	// Display formatted account details
    	void displayAccountDetails() 
		{
        	cout << "Account Details:" << endl;
        	cout << "Holder: " << accountHolder << endl;
        	cout << "Account Number: " << accountNumber << endl;
        	cout << "Type: " << accountType << endl;
        	cout << "Balance: " << fixed << setprecision(2) << balance << endl << endl;
    	}
};

int main() 
{
	
    // Default constructor
    BankAccount defaultAcc;
	cout<<"Calling Default Constructor !"<<endl<<endl;  
    //calling all Accessor methods
    cout<<"Account Holder :- "<<defaultAcc.getAccountHolder()<<endl;
    cout<<"Account Number :- "<<defaultAcc.getAccountNumber()<<endl;
    cout<<"Account Type :- "<<defaultAcc.getAccountType()<<endl;
    cout<<"Available Balance :- "<<defaultAcc.getBalance()<<endl<<endl;
    
    
    defaultAcc.deposit(3000);
    defaultAcc.withdraw(1000);
    
    defaultAcc.setAccountType("current");
    cout<<"Updated Account Type to Current."<<endl<< endl; 
    defaultAcc.displayAccountDetails();
    
    
    // Parameterized constructor
    BankAccount userAcc("Priya Patil", 123456, "Savings", 5000.00); 
	cout<<endl<<endl<<"Calling Parameterized Constructor!"<<endl<<endl; 
    //calling all Accessor methods
    cout<<"Account Holder :- "<<userAcc.getAccountHolder()<<endl;
    cout<<"Account Number :- "<<userAcc.getAccountNumber()<<endl;
    cout<<"Account Type :- "<<userAcc.getAccountType()<<endl;
    cout<<"Available Balance :- "<<userAcc.getBalance()<<endl<<endl;

    userAcc.deposit(2000.00);
    userAcc.withdraw(1500.00);

    userAcc.setAccountType("Current");
    cout << "Updated Account Type to Current." << endl << endl;

    // Display all Account Display
    userAcc.displayAccountDetails();

    return 0;
}
