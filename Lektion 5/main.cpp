#include <iostream>
using namespace std;

class A
{
public:
	A() {}
	A(A const& other)
	{
		i = new int(*other.i);
	}

	int * i;
};

int main()
{
	A a1;
	a1.i = new int(10);

	A a2 = a1;
	A a3(a2);

	cout << *a1.i << ", " << *a2.i << endl;

	delete a1.i;

	cout << *a2.i << endl;
	cout << *a3.i << endl;


	system("pause");
	return 0;
}