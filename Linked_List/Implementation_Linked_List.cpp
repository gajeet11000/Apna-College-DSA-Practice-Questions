#include <unordered_map>
#include <string>
#include <map>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

void insertAtTail(Node* &head, int data)
{
	Node* new_node = new Node(data);

	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		Node* temp = head;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new_node;
	}
}

void insertAtHead(Node *&head, int data)
{
	Node* new_node = new Node(data);
	new_node->next = head;
	head = new_node;
}

bool search(Node *head, int key)
{
	Node* temp = head;

	while(temp != NULL)
	{
		if(temp->data == key)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void display_list(Node *head)
{
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;

	insertAtTail(head, 60);
	insertAtTail(head, 100);
	insertAtTail(head, 101);
	insertAtTail(head, 110);

	insertAtHead(head, 214);
	insertAtHead(head, 78);
	insertAtHead(head, 112);

	display_list(head);

	if(search(head, 24))
	{
		cout << "Found!" << endl;
	}
	else
	{
		cout << "Not Found!" << endl;
	}

	return 0;
}