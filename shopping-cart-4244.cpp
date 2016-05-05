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
			// trolley is empty
			if (0 == shopping_trolley.size())
			{
				cout << "E005" << endl;
				continue;
			}

			//do the buy
			int total_goods_0[3] = {0, 0, 0};
			int total_goods_1[2] = {0, 0};
			int total_goods_2[2] = {0, 0};
			int goods_ser[3] = {0, 0, 0};  //the counts of every goods
			GoodsAndItsCount(goods_ser, shopping_trolley);  //get the goods_ser

			//initial the total_goods_x
			total_goods_0[0] = 10 * goods_ser[0];
			total_goods_0[1] = 9 * goods_ser[0];
			if (total_goods_0[0] >= 100)
			{
				total_goods_0[2] = total_goods_0[0] - total_goods_0[0]/100*18;
			}
			else
			{
				total_goods_0[2] = total_goods_0[0];
			}

			total_goods_1[0] = 120 * goods_ser[1];
			if (total_goods_1[0] >= 200)
			{
				total_goods_1[1] = total_goods_1[0] - total_goods_1[0]/200*40;
			}
			else
			{
				total_goods_1[1] = total_goods_1[0];
			}

			total_goods_2[0] = 30 * goods_ser[2];
			total_goods_2[1] = 15 * goods_ser[2];


			//calculate
			int origin_money = 0, count_money = 0x7fffffff;
			int final_scheme = -1; //-1: can not total count  0: rank count 1: zhe shang zhe
			for (int i=0; i<3; i++)
			{
				for (int j=0; j<2; j++)
				{
					for (int k=0; k<2; k++)
					{
						int sum = total_goods_0[i] + total_goods_1[j] + total_goods_2[k];
						if (sum < 500)
						{
							if (sum < count_money)
							{
								count_money = sum;
								origin_money = sum;
								final_scheme = -1;
							}
						}
						else
						{
							int count1 = 0, count2 = 0;
							if (shopping_card.remain_rank >= 120)
								count1 = sum - 120;
							else
								count1 = sum - shopping_card.remain_rank;
							count2 = sum * 0.8;

							if (count1 < count2)
							{
								if (count1 < count_money)
								{
									count_money = count1;
									origin_money = sum;
									final_scheme = 0;
								}
							}
							else
							{
								if (count2 <= count_money)
								{
									count_money = count2;
									origin_money = sum;
									final_scheme = 1;
								}
							}
						} // else
					} // for k
				} // for j
			} //for i
			if (count_money > shopping_card.remain_money)
			{
				cout << "E006" << endl;
			}
			else
			{
				int cost_money = count_money;
				int cost_rank = 0;
				int increse_rank = count_money / 10;

				shopping_card.remain_money -= count_money;
				if (0 == final_scheme)
				{
					if (shopping_card.remain_rank >= 120)
					{
						shopping_card.remain_rank -= 120;
						cost_rank = 120;
					}
					else
					{
						cost_rank = shopping_card.remain_rank;
						shopping_card.remain_rank = 0;
					}
				}
				shopping_card.remain_rank += increse_rank;
				//clear the trolley
				shopping_trolley.clear();

				cout << cost_money << endl 
					 << cost_rank << endl
					 << increse_rank << endl;
			}

		} //cmd b


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
				if (0 == shopping_trolley.size()) //trolley is empty
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