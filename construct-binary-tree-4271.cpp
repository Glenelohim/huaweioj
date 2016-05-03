#include <iostream>
using namespace std;

bool GeneratePostorder(int preorder[], int inorder[], int postorder[], int n)
{
	if (n <= 0)
	{
		return true;
	}
	//find the index of the first node of preorder in the inorder
	int index = 0;
	for (; index<n; index++)
	{
		if (preorder[0] == inorder[index])
		{
			break;
		}
	}
	//not found
	if (index >= n)
	{
		return false;
	}
	//found
	postorder[n-1] = preorder[0];
	bool left = GeneratePostorder(preorder+1, inorder, postorder, index);
	bool right = GeneratePostorder(preorder+index+1, inorder+index+1, postorder+index, n-index-1);

	return left && right;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int *preorder = new int[n];
		int *inorder = new int[n];
		for (int i=0; i<n; i++)
		{
			cin >> preorder[i];
		}
		for (int i=0; i<n; i++)
		{
			cin >> inorder[i];
		}

		//generate postorder
		int *postorder = new int[n];
		if (GeneratePostorder(preorder, inorder, postorder, n))
		{
			for (int i=0; i<n; i++)
			{
				cout << postorder[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "No" << endl;
		}

		delete[] preorder;
		delete[] inorder;
		delete[] postorder;
		preorder = NULL;
		inorder = NULL;
		postorder = NULL;
	}
	return 0;
}