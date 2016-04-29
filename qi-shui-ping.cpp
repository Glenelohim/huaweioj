#include <iostream>
#include <cstring>
using namespace std;

int MaxNumOfDrink(int n)
{
	if (1 == n)
	{
		return 0;
	}
	if (2==n || 3==n)
	{
		return 1;
	}

	int res = 0;
	while (n >= 3)
	{
		res += n / 3;
		n = n / 3 + n % 3;
	}
	if (2 == n)
	{
		res++;
	}
	return res;
}

int main()
{
	int batt_num[11];
	memset(batt_num, 0, sizeof(batt_num));
	for (int i=0; i<11; i++)
	{
		cin >> batt_num[i];
		if (0 == batt_num[i])
		{
			break;
		}
	}

	for (int i=0; i<11; i++)
	{
		if (0 == batt_num[i])
		{
			break;
		}
		cout << MaxNumOfDrink(batt_num[i]) << endl;
	}
	
	return 0;
}