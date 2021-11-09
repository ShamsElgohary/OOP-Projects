/*
 * Checking.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#include "Checkings.h"

Checkings::Checkings(const std::string &name, double balance, double minBalance) : Account(name, balance), m_MinBalanceAllowed(minBalance)  {
	//  Auto-generated constructor stub
}

Checkings::~Checkings() {
	//  Auto-generated destructor stub
}

void Checkings::Withdraw(double amount)
{
	if (m_MinBalanceAllowed > (m_Balance-amount)) {
		std::cout<<"Invalid : Balance Will Become Below Minimum Amount Allowed \n";
	}

	else
	{
		Account::Withdraw(amount);
	}
}

double Checkings::Get_MinBalancedAllowed() const{
	return m_MinBalanceAllowed;
}

