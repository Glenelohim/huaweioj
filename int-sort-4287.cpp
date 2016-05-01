#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	while (getline(cin, input))
	{
		//cout << input << endl;
		if (0 == input.size())
		{
			break;
		}

		string temp = "";
		vector<int> num;
		for (int i=0, len=input.size(); i<len; i++)
		{
			if (input[i] == ',')
			{
				num.push_back(atoi(temp.c_str()));
				temp = "";
			}
			else
			{
				temp += input[i];
			}
		}
		if (0 != temp.size())
		{
			num.push_back(atoi(temp.c_str()));
		}

		sort(num.begin(), num.end());
		cout << num[0];
		int len = num.size();
		for (int i=1; i<len-1; i++)
		{
			if ((num[i] == num[i-1]+1) && (num[i] == num[i+1]-1))
			{
				continue;
			}
			else
			{
				cout << " " << num[i];
			}
		}
		if (len - 1 > 0)
		{
			cout << " " << num[len-1];
		}
		cout << endl;
	}
	return 0;
}