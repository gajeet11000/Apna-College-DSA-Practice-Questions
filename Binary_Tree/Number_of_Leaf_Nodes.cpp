#include <unordered_map>
#include <string>
#include <map>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

#define ll long long

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* createBinaryTree(Node* root = NULL)
{
	int data;
	cout << "Enter the data: ";
	cin >> data;

	if(data == -1)
	{
		return NULL;
	}

	root = new Node(data);

	cout << "Enter the left data " << data << endl;
	root->left = createBinaryTree(root->left);

	cout << "Enter the right data " << data << endl;
	root->right = createBinaryTree(root->right);

	return root;
}

int numberOfLeafNodes(Node* &root)
{
	if(root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	int leaves = 0;

	if(root->left != NULL)
	{
		leaves += numberOfLeafNodes(root->left);
	}

	if(root->right != NULL)
	{
		leaves += numberOfLeafNodes(root->right);
	}

	return leaves;
}

int main()
{
	Node* root = createBinaryTree();
	// Test tree-> 8 5 9 -1 -1 7 1 -1 -1 12 2 -1 -1 -1 4 -1 11 3 -1 -1 -1
	//Ans: 4

	cout << "Number of leaf nodes are: " << numberOfLeafNodes(root)<< endl;
	return 0;
}