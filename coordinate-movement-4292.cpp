#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void Movement(string op, int &x, int &y)
{
	if (op[1]<'0' || op[1]>'9')
	{
		return;
	}
	if (3 == op.size())
	{
		if (op[2]<'0' || op[2]>'9')
		{
			return;
		}
	}

	string num = op.substr(1);
	int mov = atoi(num.c_str());
	if ('A' == op[0])
	{
		x -= mov;
	}
	else if ('D' == op[0])
	{
		x += mov;
	}
	else if ('W' == op[0])
	{
		y += mov;
	}
	else if ('S' == op[0])
	{
		y -= mov;
	}
}

int main()
{
	string input;
	
	while (getline(cin, input))
	{
		int x = 0, y = 0;
		int input_len = input.size();
		if (0 == input_len)
		{
			continue;
		}
		//erase first&last blank
		input.erase(0, input.find_first_not_of(' '));
		input.erase(input.find_last_not_of(' ') + 1);
		input_len = input.size();
		if (0 == input_len)
		{
			continue;
		}

		vector<int> semicolon_index;
		semicolon_index.push_back(0);
		for (int i=0; i<input_len; i++)
		{
			if (input[i] == ';')
			{
				semicolon_index.push_back(i);
			}
		}

		int semicolon_count = semicolon_index.size() - 1;
		string *op = new string[semicolon_count];
		for (int i=0; i<semicolon_count; i++)
		{
			if (0 == i)
			{
				op[0] = input.substr(0, semicolon_index[1]);
			}
			else
			{
				op[i] = input.substr(semicolon_index[i]+1, semicolon_index[i+1]-semicolon_index[i]-1);
			}
		}

		for (int i=0; i<semicolon_count; i++)
		{
			if (op[i].size() != 3 && op[i].size() != 2)
			{
				continue;
			}
			Movement(op[i], x, y);
		}

		cout << x << "," << y << endl;

		if (NULL != op)
		{
			delete[] op;
		}
		op = NULL;
	}
	
	return 0;
}