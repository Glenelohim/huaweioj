#include <iostream>
#include <string>
using namespace std;

string Encrypt(string str)
{
	string res = "";
	for (int i=0, len=str.size(); i<len; i++)
	{
		if (str[i] == 'Z')
		{
			res += 'a';
		}
		else if (str[i] >= 'A' && str[i] < 'Z')
		{
			res += str[i] + 33;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] <= 'c')
			{
				res += '2';
			}
			else if (str[i] <= 'f')
			{
				res += '3';
			}
			else if (str[i] <= 'i')
			{
				res += '4';
			}
			else if (str[i] <= 'l')
			{
				res += '5';
			}
			else if (str[i] <= 'o')
			{
				res += '6';
			}
			else if (str[i] <= 's')
			{
				res += '7';
			}
			else if (str[i] <= 'v')
			{
				res += '8';
			}
			else
			{
				res += '9';
			}
		}
		else
		{
			res += str[i];
		}
	}
	return res;
}

int main()
{
	string plaintext;
	while (cin >> plaintext)
	{
		cout << Encrypt(plaintext) << endl;
	}
	return 0;
}