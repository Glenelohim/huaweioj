#include <iostream>
#include <cstdio>
using namespace std;

int CheckNetSegment(int *mask, int *ip1, int *ip2)
{
	for (int i=0; i<4; i++)
	{
		if ((mask[i] < 0) || (mask[i] > 255)
		 || (ip1[i] < 0) || (ip1[i] > 255)
		 || (ip2[i] < 0) || (ip2[i] > 255))
		{
			return 1;
		}
		ip1[i] = ip1[i] & mask[i];
		ip2[i] = ip2[i] & mask[i];
	}
	for (int i=0; i<4; i++)
	{
		if (ip1[i] != ip2[i])
		{
			return 2;
		}
	}
	return 0;
}

int main()
{
	int ip1[4], ip2[4], mask[4];
	scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);
	scanf("%d.%d.%d.%d", &ip1[0], &ip1[1], &ip1[2], &ip1[3]);
	scanf("%d.%d.%d.%d", &ip2[0], &ip2[1], &ip2[2], &ip2[3]);

	cout << CheckNetSegment(mask, ip1, ip2) << endl;
	return 0;
}