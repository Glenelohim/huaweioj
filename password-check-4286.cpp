#include <iostream>
#include <string>
using namespace std;

bool PasswordCheck(string input)
{
	int len = input.size();
	//step1
	if (len <= 8)
	{
		return false;
	}

	//step2
	int mask[4] = {0, 0, 0, 0};
	for (int i=0; i<len; i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			mask[0] = 1;
		}
		else if (input[i] >= 'a' && input[i] <= 'z')
		{
			mask[1] = 1;
		}
		else if (input[i] >= '0' && input[i] <= '9')
		{
			mask[2] = 1;
		}
		else
		{
			mask[3] = 1;
		}
	}
	int count = 0;
	for (int i=0; i<4; i++)
	{
		if (1 == mask[i])
		{
			count++;
		}
	}
	if (count < 3)
	{
		return false;
	}

	//step3
	for (int substrlen=3; substrlen<=len-1; substrlen++)
	{
		for (int i=0; i<=(len-substrlen-1); i++)
		{
			string base = input.substr(i, substrlen);
			for (int j=i+1; j<=(len-substrlen); j++)
			{
				string str = input.substr(j, substrlen);
				if (base == str) //substring is same
				{
					return false;
				}
			}

		}
	}

	return true;
}

int main()
{
	string input;
	while (getline(cin, input))
	{
		if (PasswordCheck(input))
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "NG" << endl;
		}
	}
	return 0;
}