#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int String2Number(string str)
{
	int res = 0;
	if ("J" == str)
	{
		res = 11;
	}
	else if ("Q" == str)
	{
		res = 12;
	}
	else if ("K" == str)
	{
		res = 13;
	}
	else if ("A" == str)
	{
		res = 14;
	}
	else if ("2" == str)
	{
		res = 15;
	}
	else if ("joker" == str)
	{
		res = 16;
	}
	else if ("JOKER" == str)
	{
		res = 17;
	}
	else
	{
		res = atoi(str.c_str());
	}
	return res;
}

void String2Vec(string str, vector<int> &vec)
{
	string temp = "";
	for (int i=0, len=str.size(); i<len; i++)
	{
		if (' ' == str[i])
		{
			vec.push_back(String2Number(temp));
			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}
	vec.push_back(String2Number(temp));
}

int main()
{
	string input, str_left, str_right;
	while (getline(cin, input))
	{
		if (input.find("joker JOKER") != string::npos)
		{
			cout << "joker JOKER" << endl;
			continue;
		}
		int line_index = input.find_first_of('-');
		str_left = input.substr(0, line_index);
		str_right = input.substr(line_index+1);

		vector<int> vec_left, vec_right;
		String2Vec(str_left, vec_left);
		String2Vec(str_right, vec_right);
		int left_len = vec_left.size(), right_len = vec_right.size();

		//boom
		if (4 == left_len)
		{
			if (4 == right_len && vec_left[0] < vec_right[0])
			{
				cout << str_right << endl;
			}
			else
			{
				cout << str_left << endl;
			}
		}
		else if (4 == right_len)
		{
			cout << str_right << endl;
		}
		else if (left_len == right_len)
		{
			if (vec_left[0] < vec_right[0])
			{
				cout << str_right << endl;
			}
			else
			{
				cout << str_left << endl;
			}
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
	return 0;
}