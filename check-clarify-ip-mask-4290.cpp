#include <iostream>
#include <cstdio>
using namespace std;

bool IsTrueIPMask(string ip, string mask)
{

}

int CheckIP(string ip)
{

}

int main()
{
	int res[5] = {0, 0, 0, 0, 0};
	string input;
	while (cin >> input)
	{
		string ip, mask;
		ip = input.substr(0, input.find_first_of('~'));
		mask = input.substr(input.find_first_of('~') + 1);

		cout << ip << endl << mask << endl;
	}

	return 0;
}