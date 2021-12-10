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

void deleteHead(Node *&head)
{
	Node *to_delete = head;
	head = head->next;

	delete to_delete;
}

void deleteElement(Node *&head, int val)
{
	if(head == NULL)
	{
		return;
	}
	else if(head->next == NULL || head->data == val)
	{
		deleteHead(head);
	}
	else
	{
		Node *temp = head;

		while(temp->next->data != val)
		{
			temp = temp->next;
		}

		Node *to_delete = temp->next;

		temp->next = temp->next->next;

		delete to_delete;
	}
}


Node* reverseListIterative(Node *&head)
{

	Node *previous_ptr = NULL;
	Node *current_ptr = head;
	Node *next_ptr = NULL;

 	while(current_ptr != NULL)
 	{
 		next_ptr = current_ptr->next;
 		current_ptr->next = previous_ptr;

 		previous_ptr = current_ptr;
		current_ptr = next_ptr;
 	}
 	return previous_ptr;
}

Node* reverseListRecursive(Node *&head)
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	else
	{
		Node* new_head = reverseListRecursive(head->next);
		head->next->next = head;
		head->next = NULL;

		return new_head;
	}
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

	for(int i=0 ; i<5 ; i++)
	{
		insertAtTail(head, i+1);
	}

	displayList(head);

	Node* new_head = reverseListRecursive(head);

	displayList(new_head);

	return 0;
}