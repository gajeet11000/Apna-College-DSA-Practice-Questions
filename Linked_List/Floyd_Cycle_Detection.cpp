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

void makeCycle(Node *&head, int position)
{
	Node *temp = head;
	Node *pos = NULL;

	int current_position{};

	while(temp->next != NULL)
	{
		if(current_position == position)
		{
			pos = temp;
		}
		current_position++;
		temp = temp->next;
	}

	temp->next = pos;
}

bool cycleDetection(Node *&head)
{
	Node *slow = head;
	Node *fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(fast == slow)
		{
			return true;
		}
	}
	return false;
}

void cycleRemoval(Node *&head)
{
	Node *slow = head;
	Node *fast = head;

	do
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	while(slow != fast);

	fast = head;

	while(fast->next != slow->next)
	{
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = NULL;
}

int main()
{
	Node *head = NULL;

	insertAtTail(head, 10);
	insertAtTail(head, 20);
	insertAtTail(head, 30);
	insertAtTail(head, 40);
	insertAtTail(head, 50);
	insertAtTail(head, 60);
	insertAtTail(head, 70);

	makeCycle(head, 3);

	cout << "Cycle Detection: " << cycleDetection(head) << endl;

	cycleRemoval(head);

	cout << "Cycle Detection: " << cycleDetection(head) << endl;

	cout << "\nList" << endl;
	displayList(head);

	return 0;
}