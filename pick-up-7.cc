#include <iostream>
using namespace std;

bool JudgeSeven(int num)
{
	if (0 == (num % 7))
	{
		return true;
	}
	else
	{
		while (0 != (num / 10))
		{
			int bit = num % 10;
			if (7 == bit)
			{
				return true;
			}
			num = num / 10;
		}
		if (7 == num)
		{
			return true;
		}
		return false;
	}
}

int main()
{
	int N = 0;
	while (cin >> N)
	{
		int count = 0;
		if (N >= 7)
		{
			for (int i=N; i>=7; i--)
			{
				if (JudgeSeven(i))
				{
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}