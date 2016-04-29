#include <iostream>
#include <string>
using namespace std;

void DoHelp(int num)
{
	string res = "";
	int bit_count = 0;
	while (num / 10)
	{
		bit_count++;
		int temp = num % 10;
		num /= 10;
		res += '0' + temp;
	}
	res += '0' + num;
	bit_count++;

	cout << bit_count << " " << res << endl;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		DoHelp(num);
	}
	return 0;
}