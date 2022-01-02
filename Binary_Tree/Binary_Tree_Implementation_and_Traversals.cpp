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
	int data{};
	cout << "Enter the data: ";
	cin >> data;

	if(data == -1)
	{
		return NULL;
	}

	root = new Node(data);

	cout << "Enter the left data for " << data << endl;
	root->left = createBinaryTree(root->left);
	
	cout << endl;

	cout << "Enter the right data for " << data << endl;
	root->right = createBinaryTree(root->right);

	cout << endl;

	return root;
}

void inOrder(Node* &root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

void preOrder(Node* &root)
{
	if(root != NULL)
	{
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Node* &root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}
}

int main()
{
	Node* root = createBinaryTree();

	cout << "InOrder Traversal ->" << endl;
	inOrder(root);

	cout << "\nPreOrder Traversal ->" << endl;
	preOrder(root);

	cout << "\nPostOrder Traversal ->" << endl;
	preOrder(root);

	return 0;
}