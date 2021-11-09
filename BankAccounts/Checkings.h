/*
 * Checking.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#ifndef CHECKINGS_H_
#define CHECKINGS_H_

#include "Account.h"

class Checkings: public Account {
private:
	double m_MinBalanceAllowed;

public:

	Checkings(const std::string &name, double balance, double minBalance);

	virtual ~Checkings();

	void Withdraw(double amount) override;

	double Get_MinBalancedAllowed() const;



};

#endif /* CHECKINGS_H_ */
