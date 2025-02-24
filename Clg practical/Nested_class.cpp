#include <iostream>
using namespace std;

class Bank
{
    private:
        int acc_no;
        long balance;
    public:

    Bank()
    {
        acc_no=0;
        balance=0;
    }
    Bank(int accNo,long bal)
    {
        acc_no=accNo;
        balance=bal;
    }

    void getInfo()
    {
        cout<<"Account No:"<<acc_no<<endl;
        cout<<"Current Balance:"<<balance<<endl;
    }

    class Transactions
    {
        public:
        void withdraw(Bank& b,long amount)
        {
            if(amount<=b.balance)
            {
                cout<<"Successfully Witdrawed."<<endl;
                b.balance=b.balance-amount;
            }
        }

        void deposit(Bank& b,long amount)
        {
            if(amount>0)
            {
                cout<<"Deposited Amount successfully."<<endl;
                b.balance=b.balance+amount;
            }
        }
    };
};
int main()
{
    Bank b1(13213,20000);
    b1.getInfo();
    Bank::Transactions t1;
    t1.withdraw(b1,10000);
    b1.getInfo();
    return 0;
}
