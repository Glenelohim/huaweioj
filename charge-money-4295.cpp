#include <iostream>
#include <vector>
using namespace std;

int DP4ChargeMoney(int charge[], int money, int charge_index)
{
	if (0==charge_index || 0==money || 1==money)
	{
		return 1;
	}
	if (money<0 || charge_index<0)
	{
		return 0;
	}
	//pick charge[charge_index] + not pick it
	return DP4ChargeMoney(charge, money-charge[charge_index], charge_index)
		 + DP4ChargeMoney(charge, money, charge_index-1); 
}

int main()
{
	int money = 0;
	int charge[7] = {1, 2, 5, 10, 20, 50, 100};
	vector<int> res;

	while (cin >> money)
	{
		if (0 >= money)
		{
			break;
		}
		int charge_index = 6;
		for (; charge_index>=0; charge_index--)
		{
			if (charge[charge_index] <= money)
			{
				break;
			}
		}

		int temp = DP4ChargeMoney(charge, money, charge_index);
		res.push_back(temp);
	}

	for (int i=0,len=res.size(); i<len; i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}