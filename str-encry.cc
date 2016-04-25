#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string Encrypt(string key, string plaintext)
{
	string encTable = "";
	encTable += key[0];
	for (int i=1; i<key.size(); i++)
	{
		if (encTable.find(key[i]) != string::npos)
		{
			continue;
		}
		else
		{
			encTable += key[i];
		}
	}
	for (int i=0; i<26; i++)
	{
		char temp = 'a' + i;
		if (encTable.find(temp) != string::npos)
		{
			continue;
		}
		else
		{
			encTable += temp;
		}
	}
	
	string ciphertext = "";
	for (int i=0; i<plaintext.size(); i++)
	{
		if (plaintext[i] == ' ')
		{
			ciphertext += ' ';
		}
		else
		{
			if (islower(plaintext[i]))
			{
				ciphertext += encTable[plaintext[i]-'a'];
			}
			else
			{
				ciphertext += toupper(encTable[tolower(plaintext[i])-'a']);
			}
		}
	}

	return ciphertext;
}

int main()
{
	string key;
	string plaintext;
	getline(cin, key);
	getline(cin, plaintext);
	
	cout << Encrypt(key, plaintext) << endl;

	return 0;
}