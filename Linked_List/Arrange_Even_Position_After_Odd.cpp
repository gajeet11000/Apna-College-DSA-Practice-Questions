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

void evenAfterOdd(Node *&head)
{
	Node *even_start = head->next;
	Node *even = even_start;

	Node *odd = head;

	while(odd->next != NULL && even->next != NULL)
	{
		odd->next = even->next;
		odd = odd->next;

		even->next = odd->next;
		even = even->next;
	}

	odd->next = even_start;
}

int main()
{
	Node *head = NULL;

	for(int i=1 ; i<4 ; i++)
	{
		insertAtTail(head, i);
	}

	displayList(head);

	evenAfterOdd(head);
	// cout << "End";

	displayList(head);

	return 0;
}