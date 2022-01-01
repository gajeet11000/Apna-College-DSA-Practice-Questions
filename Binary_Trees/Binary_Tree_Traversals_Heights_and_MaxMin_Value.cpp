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

	void inOrder()
	{
		cout << "\n\nInOrder Traversal:-\n";
		inOrder(root);
	}

	void inOrder(Node* root)
	{
		if(root == NULL)
		{
			return;
		}

		inOrder(root->getLeft());
		cout << root->getData() << " ";
		inOrder(root->getRight());
	}

	void preOrder()
	{
		cout << "\n\npreOrder Traversal:-\n";
		preOrder(root);
	}

	void preOrder(Node* root)
	{
		if(root == NULL)
		{
			return;
		}

		cout << root->getData() << " ";
		preOrder(root->getLeft());
		preOrder(root->getRight());
	}

	void postOrder()
	{
		cout << "\n\npostOrder Traversal:-\n";
		postOrder(root);
	}

	void postOrder(Node* root)
	{
		if(root == NULL)
		{
			return;
		}

		postOrder(root->getLeft());
		postOrder(root->getRight());
		cout << root->getData() << " ";
	}

	int heightOfTree()
	{
		return heightOfTree(root);
	}

	int heightOfTree(Node* root)
	{
		if(root == NULL)
		{
			return 0;
		}

		int left_height = heightOfTree(root->getLeft()) + 1;
		int right_height = heightOfTree(root->getRight()) + 1;

		return max(left_height, right_height);
	}

	int numberOfNodes()
	{
		return numberOfNodes(root);
	}

	int numberOfNodes(Node* root)
	{
		if(root == NULL)
		{
			return 0;
		}

		int left_size = numberOfNodes(root->getLeft());
		int right_size = numberOfNodes(root->getRight());

		return left_size + right_size + 1;
	}

	int minValue()
	{
		return minValue(root);
	}

	int minValue(Node* root)
	{
		if(root == NULL)
		{
			return INT_MAX;
		}

		int left_max = minValue(root->getLeft());
		int right_max = minValue(root->getRight());

		return min(min(left_max, right_max), root->getData());
	}

	int maxValue()
	{
		return maxValue(root);
	}

	int maxValue(Node* root)
	{
		if(root == NULL)
		{
			return INT_MIN;
		}

		int left_max = maxValue(root->getLeft());
		int right_max = maxValue(root->getRight());

		return max(max(left_max, right_max), root->getData());
	}

	void levelOrder()
	{
		cout << "\n\nlevelOrder Traversal:-\n";
		levelOrder(root);
	}

	void levelOrder(Node* root)
	{
		queue<Node*> myqueue;
		myqueue.push(root);

		// Remove this push NULL statement if you
		// want to print the traversal in one line.
		myqueue.push(NULL);

		while(!myqueue.empty())
		{
			Node* front = myqueue.front();

			myqueue.pop();

			// For printing the level order traversal in one line
			// remove this if statement and unwrap the else part.
			if(front == NULL)
			{
				if(myqueue.empty())
				{
					break;
				}
				myqueue.push(NULL);
				printf("\n");
			}
			else
			{
				cout << front->getData() << " ";

				if(front->getLeft() != NULL)
				{
					myqueue.push(front->getLeft());
				}

				if(front->getRight() != NULL)
				{
					myqueue.push(front->getRight());
				}
			}
		}
	}
};


int main()
{
	BinaryTree bst;

	bst.inOrder();
	bst.preOrder();
	bst.postOrder();
	bst.levelOrder();

	cout << "\n\nHeight of the tree is: " << bst.heightOfTree();
	cout << "\n\nSize of the tree is: " << bst.numberOfNodes();

	cout << "\n\nMinimum value node of the tree is: " << bst.minValue();
	cout << "\n\nMaximum value node of the tree is: " << bst.maxValue();

	return 0;
}