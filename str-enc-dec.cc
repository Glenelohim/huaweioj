#include <iostream>
#include <string>
using namespace std;

void Encrypt(string plaintext)
{
	int len = plaintext.size();
	char *cipher = new char[len+1];

	for (int i=0; i<len; i++)
	{
		if (plaintext[i] == '9')
		{
			cipher[i] = '0';
		}
		else if (plaintext[i] == 'z')
		{
			cipher[i] = 'A';
		}
		else if (plaintext[i] == 'Z')
		{
			cipher[i] = 'a';
		}
		else if ((plaintext[i]>='0') && (plaintext[i]<'9'))
		{
			cipher[i] = plaintext[i] + 1;
		}
		else if ((plaintext[i]>='a') && (plaintext[i]<'z'))
		{
			cipher[i] = plaintext[i] - 31;
		}
		else if ((plaintext[i]>='A') && (plaintext[i]<'Z'))
		{
			cipher[i] = plaintext[i] + 33;
		}
		else
		{
			cipher[i] = plaintext[i];
		}
	}
	cipher[len] = '\0';

	cout << cipher << endl;
	delete[] cipher;
}

void Decrypt(string ciphertext)
{
	int len = ciphertext.size();
	char *plain = new char[len+1];

	for (int i=0; i<len; i++)
	{
		if (ciphertext[i] == '0')
		{
			plain[i] = '9';
		}
		else if (ciphertext[i] == 'a')
		{
			plain[i] = 'Z';
		}
		else if (ciphertext[i] == 'A')
		{
			plain[i] = 'z';
		}
		else if ((ciphertext[i]>'0') && (ciphertext[i]<='9'))
		{
			plain[i] = ciphertext[i] - 1;
		}
		else if ((ciphertext[i]>'a') && (ciphertext[i]<='z'))
		{
			plain[i] = ciphertext[i] - 33;
		}
		else if ((ciphertext[i]>'A') && (ciphertext[i]<='Z'))
		{
			plain[i] = ciphertext[i] + 31;
		}
		else
		{
			plain[i] = ciphertext[i];
		}
	}
	plain[len] = '\0';

	cout << plain << endl;
	delete[] plain;
}

int main()
{
	string plaintext, ciphertext;
	getline(cin, plaintext);
	getline(cin, ciphertext);
	Encrypt(plaintext);
	Decrypt(ciphertext);

	return 0;
}