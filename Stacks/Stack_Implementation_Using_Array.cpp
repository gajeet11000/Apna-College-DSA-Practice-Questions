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

#define size 5

class Stack
{
public:

	int *array;
	int top_ptr;

	Stack()
	{
		array = new int[size];
		top_ptr = -1;
	}

	void push(int data)
	{
		if(top_ptr == size-1)
		{
			cout << "Stack Overflow" << endl;
			return;
		}
		top_ptr++;
		array[top_ptr] = data;
	}

	int pop()
	{
		if(top_ptr == -1)
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		top_ptr--;
		return array[top_ptr+1];
	}

	int peek()
	{
		if(top_ptr == -1)
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		return array[top_ptr];
	}

	bool isEmpty()
	{
		if(top_ptr == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void display()
	{
		while(top_ptr != -1)
		{
			cout << this->pop() << " ";
		}
		cout << endl;
	}
};

int main()
{
	Stack my_stack;

	for(int i=0 ; i<5 ; i++)
	{
		my_stack.push(i*10);
	}

	my_stack.display();

	cout << my_stack.isEmpty() << endl;



	return 0;
}