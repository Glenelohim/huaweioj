#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	getline(cin, input);
	input.erase(0, input.find_first_of(" ") + 1);
	input.erase(0, input.find_first_not_of(" "));
	input.erase(input.find_last_not_of(" ") + 1);

	return 0;
}