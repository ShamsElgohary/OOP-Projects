/*
 * Account.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>

class Account {
protected:
	std::string m_Name;
	double m_Balance;
	int m_accNum;
	static int accNumGenerator;

public:
	Account(const std::string &name, double balance);

	virtual ~Account();

	virtual void Withdraw(double amount);

	void Deposit(double amount);

	std::string GetName() const;

	int GetAccountNumber() const;

	double GetBalance() const;

	virtual float GetInterestRate() const;

	virtual void AccumulateInterest();

};

#endif /* ACCOUNT_H_ */
