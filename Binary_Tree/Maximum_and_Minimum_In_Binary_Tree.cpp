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

	cout << "\nEnter the left data for " << data << endl;
	root->left = createBinaryTree(root->left);

	cout << "\nEnter the right data for " << data << endl;
	root->right = createBinaryTree(root->right);

	return root;
}

int maximumNode(Node* &root)
{
	if(root == NULL)
	{
		return INT_MIN;
	}

	int left_max = maximumNode(root->left);
	int right_max = maximumNode(root->right);

	return max(max(left_max, right_max), root->data);
}

int minimumNode(Node* &root)
{
	if(root == NULL)
	{
		return INT_MAX;
	}

	int left_min = minimumNode(root->left);
	int right_min = minimumNode(root->right);

	return min(min(left_min, right_min), root->data);
}

int main()
{
	Node* root = createBinaryTree();

	//Test tree-> 8 5 9 -1 -1 7 1 -1 -1 12 2 -1 -1 -1 4 -1 11 3 -1 -1 -1

	cout << "The minimum node in the tree is: " << minimumNode(root) << endl;
	cout << "The maximum node in the tree is: " << maximumNode(root) << endl;
	return 0;
}