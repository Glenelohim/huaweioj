#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int num)
{
	if (2 == num)
	{
		return true;
	}
	for (int i=2, k=sqrt(num); i<=k; i++)
	{
		if (0 == (num % i))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		if (num <=1 || num >= 100)
		{
			break;
		}
		if (2 == num || 3 == num)
		{
			cout << endl;
		}
		else 
		{
			cout << "4";
			for (int i=5; i<=num; i++)
			{
				if (!IsPrime(i))
				{
					cout << " " << i;
				}
			}
			cout << endl;
		}
	}

	return 0;
}