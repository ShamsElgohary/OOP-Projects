/*
 * Account.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#include "Account.h"

int Account::accNumGenerator = 1000; //Initial Value of the account numbers

Account::Account(const std::string &name, double balance) : m_Name(name), m_Balance(balance)
{
	m_accNum = accNumGenerator++;
}

Account::~Account()
{

}

void Account::Withdraw(double amount)
{
	if (amount > m_Balance) {
		std::cout<<"Invalid : Insufficient Balance \n";
	}

	else
	{
	m_Balance = m_Balance - amount;
	}
}

void Account::Deposit(double amount) {
	m_Balance = m_Balance + amount;
}

std::string Account::GetName() const {
	return m_Name;
}

int Account::GetAccountNumber() const {
	return m_accNum;
}

double Account::GetBalance() const {
	return m_Balance;
}

float Account::GetInterestRate() const {
	return 0.0f;
}

void Account::AccumulateInterest() {
}
