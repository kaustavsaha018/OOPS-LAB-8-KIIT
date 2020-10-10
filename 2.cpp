/*
Create a class which stores account number, customer name and balance. Derive two classes from Account Class : Savings and
Current. The Savings class stores minimum balance. The Current class stores the over-due ammount. Include member functions
in the appropriate class for -deposit money, -withdraw(for saving account minimum balance should be checked), -display balance.
*/
#include<iostream>
#include<string.h>
using namespace std;

class Account{
	protected:
		int account_no;
		string customer_name;
		int balance;
	public:
		Account(){
			cout<<"Invalid!"<<endl;	
		}
		Account(int account_no, string customer_name, int balance){
			this->account_no=account_no;
			this->customer_name=customer_name;
			this->balance=balance;
		}
		withdraw(int amt){
				balance=balance-amt;
		}
		deposit(int amt){
			balance=balance+amt;
		}
		display(){
			cout<<"Account No. "<<account_no<<endl;
			cout<<"Customer's Name: "<<customer_name<<endl;
			cout<<"Availalbe Balance: "<<balance<<endl;
		}
};
class Savings : public Account{
	protected:
		static const int min_balance=1000;
		
	public:
		Savings(int account_no, string customer_name, int balance):Account(account_no,customer_name,balance){
		}
		//overriding
		withdraw(int amt){
			if(amt>balance-min_balance){
				cout<<"Minimum Limit Will Exceed! Can't Withdraw!"<<endl;
				exit(1);
			}
			else{
				balance=balance-amt;
			}
			
		}
		
};
class Current : public Account{
	protected:
		static const int min_balance=1000;
		int over_due_amt;
		
	public:
		Current(int account_no, string customer_name, int balance):Account(account_no,customer_name,balance){
		}
		//overriding...
		withdraw(int amt){
			over_due_amt=balance-min_balance;
			if(amt>over_due_amt){
				cout<<"Minimum Limit Will Exceed! Can't Withdraw!"<<endl;
				exit(1);
			}
			else{
				balance=balance-amt;
			}
			
		}
		//overriding...
		display(){
			cout<<"Account No. "<<account_no<<endl;
			cout<<"Customer's Name: "<<customer_name<<endl;	
			cout<<"Current Balance: "<<balance - min_balance<<endl;	
			cout<<"Availalbe Balance: "<<balance<<endl;
		}
	
			
};
int main(){
	Savings a1(1929018,"Kaustav Saha", 2000);
	a1.deposit(1000);
	a1.withdraw(1500); 
	a1.display();
	
	cout<<endl<<"----------------------------------------"<<endl<<endl;
	
	Current a2(1929057,"Srijan Verma", 5000);
	a2.deposit(1000);
	a2.withdraw(1500); 
	a2.display();
	
	return 0;
}
