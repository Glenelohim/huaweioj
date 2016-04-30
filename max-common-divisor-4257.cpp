#include <iostream>
using namespace std;

int MaxCommonDivisor(int num1, int num2)
{
	int temp = (num1 < num2) ? num1 : num2;
	int res = 1;
	for (int i=2; i<=temp; i++)
	{
		if ((0==(num1%i)) && (0==(num2%i)))
		{
			res = i;
		}
	}
	return res;
}

int main()
{
	int num1 = 0, num2 = 0;
	while (cin >> num1 >> num2)
	{
		cout << MaxCommonDivisor(num1, num2) << endl;
	}
	return 0;
}