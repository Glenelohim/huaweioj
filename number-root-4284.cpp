#include <iostream>
using namespace std;

int NumberBaseRoot(const int &num)
{
	int sum = num;
	while (0 != (sum / 10))
	{
		int temp = 0, temp_num = sum;
		while (0 != (temp_num / 10))
		{
			int bit = temp_num % 10;
			temp += bit;
			temp_num /= 10;
		}
		temp += temp_num;
		sum = temp;
	}
	return sum;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << NumberBaseRoot(num) << endl;
	}
	return 0;
}