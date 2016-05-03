#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void String2Vector(vector<int> &res, const string &str)
{
	for (int i=0, len=str.size(); i<len; i++)
	{
		res.push_back(str[i]-'0');
	}
}

bool IsTheSameTree(TreeNode *root1, TreeNode* root2)
{
	if (NULL == root1 && NULL == root2)
	{
		return true;
	}
	else if (NULL == root1 || NULL == root2)
	{
		return false;
	}
	else if (root1->value != root2->value)
	{
		return false;
	}

	return IsTheSameTree(root1->left, root2->left)
		 &&IsTheSameTree(root1->right, root2->right);
}

void BuildBST(TreeNode *&root, int key)
{
	if (NULL == root)
	{
		root = new TreeNode(key);
		return;
	}
	if (key > root->value)
	{
		BuildBST(root->right, key);
	}
	else
	{
		BuildBST(root->left, key);
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (0 == n)
		{
			break;
		}

		string str_base;
		vector<int> vec_base;
		TreeNode *tree_base = NULL;

		//initial
		cin >> str_base;
		String2Vector(vec_base, str_base);
		for (int i=0, len=vec_base.size(); i<len; i++)
		{
			BuildBST(tree_base, vec_base[i]);
		}

		vector<string> res(n);
		for (int i=0; i<n; i++)
		{
			string input;
			vector<int> num;
			TreeNode *root = NULL;

			cin >> input;
			String2Vector(num, input);
			for (int j=0, len=num.size(); j<len; j++)
			{
				BuildBST(root, num[j]);
			}

			if (IsTheSameTree(tree_base, root))
			{
				res[i] = "YES";
			}
			else
			{
				res[i] = "NO";
			}
		}

		for (int i=0; i<n; i++)
		{
			cout << res[i] << endl;
		}
	}

	return 0;
}