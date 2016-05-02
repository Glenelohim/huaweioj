#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool IsStrMatchCMD(string cmd, string str)
{
	if (NULL == strstr(cmd.c_str(), str.c_str()))
	{
		return false;
	}
	if (0 == strcmp(cmd.c_str(), strstr(cmd.c_str(), str.c_str())))
	{
		return true;
	}
	return false;
}

void CommandHelper(string input)
{
	//count blank number
	int len = input.size();
	int blank_index = 0, blank_count = 0;
	for (int i=0; i<len; i++)
	{
		if (input[i] == ' ')
		{
			blank_index = i;
			blank_count++;
		}
	}
	if (blank_count > 1)
	{
		cout << "unkown command" << endl;
		return;
	}

	string first, second;
	//check reset
	if (0 == blank_count)
	{
		first = input;
		string cmd = "reset";
		if (IsStrMatchCMD(cmd, first))
		{
			cout << "reset what" << endl;
		}
		else
		{
			cout << "unkown command" << endl;
		}
		return;
	}

	//two command values
	first = input.substr(0, blank_index);
	second = input.substr(blank_index+1);
	if (0 == first.size() || 0 == second.size())
	{
		cout << "unkown command" << endl;
		return;
	}
	//"b a" command
	string cmd1 = "b";
	string cmd2 = "a";
	if (cmd1 == first && cmd2 == second)
	{
		cout << "unkown command" << endl;
		return;
	}
	//"r b" command
	cmd1 = "r";
	cmd2 = "b";
	if (cmd1 == first && cmd2 == second)
	{
		cout << "unkown command" << endl;
		return;
	}
	//"re b" command
	cmd1 = "re";
	cmd2 = "b";
	if (cmd1 == first && cmd2 == second)
	{
		cout << "unkown command" << endl;
		return;
	}

	//check reset board
	cmd1 = "reset";
	cmd2 = "board";
	if (IsStrMatchCMD(cmd1, first) && IsStrMatchCMD(cmd2, second))
	{
		cout << "board fault" << endl;
		return;
	}
	//check reboot backplane
	cmd1 = "reboot";
	cmd2 = "backplane";
	if (IsStrMatchCMD(cmd1, first) && IsStrMatchCMD(cmd2, second))
	{
		cout << "impossible" << endl;
		return;
	}
	//check backplane abort
	cmd1 = "backplane";
	cmd2 = "abort";
	if (IsStrMatchCMD(cmd1, first) && IsStrMatchCMD(cmd2, second))
	{
		cout << "install first" << endl;
		return;
	}
	//check board *
	cmd1 = "board";
	if (IsStrMatchCMD(cmd1, first))
	{
		cmd2 = "add";
		if (IsStrMatchCMD(cmd2, second))
		{
			cout << "where to add" << endl;
			return;
		}
		cmd2 = "delet";
		if (IsStrMatchCMD(cmd2, second))
		{
			cout << "no board at all" << endl;
			return;
		}
	}

	cout << "unkown command" << endl;
}

int main()
{
	string input;
	while (getline(cin, input))
	{
		if (input.size() > 0)
		{
			CommandHelper(input);
		}
	}
	return 0;
}