#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(int accountNr, int saldo, float rate);
	virtual ~SavingsAccount();

	float getRate() const;

private:
	float rate;
};