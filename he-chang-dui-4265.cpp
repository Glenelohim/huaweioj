#include <iostream>
using namespace std;

//refer from the internet
void DP4GetLGS(int pStudent[], int pDP_LGS[], int len)
{
	for (int i=0; i<len; i++)
	{
		pDP_LGS[i] = 1;
		for (int j=0; j<i; j++)
		{
			if (pStudent[i] > pStudent[j] && pDP_LGS[i] < (pDP_LGS[j] + 1))
			{
				pDP_LGS[i] = pDP_LGS[j] + 1;
			}
		}
	}
}

void DP4GetLLS(int pStudent[], int pDP_LLS[], int len)
{
	for (int i=len-1; i>=0; i--)
	{
		pDP_LLS[i] = 1;
		for (int j=len-1; j>i; j--)
		{
			if (pStudent[i] > pStudent[j] && pDP_LLS[i] < (pDP_LLS[j] + 1))
			{
				pDP_LLS[i] = pDP_LLS[j] + 1;
			}
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;
	if (N <= 0)
	{
		return 0;
	}
	//initial
	int *pStudent = new int[N];
	for (int i=0; i<N; i++)
	{
		cin >> pStudent[i];
	}

	int *pDP_LGS = new int[N];
	int *pDP_LLS = new int[N];
	DP4GetLGS(pStudent, pDP_LGS, N);
	DP4GetLLS(pStudent, pDP_LLS, N);

	int maxlen = 0;
	for (int i=0; i<N; i++)
	{
		if ((pDP_LGS[i] + pDP_LLS[i]) > maxlen)
		{
			maxlen = pDP_LGS[i] + pDP_LLS[i];
		}
	}
	maxlen--;
	cout << N - maxlen << endl;

	delete[] pStudent;
	delete[] pDP_LGS;
	delete[] pDP_LLS;
	pStudent = NULL;
	pDP_LGS = NULL;
	pDP_LLS = NULL;

	return 0;
}