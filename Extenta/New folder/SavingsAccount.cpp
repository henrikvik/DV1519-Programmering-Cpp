#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int accountNr, int saldo, float rate)
	: Account(accountNr, saldo)
{
	this->rate = rate;
}

SavingsAccount::~SavingsAccount()
{

}

float SavingsAccount::getRate() const
{
	return this->rate;
}
