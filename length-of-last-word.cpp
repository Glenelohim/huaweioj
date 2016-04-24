#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	getline(cin, input);
	input.erase(input.find_last_not_of(" ") + 1);

	if (0 == input.size())
	{
		cout << "0" << endl;
	}
	else
	{
		int res = 0;
		for (int i=input.size()-1; i>=0; i--)
		{
			if (input[i] != ' ')
			{
				res++;
			}
			else
			{
				break;
			}
		}
		cout << res << endl;
	}

	return 0;
}