#include <iostream>
using namespace std;

int FaMa(int n, int *weight, int *num)
{
	//I just don't understand what's that mean
}

int main()
{
	int n = 0;
	cin >> n;
	int *weight = new int[n];
	int *num = new int[n];
	for (int i=0; i<n; i++)
	{
		cin >> weight[i];
	}
	for (int i=0; i<n; i++)
	{
		cin >> num[i];
	}



	delete[] weight;
	delete[] num;
	return 0;
}