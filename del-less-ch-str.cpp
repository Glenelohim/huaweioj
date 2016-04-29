#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string EraseLessCh(string str)
{
	int freq[26];
	memset(freq, 0, sizeof(freq));

	int len = str.size();
	for (int i=0; i<len; i++)
	{
		freq[str[i]-'a']++;
	}

	int min = 21;
	for (int i=0; i<26; i++)
	{
		if (freq[i] != 0)
		{
			if (min>freq[i])
			{
				min = freq[i];
			}
		}
	}

	string res = "";
	for (int i=0; i<len; i++)
	{
		if (freq[str[i]-'a'] > min)
		{
			res += str[i];
		}
	}
	
	return res;
}

int main()
{
	string input;
	while (cin >> input)
	{
		cout << EraseLessCh(input) << endl;
	}
	return 0;
}