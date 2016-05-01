#include <iostream>
#include <cstring>
using namespace std;

void BuildPostorder(char *postorder, char *preorder, char *midorder, int len)
{
	if (0 == len)
	{
		return;
	}
	//the first node of preorder in the midorder, 
	//its left is the left tree, right is the right tree
	//and it is the last node of postorder
	int index = strchr(midorder, preorder[0]) - midorder;
	postorder[len-1] = preorder[0];
	BuildPostorder(postorder, preorder+1, midorder, index);  //left tree
	BuildPostorder(postorder+index, preorder+index+1, 
				   midorder+index+1, len-index-1);  //right tree
}

int main()
{
	char *preorder = new char[26];
	char *midorder = new char[26];
	char *postorder = new char[27];

	while (cin >> preorder >> midorder)
	{
		int len = strlen(preorder);
		BuildPostorder(postorder, preorder, midorder, len);
		postorder[len] = '\0';
		cout << postorder << endl;
	}

	delete[] preorder;
	delete[] midorder;
	delete[] postorder;
	preorder = NULL;
	midorder = NULL;
	postorder = NULL;
	return 0;
}