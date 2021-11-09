/*
 * Transaction.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#include "Transaction.h"

void Transact(Account *PtrToAccount, double DepositAmount, double WithdrawAmount) {
	std::cout << "Transaction is beginning... \n";

	PtrToAccount->Deposit(DepositAmount);
	PtrToAccount->AccumulateInterest();
	PtrToAccount->Withdraw(WithdrawAmount);

	if (typeid(*PtrToAccount)== typeid(Checkings))
	{
		std::cout<<"Account is a checking account \n";
		Checkings *PtrToCheckingAcc = static_cast<Checkings *> (PtrToAccount);
		std::cout << "Minimum Balance of account is : " << PtrToCheckingAcc->Get_MinBalancedAllowed() << '\n';
	}

	else if (typeid(*PtrToAccount)== typeid(Savings))
	{
		std::cout<<"Account is a saving account \n";
		std::cout << "Accumulated Interest of account is : " << PtrToAccount->GetInterestRate() << '\n';
	}

/*
  Another method
	Checking *pChecking = dynamic_cast<Checking*>(PtrToAccount);
	if (pChecking != nullptr) {
		std::cout << "Minimum balance of Checking:" << pChecking->Get_MinBalancedAllowed() << std::endl;
	}

*/
	std::cout << "Balance of account is : " << PtrToAccount->GetBalance()<< '\n';
	std::cout << "Transaction is ending... \n \n \n";
}
