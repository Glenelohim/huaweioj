#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct Patients
{
	string id;
	int type;
	int cash;
	int card;
	int state; //2: under pay  1: under diag/ registered  0: under register
	//Patients(string i, int p, int cas, int car) : id(i), type(p), cash(cas), card(car) {}
};

Patients g_pat[6];
vector<Patients> g_doc_queue;
vector<string> g_out_res;

void OpInit(void)
{
	//init patient
	g_pat[0].id = "pat01";
	g_pat[0].type = 0;
	g_pat[0].cash = 100;
	g_pat[0].card = 0;
	g_pat[0].state = 0;

	g_pat[1].id = "pat02";
	g_pat[1].type = 1;
	g_pat[1].cash = 100;
	g_pat[1].card = 100;
	g_pat[1].state = 0;

	g_pat[2].id = "pat03";
	g_pat[2].type = 0;
	g_pat[2].cash = 100;
	g_pat[2].card = 0;
	g_pat[2].state = 0;

	g_pat[3].id = "pat04";
	g_pat[3].type = 1;
	g_pat[3].cash = 100;
	g_pat[3].card = 50;
	g_pat[3].state = 0;

	g_pat[4].id = "pat05";
	g_pat[4].type = 1;
	g_pat[4].cash = 10;
	g_pat[4].card = 10;
	g_pat[4].state = 0;

	g_pat[5].id = "pat06";
	g_pat[5].type = 1;
	g_pat[5].cash = 20;
	g_pat[5].card = 10;
	g_pat[5].state = 0;

	//init doc_queue & out_res
	g_doc_queue.clear();
	g_out_res.clear();
	g_out_res.push_back("E000");
}

void OpRegister(string patID)
{
	int id = patID[patID.size()-1] - '0';
	if (g_pat[id-1].state != 0)
	{
		g_out_res.push_back("E002");
		return;
	}
	
	if (g_doc_queue.size() >= 4)
	{
		g_out_res.push_back("E003");
		return;
	}

	//has card
	if (1 == g_pat[id-1].type)
	{
		if (g_pat[id-1].card >= 10)
		{
			g_pat[id-1].card -= 10;
			g_pat[id-1].state = 1;
			g_doc_queue.push_back(g_pat[id-1]);
			g_out_res.push_back("E001");
			return;
		}

		if (g_pat[id-1].cash >= 10)
		{
			g_pat[id-1].cash -= 10;
			g_pat[id-1].state = 1;
			g_doc_queue.push_back(g_pat[id-1]);
			g_out_res.push_back("E001");
			return;
		}
		else
		{
			g_out_res.push_back("E004");
			return;
		}
	}
	else
	{
		if (g_pat[id-1].cash >= 10)
		{
			g_pat[id-1].cash -= 10;
			g_pat[id-1].state = 1;
			g_doc_queue.push_back(g_pat[id-1]);
			g_out_res.push_back("E001");
			return;
		}
		else
		{
			g_out_res.push_back("E004");
			return;
		}
	}

}

void OpDiag(void)
{
	if (0 == g_doc_queue.size())
	{
		g_out_res.push_back("E006");
		return;
	}

	string str_id = g_doc_queue[0].id;
	int pid = str_id[str_id.size()-1] - '0';
	g_pat[pid-1].state = 2; // under pay
	g_doc_queue.erase(g_doc_queue.begin());
	g_out_res.push_back("E005");
}

void OpPay(string patID)
{
	int id = patID[patID.size()-1] - '0';
	if (g_pat[id-1].state != 2)
	{
		g_out_res.push_back("E014");
		return;
	}

	//has card
	if (1 == g_pat[id-1].type)
	{
		if (g_pat[id-1].card >= 50)
		{
			g_pat[id-1].card -= 50;
			g_pat[id-1].state = 0;
			g_out_res.push_back("E007");
			return;
		}

		if (g_pat[id-1].cash >= 50)
		{
			g_pat[id-1].cash -= 50;
			g_pat[id-1].state = 0;
			g_out_res.push_back("E007");
			return;
		}
		else
		{
			g_pat[id-1].state = 0;
			g_out_res.push_back("E008");
			return;
		}
	}
	else
	{
		if (g_pat[id-1].cash >= 50)
		{
			g_pat[id-1].cash -= 50;
			g_pat[id-1].state = 0;
			g_out_res.push_back("E007");
			return;
		}
		else
		{
			g_pat[id-1].state = 0;
			g_out_res.push_back("E008");
			return;
		}
	}
}

void OpQuery(string str)
{
	if ('0' == str[0]) // qu_0-dct
	{
		int len = g_doc_queue.size();
		if (0 == len)
		{
			g_out_res.push_back("E013:dct 0");
			return;
		}
		else
		{
			string temp = "E013:dct";
			for (int i=0; i<len; i++)
			{
				temp += ' ';
				temp += g_doc_queue[i].id;
			}
			g_out_res.push_back(temp);
			return;
		}
	}
	else if ('1' == str[0])  //1-patID
	{
		str = str.substr(2);  //patID
		int id = str[str.size()-1] - '0';
		string temp = "E012:" + str;
		if (0 == g_pat[id-1].state)
		{
			temp += " 0 ";
			char tmp[20];
			itoa(g_pat[id-1].card, tmp, 10);
			temp += tmp;
			temp += ',';
			itoa(g_pat[id-1].cash, tmp, 10);
			temp += tmp;
			g_out_res.push_back(temp);
			return;
		}
		else if (1 == g_pat[id-1].state)
		{
			temp += " 1 ";
			int index = 0;
			for (int i=0, len=g_doc_queue.size(); i<len; i++)
			{
				if (g_doc_queue[i].id == str)
				{
					index = i + 1;
					break;
				}
			}
			temp += '0' + index;
			temp += ',';
			char tmp[20];
			itoa(g_pat[id-1].card, tmp, 10);
			temp += tmp;
			temp += ',';
			itoa(g_pat[id-1].cash, tmp, 10);
			temp += tmp;
			g_out_res.push_back(temp);
			return;
		}
		else
		{
			temp += " 2 ";
			char tmp[20];
			itoa(g_pat[id-1].card, tmp, 10);
			temp += tmp;
			temp += ',';
			itoa(g_pat[id-1].cash, tmp, 10);
			temp += tmp;
			g_out_res.push_back(temp);
			return;
		}
	}
}

int main()
{
	string input;
	while (cin >> input)
	{
		vector<string> cmd;
		string cmd_temp = "";
		for (int i=0, len=input.size(); i<len; i++)
		{
			if (',' == input[i])
			{
				cmd.push_back(cmd_temp);
				cmd_temp = "";
			}
			else
				cmd_temp += input[i];
		}
		cmd.push_back(cmd_temp);

		for (int i=0, len=cmd.size(); i<len; i++)
		{
			if ('i' == cmd[i][0])
			{
				OpInit();
			}
			else if ('r' == cmd[i][0])
			{
				string patid = cmd[i].substr(4);
				OpRegister(patid);
			}
			else if ('d' == cmd[i][0])
			{
				OpDiag();
			}
			else if ('p' == cmd[i][0])
			{
				string patid = cmd[i].substr(4);
				OpPay(patid);
			}
			else if ('q' == cmd[i][0])
			{
				string str = cmd[i].substr(3);
				OpQuery(str);
			}
		}

		for (int i=0, len=g_out_res.size(); i<len; i++)
		{
			cout << g_out_res[i] << endl;
		}

	}
	return 0;
}