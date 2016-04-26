#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> UNIT_DIG(20);
vector<string> TENS_DIG(8);

void InitDig(void)
{
	UNIT_DIG[0]  = "zero";
	UNIT_DIG[1]  = "one";
	UNIT_DIG[2]  = "two";
	UNIT_DIG[3]  = "three";
	UNIT_DIG[4]  = "four";
	UNIT_DIG[5]  = "five";
	UNIT_DIG[6]  = "six";
	UNIT_DIG[7]  = "seven";
	UNIT_DIG[8]  = "eight";
	UNIT_DIG[9]  = "nine";
	UNIT_DIG[10] = "ten";
	UNIT_DIG[11] = "eleven";
	UNIT_DIG[12] = "twelve";
	UNIT_DIG[13] = "thirteen";
	UNIT_DIG[14] = "fourteen";
	UNIT_DIG[15] = "fifteen";
	UNIT_DIG[16] = "sixteen";
	UNIT_DIG[17] = "seventeen";
	UNIT_DIG[18] = "eighteen";
	UNIT_DIG[19] = "nineteen";

	TENS_DIG[0] = "twenty";
	TENS_DIG[1] = "thirty";
	TENS_DIG[2] = "forty";
	TENS_DIG[3] = "fifty";
	TENS_DIG[4] = "sixty";
	TENS_DIG[5] = "seventy";
	TENS_DIG[6] = "eighty";
	TENS_DIG[7] = "ninety";
}

/*unsigned int CountDig(long num)
{
	unsigned int res = 0;
	while (num != 0)
	{
		res++;
		num /= 10;
	}
	return res;
}*/

string Exchange(int small_than_thun)  //except 0
{
	string res = "";
	int index = small_than_thun / 100;
	if (index != 0)
	{
		res += UNIT_DIG[index];
		res += " hundred";
	}

	small_than_thun %= 100;
	if (small_than_thun == 0)
	{
		return res;
	}
	if (res.size() != 0)
	{
		res += " and ";
	}

	if (small_than_thun < 20)
	{
		res += UNIT_DIG[small_than_thun];
	}
	else
	{
		index = small_than_thun / 10;
		res += TENS_DIG[index-2];
		index = small_than_thun % 10;
		if (index != 0)
		{
			res += " " + UNIT_DIG[index];
		}
	}

	return res;
}

string DoExchange(long num)
{
	const long BILLION  = 1000000000;
	const long MILLION  = 1000000;
	const long THOUSAND = 1000;
	string res = "";

	int num = input / BILLION;
	input %= BILLION;
	if (num != 0)
	{
		res += Exchange(num);
		res += " billion";
	}

	num = input / MILLION;
	input %= BILLION;
	if (num != 0)
	{
		if (res.size() != 0)
		{
			res += " ";
		}
		res += Exchange(num);
		res += " million";
	}

	num = input / THOUSAND;
	input %= THOUSAND;
	if (num != 0)
	{
		if (res.size() != 0)
		{
			res += " ";
		}
		res += Exchange(num);
		res += " thousand";
	}

	num = input;
	if (num != 0)
	{
		if (res.size() != 0)
		{
			res += " ";
		}
		res += Exchange(num);
	}

	return res;
}

int main()
{
	long input = 0;
	
	InitDig();

	while (cin >> input)
	{
		if (0 == input)
		{
			cout << "zero" << endl;
			break;
		}
		cout << DoExchange(input) << endl;
	}
	return 0;
}