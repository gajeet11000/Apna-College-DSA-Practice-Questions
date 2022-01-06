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
	int data{} ;
	cout << "Enter the data: ";
	cin >> data;

	if(data < 0)
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

int height(Node* &root)
{
	if(root == NULL)
	{
		return 0;
	}

	int left_height = height(root->left) + 1;
	int right_height = height(root->right) + 1;

	return max(left_height, right_height);
}

int main()
{
	Node* root = createBinaryTree();

	cout << "The height of the tree is: " << height(root) << endl;

	// Tree to test-> 8 5 9 -1 -1 7 1 -1 -1 12 2 -1 -1 -1 4 -1 11 3 -1 -1 -1
	// Ans: 5

	return 0;
}