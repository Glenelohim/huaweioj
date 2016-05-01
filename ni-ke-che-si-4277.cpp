#include <iostream>
using namespace std;

void JudgeNiko(int num)
{
	if (num < 1 || num > 100)
	{
		return;
	}
	int left = num * num * num;
	int base = 1, right = 1;
	int temp = base;
	for (; base<=left; base+=2)
	{
		right = 0;
		temp = base;
		for (int i=0; i<num; i++)
		{
			right += temp;
			temp += 2;
		}

		if (left == right)  //find
		{
			cout << base;
			temp = base + 2;
			for (int i=1; i<num; i++)
			{
				cout << "+" << temp;
				temp += 2;
			}
			cout << endl;
			return;
		}
	}
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		JudgeNiko(num);
	}
	return 0;
}