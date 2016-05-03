#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

bool IsTrueIP(string ip, int arr_ip[])
{
	int len = ip.size(), dot_count = 0;
	int dot_index[3];
	for (int i=0; i<len; i++)
	{
		if (ip[i] == '.')
		{
			dot_count++;
			if (i == 0 || i == len-1)
			{
				return false;
			}
			if (ip[i-1] < '0' || ip[i-1] > '9'
			 || ip[i+1] < '0' || ip[i+1] > '9')
			{
				return false;
			}
			if (dot_count <= 3)
			{
				dot_index[dot_count-1] = i;
			}
		}
	}
	if (dot_count != 3)
	{
		return false;
	}

	string num[4];
	num[0] = ip.substr(0, dot_index[0]);
	num[1] = ip.substr(dot_index[0]+1, dot_index[1]-dot_index[0]-1);
	num[2] = ip.substr(dot_index[1]+1, dot_index[2]-dot_index[1]-1);
	num[3] = ip.substr(dot_index[2]+1);

	for (int i=0; i<4; i++)
	{
		if (num[i] != "0" && num[i][0] == '0')
		{
			return false;
		}
		int temp = atoi(num[i].c_str());
		if (temp > 255)
		{
			return false;
		}
		arr_ip[i] = temp;
	}
	return true;
}

string Mask2Str(int num)
{
	int mask[8], index = 7;
	memset(mask, 0, sizeof(mask));
	while (0 < (num / 2))
	{
		mask[index--] = num % 2;
		num /= 2;
	}
	if (index >= 0)
	{
		mask[index] = num;
	}

	string res = "";
	for (int i=0; i<8; i++)
	{
		res += '0' + mask[i];
	}
	return res;
}

bool IsTrueMask(string mask)
{
	int arr_mask[4];
	if (!IsTrueIP(mask, arr_mask))
	{
		return false;
	}

	string binary_mask = "";
	for (int i=0; i<4; i++)
	{
		binary_mask += Mask2Str(arr_mask[i]);
	}
	if (binary_mask[0] == '0')
	{
		return false;
	}

	int index = binary_mask.find_first_of('0');
	for (int i=index+1; i<32; i++)
	{
		if (binary_mask[i] == '1')
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int res[7] = {0, 0, 0, 0, 0, 0, 0};
	int arr_ip[4];
	string input;
	while (cin >> input)
	{
		string ip, mask;
		ip = input.substr(0, input.find_first_of('~'));
		mask = input.substr(input.find_first_of('~') + 1);

		if (0 == ip.size() || 0 == mask.size())
		{
			res[5]++;
			continue;
		}

		if (!IsTrueIP(ip, arr_ip) || !IsTrueMask(mask))
		{
			res[5]++;
			continue;
		}
		// class A
		if (arr_ip[0]>=1 && arr_ip[0]<= 126)
		{
			res[0]++;
			if (10 == arr_ip[0])
			{
				res[6]++;
			}
		}
		// class B
		else if (arr_ip[0]>=128 && arr_ip[0]<=191)
		{
			res[1]++;
			if (172 == arr_ip[0])
			{
				if (arr_ip[1]>=16 && arr_ip[1]<=31)
				{
					res[6]++;
				}
			}
		}
		// class C
		else if (arr_ip[0]>=192 && arr_ip[0]<=223)
		{
			res[2]++;
			if (192 == arr_ip[0] && 168 == arr_ip[1])
			{
				res[6]++;
			}
		}
		// class D
		else if (arr_ip[0]>=224 && arr_ip[0]<=239)
		{
			res[3]++;
		}
		// class E
		else if (arr_ip[0]>=240 && arr_ip[0]<=255)
		{
			res[4]++;
		}

	}

	cout << res[0];
	for (int i=1; i<7; i++)
	{
		cout << " " << res[i];
	}
	cout << endl;

	return 0;
}