/*
 * Savings.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#ifndef SAVINGS_H_
#define SAVINGS_H_

#include "Account.h"

class Savings: public Account {
private:
	float m_Rate;
public:
	Savings(const std::string &name, double balance, float rate);

	virtual ~Savings();

	float GetInterestRate() const override;

	void AccumulateInterest() override;

};

#endif /* SAVINGS_H_ */
