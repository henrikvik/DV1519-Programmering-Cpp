#pragma once

class Account
{
public:
	Account(int accountNr, int saldo);
	virtual ~Account();

	void setSaldo(int saldo);
	int getSaldo() const;

private:
	int accountNr;
	int saldo;
};