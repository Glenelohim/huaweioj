#include <iostream>
using namespace std;

int CountZeroNum(int num)
{
	if (0 == num)
	{
		return 0;
	}

	int res = 0;
	while (1 != num)
	{
		if (0 == (num % 2))
		{
			res++;
		}
		num /= 2;
	}
	return res;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << CountZeroNum(num) << endl;
	}
	return 0;
}