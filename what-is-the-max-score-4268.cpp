#include <iostream>
using namespace std;

int MaxScore(int score[], int begin, int end)
{
	if (begin > end)
	{
		swap(begin, end);
	}
	int res = 0;

	for (int i=begin; i<=end; i++)
	{
		if (res < score[i])
		{
			res = score[i];
		}
	}

	return res;
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;
	int *score = new int[N];
	int *max_score = new int[M];
	for (int i=0; i<N; i++)
	{
		cin >> score[i];
	}
	for (int i=0; i<M; i++)
	{
		max_score[i] = -1;
	}

	char op;
	int a, b;
	int count = 0;
	for (int i=1; i<=M; i++)
	{
		cin >> op >> a >> b;
		if (op == 'Q')
		{
			max_score[count] = MaxScore(score, a-1, b-1);
			count++;
		}
		else if (op == 'U')
		{
			score[a-1] = b;
		}
	}

	for (int i=0; i<M; i++)
	{
		if (-1 == max_score[i])
		{
			break;
		}
		cout << max_score[i] << endl;
	}

	delete[] score;
	delete[] max_score;
	score = NULL;
	max_score = NULL;
	return 0;
}