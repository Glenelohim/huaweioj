#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int CalExpression(int num[], int ch[])
{
	int res = -1;
	stack<int> num_stack;
	queue<int> ch_stack;

	num_stack.push(num[0]);
	for (int i=0; i<3; i++)
	{
		if (ch[i] == 2) //*
		{
			int temp = num_stack.top();
			temp *= num[i+1];
			num_stack.pop();
			num_stack.push(temp);
		}
		else if (ch[i] == 3) // /
		{
			int temp = num_stack.top();
			temp /= num[i+1];
			num_stack.pop();
			num_stack.push(temp);
			/*
			if (i == 2)
			{
				if (0 != (temp % num[i+1]))
				{
					return -1;
				}
				temp /= num[i+1];
				num_stack.pop();
				num_stack.push(temp);
			}
			else
			{
			}
			*/
		}
		else
		{
			num_stack.push(num[i+1]);
			ch_stack.push(ch[i]);
		}
	}
	stack<int> rev_num_stack;
	while (!num_stack.empty())
	{
		rev_num_stack.push(num_stack.top());
		num_stack.pop();
	}
	while (!ch_stack.empty())
	{
		int temp1 = rev_num_stack.top();
		int op = ch_stack.front();
		rev_num_stack.pop();
		ch_stack.pop();
		int temp2 = rev_num_stack.top();
		rev_num_stack.pop();

		if (op == 0)
		{
			rev_num_stack.push(temp1 + temp2);
		}
		else if(op == 1)
		{
			rev_num_stack.push(temp1 - temp2);
		}

	}
	res = rev_num_stack.top();
	rev_num_stack.pop();
	return res;
}

bool Game24Points(int a, int b, int c, int d)
{
	//TODO: Add codes here ... 
	//+:0, -:1, *:2, /:3

	int num[4], op[3];
	num[0] = a;
	num[1] = b;
	num[2] = c;
	num[3] = d;

	for (int i=0; i<4; i++)
	{
		op[0] = i;
		for (int j=0; j<4; j++)
		{
			op[1] = j;
			for (int k=0; k<4; k++)
			{
				op[2] = k;
				if (24 == CalExpression(num, op))
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	cout << Game24Points(7, 2, 1, 10) << endl;
	return 0;
}