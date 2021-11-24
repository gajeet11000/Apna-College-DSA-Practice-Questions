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

void displayList(Node *head)
{
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int listSize(Node *&head)
{
	int count = 0;
	Node *temp = head;

	while(temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

void appendLastKNodes(Node *&head, int k)
{
	Node *new_head = NULL;
	Node *new_tail = NULL;

	Node *temp = head;
	int iterate_upto = listSize(head) - k - 1;

	while(temp->next != NULL)
	{
		if(iterate_upto == 0)
		{
			new_tail = temp;
			new_head = temp->next;
		}

		temp = temp->next;
		iterate_upto--;
	}

	new_tail->next = NULL;
	temp->next = head;
	head = new_head;
}

int main()
{
	Node *head = NULL;

	insertAtTail(head, 10);
	insertAtTail(head, 20);
	insertAtTail(head, 30);
	insertAtTail(head, 40);
	insertAtTail(head, 40);
	insertAtTail(head, 40);

	displayList(head);

	appendLastKNodes(head, 3);

	displayList(head);

	appendLastKNodes(head, 3);

	displayList(head);

	return 0;
}