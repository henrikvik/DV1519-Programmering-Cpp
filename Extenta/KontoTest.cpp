#include <crtdbg.h>
#include "SavingsAccount.h"
#include "FundAccount.h"

#include <iostream>
using namespace std;

#include <vector>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Account* accounts[6] = { nullptr };
	accounts[0] = new FundAccount	(18, 12349, 2301);
	accounts[1] = new SavingsAccount(38, 82401, 0.02);
	accounts[2] = new FundAccount	(78, 95813, 1234);
	accounts[3] = new SavingsAccount(83, 92349, 0.004);
	accounts[4] = new FundAccount	(89, 48172, 4072);

	int sum = 0;
	for (size_t i = 0; i < 6; i++)
	{
		if (accounts[i])
		{
			cout << i << ") Saldo: " << accounts[i]->getSaldo() << endl;
			sum += accounts[i]->getSaldo();
		}
	}
	cout << "Sum of all account saldos: " << sum << endl;

	for (size_t i = 0; i < 6; i++)
	{
		SavingsAccount * ptr = dynamic_cast<SavingsAccount*>(accounts[i]);
		if (ptr)
		{
			cout << i << ") Rate: " << ptr->getRate() * 100 << "%" << endl;
		}
	}


	for (size_t i = 0; i < 6; i++)
	{
		delete accounts[i];
	}

	system("pause");
	return 0;
}