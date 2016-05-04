#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
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

void GetGoodsNums(string cmd, int &goods, int &nums)
{
	int index = cmd.find_first_of('-');
	string left = cmd.substr(0, index);
	string right = cmd.substr(index+1);
	goods = atoi(left.c_str());
	nums = atoi(right.c_str());
}

void GoodsAndItsCount(int goods_ser[], vector<ShoppingTrolley> shopping_trolley)
{
	for (int i=0, len=shopping_trolley.size(); i<len; i++)
	{
		goods_ser[shopping_trolley[i].goods_number] += shopping_trolley[i].goods_count;
	}
}

int main()
{
	string cmd;
	ShoppingCard shopping_card;
	vector<ShoppingTrolley> shopping_trolley;
	while (getline(cin, cmd))
	{
		if ('r' == cmd[0])
		{
			shopping_card.reset();
			cout << "S001" << endl;
		}


		//pick up the goods
		else if ('o' == cmd[0])
		{
			cmd = cmd.substr(2);
			int goods, nums;
			GetGoodsNums(cmd, goods, nums);
			if (goods<0 || goods>2 || nums<=0 || nums>100)
			{
				cout << "E002" << endl;
			}
			else
			{
				if (shopping_trolley.size() < 5)
				{
					ShoppingTrolley new_goods(goods, nums);
					shopping_trolley.push_back(new_goods);
					cout << "S002" << endl;
				}
				else
				{
					cout << "E003" << endl;
				}
			}
		}


		// cmd l
		else if ('l' == cmd[0])
		{
			cmd = cmd.substr(2);
			int op = atoi(cmd.c_str());
			if (op < 0 || op > 1)
			{
				cout << "E002" << endl;
			}
			else
			{
				if (0 == op)
				{
					cout << shopping_card.remain_money << endl
						 << shopping_card.remain_rank << endl;
				}
				else
				{
					int goods_ser[3] = {0, 0, 0};
					GoodsAndItsCount(goods_ser, shopping_trolley);
					cout << shopping_trolley.size() << endl
						 << goods_ser[0] << endl
						 << goods_ser[1] << endl
						 << goods_ser[2] << endl;
				}
			}
		}


		//cmd b
		else if ('b' == cmd[0])
		{
			//do the buy-----------------**********

			//clear the trolley
			shopping_trolley.clear();
		}


		//cmd c
		else if ('c' == cmd[0])
		{
			cmd = cmd.substr(2);
			int goods, nums;
			GetGoodsNums(cmd, goods, nums);
			if (goods<0 || goods>2 || nums<=0 || nums>100)
			{
				cout << "E002" << endl;
			}
			else
			{
				if (0 == shopping_trolley.size()) //trolly is empty
				{
					cout << "E005" << endl;
				}
				else
				{
					vector<ShoppingTrolley>::iterator ip;
					bool is_exist = false;
					for (ip=shopping_trolley.begin(); ip!=shopping_trolley.end(); ip++)
					{
						if (ip->goods_number == goods && ip->goods_count == nums)
						{
							is_exist = true;
							shopping_trolley.erase(ip);
							break;
						}
					}
					if (is_exist)
					{
						cout << "S003" << endl;
					}
					else
					{
						cout << "E004" << endl;
					}
				}
			}
		}

		//cmd e
		else if ('e' == cmd[0])
		{
			break;
		}

	}
	//cout << shopping_card.remain_money << " " << shopping_card.remain_rank << endl;

	return 0;
}