#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	getline(cin, input);
	for (int i=0; i<input.size(); i++)
	{
		if (input[i]>='A' && input[i]<'V')
		{
			input[i] += 37;
		}
		else if (input[i]>='V' && input[i]<='Z')
		{
			input[i] += 11;
		}
	}
	cout << input << endl;
	return 0;
}