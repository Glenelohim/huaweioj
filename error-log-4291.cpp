#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ErrorLog
{
	string filename;
	int linenumber;
	int count;
	ErrorLog(string f, int l, int c=1) : filename(f), linenumber(l), count(c) {}
};

int main()
{
	int line_number = 0, input_count = 0;
	string file_name;
	vector<ErrorLog> res;

	while (cin >> file_name >> line_number)
	{
		//initial input
		file_name = file_name.substr(file_name.find_last_of('\\')+1);
		if (file_name.size() > 16)
		{
			file_name = file_name.substr(file_name.size()-16);
		}
		
		//find if exist
		int len = res.size();
		bool is_exist = false;
		for (int i=0; i<len; i++)
		{
			if (res[i].filename == file_name && res[i].linenumber == line_number)
			{
				res[i].count++;
				is_exist = true;
			}
		}
		if (!is_exist)
		{
			ErrorLog one_err(file_name, line_number);
			if (input_count >= 8)
			{
				res.erase(res.begin());
			}
			res.push_back(one_err);
			input_count++;
		}
	}

	for (int i=0, len=res.size(); i<len; i++)
	{
		cout << res[i].filename << " " << res[i].linenumber << " "
			 << res[i].count << endl;
	}

	return 0;
}