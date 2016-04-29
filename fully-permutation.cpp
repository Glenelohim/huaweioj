#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//FullArray
void FullyPermutation(int train[], int begin, int end, vector<string> &res)
{
	if (begin == end)
	{
		string temp = "";
		for (int i=0; i<=end; i++)
		{
			temp += '0' + train[i];
		}
		res.push_back(temp);
		return;
	}

	for (int i=begin; i<=end; i++)
	{
		swap(train[begin], train[i]);
		FullyPermutation(train, begin+1, end, res);
		swap(train[begin], train[i]);
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
		FullyPermutation(train, 0, num-1, res);
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