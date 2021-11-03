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

Node* reverseKNodes(Node *&head, int k)
{

	if(head == NULL || head->next == NULL || k == 0)
	{
		return head;
	}

	Node* previous_ptr = NULL;
	Node* current_ptr = head;
	Node* next_ptr = NULL;

	int k_temp = k;

	while(k_temp-- && current_ptr != NULL)
	{
		next_ptr = current_ptr->next;
		current_ptr->next = previous_ptr;

		previous_ptr = current_ptr;
		current_ptr = next_ptr;
	}

	reverseKNodes(next_ptr, k);

	head->next = next_ptr;
	head = previous_ptr;
	return head;
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
	Node* head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);     
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);

	displayList(head);
	Node *new_head = reverseKNodes(head, 2);
	displayList(new_head);

	return 0;
}