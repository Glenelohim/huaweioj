#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(int pre, int aft)
{
	return pre > aft;
}

int MaxScore(string name)
{
	int score[26];
	int res = 0;
	int chs = 26;
	memset(score, 0, sizeof(score));

	for (int i=0; i<name.size(); i++)
	{
		int temp = tolower(name[i]) - 'a';
		score[temp]++;
	}
	sort(score, score+26, cmp);
	for (int i=0; i<26; i++)
	{
		if (0 == score[i])
		{
			break;
		}
		res += score[i] * chs;
		chs--;
	}

	return res;
}

int main()
{
	string input;
	int count = 0;	
	while (cin >> input)
	{
		if (0 == count)
		{
			count++;
			continue;
		}
		cout << MaxScore(input) << endl;
	}

	return 0;
}