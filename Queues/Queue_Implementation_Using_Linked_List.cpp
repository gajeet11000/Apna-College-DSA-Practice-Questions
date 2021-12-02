#include <unordered_map>
#include <string>
#include <map>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

#define ll long long

using namespace std;

class Queue
{
	class Node
	{
		int data;
		Node *next;

	public:

		Node(int data)
		{
			this->data = data;
			next = NULL;
		}

		int getData()
		{
			return data;
		}

		Queue::Node* getNext()
		{
			return next;
		}

		void setNext(Node *&next)
		{
			this->next = next;
		}
	};

	Node *front;
	Node *back;

public:

	Queue()
	{
		front = NULL;
		back = NULL;
	}

	bool isEmpty()
	{
		return front == NULL && back == NULL;
	}

	void enqueue(int data)
	{
		Node *new_node = new Node(data);

		if(isEmpty())
		{
			front = new_node;
			back = new_node;
		}
		else
		{
			back->setNext(new_node);
			back = new_node;
		}
	}

	void dequeue()
	{
		if(isEmpty())
		{
			cout << "Queue is empty, nothing to dequeue" << endl;
		}
		else 
		{
			Node *to_delete = front;

			front = front->getNext();
			//if there is only one node then here front will get NULL
			//if front get NULL then back must also be NULLed out.

			if(front == NULL) 
			{
				back = NULL;
			}
			delete to_delete;
		}
	}

	int peek()
	{
		if(isEmpty())
		{
			cout << "Queue is empty, returning -1" << endl;
		}
		else
		{
			return front->getData();
		}
	}

	void display()
	{
		if(isEmpty())
		{
			cout << "Queue is empty" << endl;
			return;
		}
		Node *temp = front;

		while(temp != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}
};

int main()
{
	Queue myqueue;

	for(int i=0 ; i<10 ; i++)
	{
		myqueue.enqueue((i+1)*10);
	}

	myqueue.display();

	for(int i=0 ; i<5 ; i++)
	{
		myqueue.dequeue();
	}

	myqueue.display();

	for(int i=0 ; i<6 ; i++)
	{
		myqueue.dequeue();
	}

	myqueue.display();

	return 0;
}