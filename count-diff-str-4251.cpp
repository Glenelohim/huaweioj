#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	getline(cin, input);
	sort(input.begin(), input.end());
	if (0 == input.size())
	{
		cout << "0" << endl;
		return 0;
	}

	string res = "";
	res += input[0];
	for (int i=1, len=input.size(); i<len; i++)
	{
		if (input[i] != input[i-1])
		{
			res += input[i];
		}
	}
	cout << res.size() << endl;

	return 0;
}