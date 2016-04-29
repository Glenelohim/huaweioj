#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReverseString(string str)
{
	string res = "";
	for (int i=str.size()-1; i>=0; i--)
	{
		res += str[i];
	}
	return res;
}

string BigNumSum(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 > len2)
	{
		return BigNumSum(num2, num1);
	}

	num1 = ReverseString(num1);
	num2 = ReverseString(num2);
	vector<int> big_sum(101, -1);
	int carry_bit = 0;
	int i = 0;
	for (i=0; i<len1; i++)
	{
		int temp = (num1[i] - '0') + (num2[i] - '0') + carry_bit;
		big_sum[i] = temp % 10;
		carry_bit = temp / 10;
	}
	for (; i<len2; i++)
	{
		int temp = (num2[i] - '0') + carry_bit;
		big_sum[i] = temp % 10;
		carry_bit = temp / 10;
	}
	if (0 != carry_bit)
	{
		big_sum[i] = carry_bit;
	}

	int index = 100;
	string res = "";
	while (-1 == big_sum[index] && index >= 0)
	{
		index--;
	}
	while (index >= 0)
	{
		res += '0' + big_sum[index];
		index--;
	}

	return res;
}

int main()
{
	string num1, num2;

	while (cin >> num1 >> num2)
	{
		cout << BigNumSum(num1, num2) << endl;
	}

	return 0;
}