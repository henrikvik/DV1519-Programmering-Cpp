#include "FundAccount.h"

FundAccount::FundAccount(int accountNr, int saldo, int fund)
	: Account(accountNr, saldo)
{
	this->fund = fund;
}

FundAccount::~FundAccount()
{
}
