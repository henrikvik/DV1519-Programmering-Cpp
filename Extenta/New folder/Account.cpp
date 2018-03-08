#include "Account.h"

Account::Account(int accountNr, int saldo)
{
	this->accountNr = accountNr;
	this->saldo = saldo;
}

Account::~Account()
{
}

void Account::setSaldo(int saldo)
{
	this->saldo = saldo;
}

int Account::getSaldo() const
{
	return this->saldo;
}
