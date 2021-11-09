#include <iostream>
#include "Account.h"
#include "Checkings.h"
#include "Savings.h"
#include "Transaction.h"

#define SavingsAcc 1
#define CheckingsAcc 2

using namespace std;


int main()
{

	int state;
	string name;
	double balance;
	double minBalance;
	double withdrawAmount;
	double depositAmount;
	float rate;

	while(true)
	{
	cout<< "Press 1 for a Savings Account \nPress 2 for a Checkings Account \n";
	cin>> state;

	if (state == SavingsAcc)
	{
		cout<<"Enter Account Name : \n";
		cin>>name;
		cout<<"Enter Balance of Account : \n";
		cin>>balance;
		cout<<"Enter Interest Rate of Account : \n";
		cin>>rate;

		Savings *Acc = new Savings{name,balance,rate};

		cout<<"Enter Amount to deposit : \nEnter 0 if you wish to withdraw only. \n";
		cin>>depositAmount;
		cout<<"Enter Amount to withdraw : \nEnter 0 if you wish to deposit only. \n";
		cin>>withdrawAmount;

		Transact(Acc, depositAmount, withdrawAmount);

	}

	else if (state == CheckingsAcc)
	{
		cout<<"Enter Account Name : \n";
		cin>>name;
		cout<<"Enter Balance of Account : \n";
		cin>>balance;
		cout<<"Enter Minimum allowed amount to be in the balance of this Account : \n";
		cin>>minBalance;

		Checkings Acc(name,balance,minBalance);

		cout<<"Enter Amount to deposit : \nEnter 0 if you wish to withdraw only. \n";
		cin>>depositAmount;
		cout<<"Enter Amount to withdraw : \nEnter 0 if you wish to deposit only. \n";
		cin>>withdrawAmount;

		Transact(&Acc, depositAmount, withdrawAmount);

	}

	else
	{
		cout<<"Invalid Input \n";
	}


	}
    return 0;
}
 
