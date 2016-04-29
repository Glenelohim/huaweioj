#include <iostream>
using namespace std;

int DoHelper(int people[], int num)
{
	int count = 0, say_three = 0, index = 0;
	while (true)
	{
		if (count == num-1)
		{
			break;
		}
		if (1 == people[index])
		{
			if (2 == say_three)  //say 3 out, mark 0
			{
				count++;
				people[index] = 0;
			}
			say_three++;
			say_three %= 3;
		}
		index++;
		index %= num;
	}

	int res = 0;
	for (int i=0; i<num; i++)
	{
		if (1 == people[i])
		{
			res = i + 1;
			break;
		}
	}

	return res;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int *people = new int[num];
		for (int i=0; i<num; i++)
		{
			people[i] = 1;
		}

		cout << DoHelper(people, num) << endl;

		delete[] people;
		people = NULL;
	}
	return 0;
}