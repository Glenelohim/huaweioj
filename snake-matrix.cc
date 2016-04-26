#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> row_begin;
	row_begin.push_back(1);
	for (int i=1; i<N; i++)
	{
		row_begin.push_back(row_begin[i-1]+i);
	}
	
	for (int i=0; i<N; i++)
	{
		int cur_num = row_begin[i];
		cout << cur_num;
		for (int count=1, step=i+2; count<(N-i); count++, step++)
		{
			cout << " ";
			int pre_num = cur_num;
			cur_num = pre_num + step;
			cout << cur_num;
		}
		cout << endl;
	}

	return 0;
}