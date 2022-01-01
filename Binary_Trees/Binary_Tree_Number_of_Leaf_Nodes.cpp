#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

#define ll long long

using namespace std;

class BinaryTree
{
	class Node
	{
		int data;
		Node* left;
		Node* right;

	public:

		Node()
		{
			left = NULL;
			right = NULL;
		}

		Node(int data)
		{
			this->data = data;
			Node();
		}

		int getData()
		{
			return data;
		}

		void setData(int data)
		{
			this->data = data;
		}

		BinaryTree::Node* getLeft()
		{
			return left;
		}

		void setLeft(Node* left)
		{
			this->left = left;
		}

		BinaryTree::Node* getRight()
		{
			return right;
		}

		void setRight(Node* right)
		{
			this->right = right;
		}
	};
	
	Node* root;

public:

	BinaryTree()
	{
		root = createBinaryTree();
	}

	Node* createBinaryTree()
	{
		int data{};
		cout << "Enter the data: ";
		cin >> data;
		cout << endl;

		if(data == -1)
		{
			return NULL;
		}

		Node* node = new Node(data);

		cout << "Left data for " << data << ":\n";
		node->setLeft(createBinaryTree());

		cout << "Right data for " << data << ":\n";
		node->setRight(createBinaryTree());

		return node;
	}

	int numberOfLeafNodes()
	{
		return numberOfLeafNodes(root);
	}

	int numberOfLeafNodes(Node* root)
	{
		if(root == NULL)
		{
			return 0;
		}
		
		if(root->getLeft() == NULL && root->getRight() == NULL)
		{
			return 1;
		}

		int left_tree_leaf_nodes = numberOfLeafNodes(root->getRight());
		int right_tree_leaf_nodes = numberOfLeafNodes(root->getLeft());

		return left_tree_leaf_nodes + right_tree_leaf_nodes;
	}

};

int main()
{
	BinaryTree bt;

	// Tree input -> 2 7 2 -1 -1 6 5 -1 -1 11 -1 -1 5 -1 9 4 -1 -1 -1

	cout << "Number of leaf nodes in the tree are: " << bt.numberOfLeafNodes() << endl;
	return 0;
}