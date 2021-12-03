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
	stack<int> stack1, stack2;

public:

	void enqueue(int data)
	{
		stack1.push(data);
	}

	int dequeue()
	{
		int top = -1;

		if(stack1.empty() and stack2.empty())
		{
			cout << "Nothing to dequeue, queue is empty." << endl;
			return top;
		}

		while(!stack1.empty())
		{
			if(stack1.size() > 1)
			{
				stack2.push(stack1.top());
			}
			top = stack1.top();
			stack1.pop();
		}

		while(!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return top;
	}

	int dequeueRecursively()
	{
		int temp = -1;
		if(stack1.empty())
		{
			cout << "Nothing to dequeue, queue is empty." << endl;
			return temp;
		}

		temp = stack1.top();
		stack1.pop();

		if(stack1.empty())
		{
			return temp;
		}

		int front = dequeueRecursively();
		stack1.push(temp);
		return front;
	}
};

int main()
{
	Queue myqueue;

	for(int i=0 ; i<5 ; i++)
	{
		myqueue.enqueue((i+1)*10);
	}

	for(int i=0 ; i<5 ; i++)
	{
		cout << myqueue.dequeueRecursively() << endl;
	}

	cout << myqueue.dequeueRecursively() << endl;
	return 0;
}