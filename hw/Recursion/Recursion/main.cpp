
#include <iostream>
using namespace std;

int add(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return (n % 10 + add(n / 10));
}

int main()
{
	int value = 0;
	cout << "ENTER A NUMBER: ";
	cin >> value;
	int result = add(value);
	cout << "result: " << result << endl;
	return 0;
}
