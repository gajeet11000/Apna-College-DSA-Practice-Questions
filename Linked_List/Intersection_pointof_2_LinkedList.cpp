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

bool intersectionPoint(Node *&first_head, Node *&second_head)
{
	int first_size = listSize(first_head);
	int second_size = listSize(second_head);

	Node *temp = (first_size > second_size)?first_head : second_head;
	int size_diff = abs(first_size - second_size);

	while(size_diff--)
	{
		if(temp == NULL)
		{
			return false;
		}
		temp = temp->next;
	}

	if(first_size > second_size)
	{
		first_head = temp;
	}
	else
	{
		second_head = temp;
	}

	bool intersection_found = false;
	int position = 1;

	while(first_head->next != NULL)
	{
		if(first_head == second_head)
		{
			cout << "Intersection at position: " << position << endl;
			intersection_found = true;
			break;
		}
		position++;
		first_head = first_head->next;
		second_head = second_head->next;
	}

	return intersection_found;
}

void intersectLinks(Node *&head1, Node *&head2, int position)
{
	Node *temp1 = head1;
	Node *temp2 = head2;

	position--;

	while(position--)
	{
		temp1 = temp1->next;
	}
	while(temp2->next != NULL)
	{
		temp2 = temp2->next;
	}

	temp2->next = temp1;
}

int main()
{
	Node *head1 = NULL;
	Node *head2 = NULL;
	Node *common = NULL;

	for(int i=1 ; i<5 ; i++)
	{
		insertAtTail(head1, i*10);
	}
	
	for(int i=1 ; i<9 ; i++)
	{
		insertAtTail(head2, i);
	}

	for(int i=100 ; i<106 ; i++)
	{
		insertAtTail(common, i);
	}

	intersectLinks(head2, head1, 5);

	displayList(head1);
	cout << endl;
	displayList(head2);
	cout << endl;

	if(intersectionPoint(head1, head2))
	{
		cout << "Intersection Found!" << endl;
	}
	else
	{
		cout << "No Intersection Found!" << endl;
	}
	return 0;
}