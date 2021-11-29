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

class Stack
{
public: 
	Stack *prev;
	int data;

	Stack(int val)
	{
		prev = NULL;
		data = val;
	}
};

void push(Stack *&stack, int data)
{
	Stack *new_top = new Stack(data);
	new_top->prev = stack;
	stack = new_top;
}

void pop(Stack *&stack)
{
	if(stack == NULL)
	{
		cout << "No elements to pop" << endl;
		return;
	}
	Stack *to_delete = stack;
	stack = stack->prev;
	delete to_delete;
}

void top(Stack *&stack)
{

	if(stack == NULL)
	{
		cout << "Stack is empty, no elements to show" << endl;
	}
	else
	{
		cout << stack->data <<endl;
	}
}

int main()
{
	Stack* stack = NULL;
	push(stack, 24);
	push(stack, 23);

	top(stack);
	pop(stack);

	top(stack);
	pop(stack);

	top(stack);
	pop(stack);
	return 0;

}