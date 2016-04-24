#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char s1, char s2)
{
	return s1 < s2;
}

int main()
{
	string input;
	cin >> input;
	sort(input.begin(), input.end(), cmp);
	cout << input << endl;
	return 0;
}