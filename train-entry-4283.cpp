#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void FullyPermuStack(int train[], int cur_index, int end_index, 
		vector<string> &res, string str, stack<int> train_stack)
{
	//pop out i's nums from train_stack
	for (int i=train_stack.size(); i>=0; i--)
	{
		stack<int> temp_train_stack(train_stack);
		string temp_str = str;
		//pick out i's nums into str
		for (int j=0; j<i; j++)
		{
			temp_str += '0' + temp_train_stack.top();
			temp_train_stack.pop();
		}

		temp_train_stack.push(train[cur_index]);
		//last num has been solved
		if (cur_index == end_index)
		{
			while (!temp_train_stack.empty())
			{
				temp_str += '0' + temp_train_stack.top();
				temp_train_stack.pop();
			}
			res.push_back(temp_str);
		}
		else
		{
			FullyPermuStack(train, cur_index+1, end_index, res, temp_str, temp_train_stack);
		}
	}
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int *train = new int[num];
		for (int i=0; i<num; i++)
		{
			cin >> train[i];
		}

		vector<string> res;
		string str = "";
		stack<int> train_stack;

		FullyPermuStack(train, 0, num-1, res, str, train_stack);
		sort(res.begin(), res.end());
		for (int i=0, len=res.size(); i<len; i++)
		{
			for (int j=0; j<num; j++)
			{
				cout << res[i][j];
				if (j != num-1)
				{
					cout << " ";
				}
			}
			cout << endl;
		}

		delete[] train;
		train = NULL;
	}

	return 0;
}