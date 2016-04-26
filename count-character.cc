#include <iostream>
#include <string>
using namespace std;

void CountCh(string str)
{
	int len = str.size();
	int num_of_eng = 0, num_of_num = 0, num_of_blank = 0, num_of_other = 0;

	for (int i=0; i<len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num_of_num++;
		}
		else if (str[i] == ' ')
		{
			num_of_blank++;
		}
		else if (isalpha(str[i]))
		{
			num_of_eng++;
		}
		else
		{
			num_of_other++;
		}
	}
	cout << num_of_eng << endl
		 << num_of_blank << endl
		 << num_of_num << endl
		 << num_of_other << endl;
}

int main()
{
	string str;
	getline(cin, str);
	CountCh(str);
	return 0;
}