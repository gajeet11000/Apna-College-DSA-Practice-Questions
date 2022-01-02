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

	cout << "\nEnter the left data for " << data << endl;
	root->left = createBinaryTree(root->left);
	
	cout << "\nEnter the right data for " << data << endl;
	root->right = createBinaryTree(root->right);

	return root;
}

void levelOrder(Node* &root)
{
	queue<Node*> myq;
	myq.push(root);

	while(!myq.empty())
	{
		Node* temp = myq.front();
		myq.pop();

		if(temp != NULL)
		{
			cout << temp->data << " ";
		}

		if(temp->left != NULL)
		{
			myq.push(temp->left);
		}

		if(temp->right != NULL)
		{
			myq.push(temp->right);
		}
	}
}

void levelOrderLinebyLine(Node* &root)
{
	queue<Node*> myq;
	myq.push(root);
	myq.push(NULL);

	while(!myq.empty())
	{
		Node* temp = myq.front();
		myq.pop();

		if(temp == NULL)
		{
			if(myq.empty())
			{
				break;
			}
			else
			{
				cout << endl;
				myq.push(NULL);
			}
		}
		else
		{
			cout << temp->data << " ";

			if(temp->left != NULL)
			{
				myq.push(temp->left);
			}

			if(temp->right != NULL)
			{
				myq.push(temp->right);
			}
		}

	}
}

int main()
{
	Node* root = createBinaryTree();

	cout << "\n\nLevel Order Traversal ->" << endl;
	levelOrder(root);

	cout << "\n\nLevel Order Traversal Line by Line->" << endl;
	levelOrderLinebyLine(root);

	// Tree -> 2 7 2 -1 -1 6 5 -1 -1 11 -1 -1 5 -1 9 4 -1 -1 -1 -1

	return 0;
}