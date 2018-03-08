#pragma once
#include "Account.h"

class FundAccount : public Account
{
public:
	FundAccount(int accountNr, int saldo, int fund);
	virtual ~FundAccount();

private:
	int fund;
};