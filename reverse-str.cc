#include <iostream>
#include <string>
using namespace std;

string ReverseStr(string str)
{
	string res = "";
	for (int i=str.size()-1; i>=0; i--)
	{
		res += str[i];
	}
	return res;
}

int main()
{
	string str;
	getline(cin, str);
	cout << ReverseStr(str) << endl;;
	return 0;
}