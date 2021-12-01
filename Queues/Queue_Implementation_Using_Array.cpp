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

#define N 20
#define ll long long

using namespace std;

class Queue
{
	int *array;
	int back;

public:

	Queue()
	{
		array = new int[N];
		back = -1;
	}

	bool isEmpty()
	{
		return back == -1;
	}

	bool isFull()
	{
		return back == N-1;
	}

	void enqueue(int data)
	{
		if(isFull())
		{
			cout << "Sorry, cannot push the queue is full." << endl;
		}
		else
		{
			back++;
			array[back] = data;
		}
	}

	void dequeue()
	{
		if(isEmpty())
		{
			cout << "Sorry, cannot pop the queue is empty." << endl;
		}
		else
		{
			int i = 0;
			while(i < back)
			{
				array[i] = array[i+1];
				i++;
			}
			back--;
		}
	}

	int peek()
	{
		if(isEmpty())
		{
			cout << "Queue is empty returning -1" << endl;
			return -1;
		}
		return array[0];
	}

	void display()
	{
		if(isEmpty())
		{
			cout << "No elements to display queue is empty." << endl;
		}
		else
		{
			for(int i=0 ; i<=back ; i++)
			{
				cout << array[i] << " "; 
			}
			cout << endl;
		}
	}
};

int main()
{
	Queue myqueue;

	for(int i=0 ; i<20 ; i++)
	{
		myqueue.enqueue((i+1)*10);
	}

	myqueue.display();

	myqueue.enqueue(999);

	myqueue.dequeue();

	myqueue.display();

	myqueue.enqueue(999);

	myqueue.display();

	// for(int i=0 ; i<5 ; i++)
	// {
	// 	myqueue.dequeue();
	// }

	// for(int i=0 ; i<15 ; i++)
	// {
	// 	myqueue.dequeue();
	// }

	// myqueue.display();

	// myqueue.dequeue();

	return 0;
}