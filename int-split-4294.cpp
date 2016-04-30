#include <iostream>
using namespace std;

//if n is even: f(n) = f(n-1) + f(n / 2)
//if n is odd: f(n) = f(n-1)
long long DoHelper(int num)
{
	if (num < 1 || num > 1000000)
	{
		return -1;
	}
	if (1 == num)
	{
		return 1;
	}

	long long *fn = new long long[num+1];
	fn[0] = fn[1] = 1;
	fn[2] = 2;
	for (int i=3; i<=num; i++)
	{
		if (0 == i%2)  //i is odd
		{
			fn[i] = (fn[i-1] + fn[i/2]) % 1000000000;
		}
		else
		{
			fn[i] = fn[i-1];
		}
	}
	long long res = fn[num];
	//long long res = fn[num] % 1000000000;
	delete[] fn;

	return res;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << DoHelper(num) << endl;
	}
	return 0;
}