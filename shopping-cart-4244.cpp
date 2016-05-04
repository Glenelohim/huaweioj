#include <iostream>
#include <string>
using namespace std;

struct ShoppingCard
{
	int remain_money;
	int remain_rank;
	ShoppingCard(int m = 3000, int r = 150) : remain_money(m), remain_rank(r) {}
	void reset() {remain_money = 3000; remain_rank = 150;}
};

struct ShoppingTrolley
{
	int goods_number;
	int goods_count;
	ShoppingTrolley(int n, int c) : goods_number(n), goods_count(c) {}
};

int main()
{
	string cmd;
	ShoppingCard shopping_card;
	while (getline(cin, cmd))
	{
		if ("r" == cmd)
		{
			shopping_card.reset();
			cout << "S001" << endl;
			continue;
		}

	}
	//cout << shopping_card.remain_money << " " << shopping_card.remain_rank << endl;

	return 0;
}