#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> DICT;

int AddOneWord (char* Word)
{
	if (Word == NULL)
	{
		return -1;
	}

	string fir = Word;
	map<string, string>::iterator p = DICT.find(fir);
	if (p != DICT.end())
	{
		return -1;
	}

	string sec = fir;
	sort(sec.begin(), sec.end());
	DICT[fir] = sec;

    return 0;
}

int FindSimilarWordNum (char* Word)
{
	if (NULL == Word)
	{
		return -1;
	}
	
	string sec = Word;
	string temp = sec;
	sort(sec.begin(), sec.end());
	map<string, string>::iterator p = DICT.begin();
	int res = 0;
	for (; p!=DICT.end(); p++)
	{
		if (p->second==sec && p->first!=temp)
		{
			res++;
		}
	}
    return res;
}

int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord)
{
	if (NULL == Word)
	{
		return -1;
	}
	string sec = Word;
	string temp = sec;
	sort(sec.begin(), sec.end());
	vector<string> res;
	map<string, string>::iterator p = DICT.begin();
	for (; p!=DICT.end(); p++)
	{
		if (p->second==sec && p->first!=temp)
		{
			res.push_back(p->first);
		}
	}
	if (0 == res.size())
	{
		SimilarWord[0] = '\0';
		return -1;
	}

	sort(res.begin(), res.end());
	if (Seq > res.size())
	{
		SimilarWord[0] = '\0';
		return -1;
	}

	int len = res[Seq-1].size();
	for (int i=0; i<len; i++)
	{
		SimilarWord[i] = res[Seq-1][i];
	}
	SimilarWord[len] = '\0';
    return 0;
}

void ClearAllWords(void)
{
    DICT.clear();
}

int main()
{
	char *test_word[7] = {
		"mock",
		"aabc",
		"abc",
		"ckom",
		"bcaa",
		"abca",
		"caba"
	};

	AddOneWord(test_word[0]);
	AddOneWord(test_word[1]);
	AddOneWord(test_word[2]);
	AddOneWord(test_word[3]);
	AddOneWord(test_word[4]);
	AddOneWord(test_word[5]);

	map<string, string>::iterator p = DICT.begin();
	for (; p!=DICT.end(); p++)
	{
		cout << p->first << " - " << p->second << endl;
	}

	
	cout << FindSimilarWordNum(test_word[6]) << endl;
	

	char *kk = new char[7];
	FindOneSimilarWord(test_word[6], 2, kk);
	cout << kk << endl;
	FindOneSimilarWord(test_word[6], 1, kk);
	cout << kk << endl;

	vector<string> test(3);
	test[0] = "hello";
	test[1] = "ahell";
	test[2] = "hella";
	sort(test.begin(), test.end());

	cout << test[0] << " "<< test[1] << " " << test[2] << endl;
	delete[] kk;
	return 0;
}