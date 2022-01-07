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

	cout << "\nEnter left data for " << data << endl;
	root->left = createBinaryTree(root->left);

	cout << "\nEnter the right data for " << data << endl;
	root->right = createBinaryTree(root->right);

	return root;
}

int numberOfNodes(Node* &root)
{
	if(root == NULL)
	{
		return 0;
	}

	int left_tree_nodes = 0;
	int right_tree_nodes = 0;

	if(root->left != NULL)
	{
		left_tree_nodes = numberOfNodes(root->left);
	}
	if(root->right != NULL)
	{
		right_tree_nodes = numberOfNodes(root->right);
	}

	return left_tree_nodes + right_tree_nodes + 1; // 1 for the root node
}

int main()
{
	Node* root = createBinaryTree();

	// Tree to test-> 8 5 9 -1 -1 7 1 -1 -1 12 2 -1 -1 -1 4 -1 11 3 -1 -1 -1
	// Tree to test-> 8 5 -1 -1 -1
	// Ans: 10

	cout << "Number of nodes in the tree are: " << numberOfNodes(root) << endl;

	return 0;
}