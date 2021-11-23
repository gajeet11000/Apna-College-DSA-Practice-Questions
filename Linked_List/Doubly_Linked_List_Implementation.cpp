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

	Node *prev;
	Node *next;
	int data;

	Node(int val)
	{
		prev = NULL;
		data = val;
		next = NULL;
	}
};

void insertAtHead(Node *&head, int val)
{
	Node *new_node = new Node(val);

	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}

void insertAtTail(Node *&head, int val)
{
	Node *new_node = new Node(val);

	if(head == NULL)
	{
		insertAtHead(head, val);
	}
	else
	{
		Node *temp = head;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new_node;
		new_node->prev = temp;
	}

}



void deleteAtHead(Node *&head)
{
	Node *temp = head;

	head = head->next;
	head->prev = NULL;

	delete temp;
}

void deleteElement(Node *&head, int pos)
{
	if(pos == 0)
	{
		deleteAtHead(head);
		return;
	}

	Node *temp = head;
	int count = 0;

	while(count != pos && temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	temp->prev->next = temp->next;

	if(temp->next != NULL)
	{
		temp->next->prev = temp->prev;
	}

	delete temp;
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

	displayList(head);

	deleteElement(head, 3);

	displayList(head);

	deleteElement(head, 0);

	displayList(head);


	return 0;
}