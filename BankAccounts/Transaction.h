/*
 * Transaction.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <iostream>
#include "Account.h"
#include "Savings.h"
#include <typeinfo>
#include "Checkings.h"


void Transact(Account *PtrToAccount, double DepositAmount, double WithdrawAmount);

#endif /* TRANSACTION_H_ */
