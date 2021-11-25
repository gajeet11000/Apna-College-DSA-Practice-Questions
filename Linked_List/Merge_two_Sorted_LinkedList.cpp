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
	int size = 0;
	Node *temp = head;

	while(temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return size;
}

Node* mergeSortedListsIterative(Node *&head1, Node *&head2)
{
	Node *new_list = new Node(-1);

	Node *ptr1 = head1;
	Node *ptr2 = head2;
	Node *ptr3 = new_list;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->data < ptr2->data)
		{
			ptr3->next = ptr1;
			ptr1 = ptr1->next;
		}
		else
		{
			ptr3->next = ptr2;
			ptr2 = ptr2->next;
		}
		ptr3 = ptr3->next;
	}

	while(ptr1 != NULL)
	{
		ptr3->next = ptr1;
		ptr3 = ptr3->next;

		ptr1 = ptr1->next;
	}

	while(ptr2 != NULL)
	{
		ptr3->next = ptr2;
		ptr3 = ptr3->next;

		ptr2 = ptr2->next;
	}

	// Instead of the above two while loops
	// you can just use these if statement
	//to do the same.
	
	// if(ptr1 == NULL)
	// {
	// 	ptr3->next = ptr2;
	// }
	// if(ptr2 == NULL)
	// {
	// 	ptr3->next = ptr1;
	// }

	return new_list->next;
}

Node* mergeSortedListsRecursive(Node *&head1, Node *&head2)
{
	Node *new_list = NULL;

	if(head1 == NULL)
	{
		return head2;
	}
	if(head2 == NULL)
	{
		return head1;
	}

	if(head1->data < head2->data)
	{
		new_list = head1;
		new_list->next = mergeSortedListsRecursive(head1->next, head2);
	}
	else
	{
		new_list = head2;
		new_list->next = mergeSortedListsRecursive(head1, head2->next);
	}

	return new_list;

}


int main()
{
	Node *head1 = NULL;
	Node *head2 = NULL;

	for(int i=1 ; i<9 ; i+=2)
	{
		insertAtTail(head1, i);
	}
	
	for(int i=2 ; i<9 ; i+=2)
	{
		insertAtTail(head2, i);
	}

	cout << "First List: ";
	displayList(head1);
	cout << "Second List: ";
	displayList(head2);

	// Node *new_list = mergeSortedListsIterative(head1, head2);
	Node *new_list = mergeSortedListsRecursive(head1, head2);

	cout << "\nMerged List: ";
	displayList(new_list);

	cout << endl;
	return 0;
}