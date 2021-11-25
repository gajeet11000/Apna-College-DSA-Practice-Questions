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
	Node *next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

Node* insertAtTail(Node *&head, int data)
{
	Node *new_node = new Node(data);

	if(head == NULL)
	{
		new_node->next = new_node;
		head = new_node;
		return new_node;
	}

	Node *temp = head;

	while(temp->next != head)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->next = head;

	return new_node; //Returns newly created node for insertAtHead()
}


//Insert at head is the same as insert at tail
// but in insert at head at last we just make the
// newly created node the head node.

void insertAtHead(Node *&head, int data)
{
	head = insertAtTail(head, data);
}

void deleteHead(Node *&head)
{
	Node *to_delete = head;

	Node *new_head = head->next;
	Node *temp = head;

	while(temp->next != head)
	{
		temp = temp->next;
	}
	temp->next = new_head;
	head = new_head;

	delete to_delete;
}

void deleteElement(Node *&head, int position)
{
	if(position == 0)
	{
		deleteHead(head);
		return;
	}

	Node *temp = head;

	while(--position)
	{
		temp = temp->next;
	}

	Node *to_delete = temp->next;
	temp->next = temp->next->next;

	delete to_delete;

}

void displayList(Node *head)
{
	Node *temp = head;

	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	while(temp != head);

	cout << endl;
}

int main()
{
	Node *head = NULL;

	for(int i=1 ; i<7 ; i++)
	{
		insertAtTail(head, i);
	}

	displayList(head);

	// insertAtHead(head, 50);

	// deleteElement(head, 0);
	deleteElement(head, 5);

	displayList(head);

	return 0;
}