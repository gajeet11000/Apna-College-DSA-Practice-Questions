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
#include <stack>

#define ll long long

using namespace std;

void pushToBottom(stack<int> &mystack, int element)
{
	if(mystack.empty())
	{
		mystack.push(element);
		return;
	}
	int top_element = mystack.top();
	mystack.pop();
	
	pushToBottom(mystack, element);
	mystack.push(top_element);
}

void reverseStack(stack<int> &mystack)
{
	if(mystack.empty())
	{
		return;
	}

	int top_element = mystack.top();
	mystack.pop();

	reverseStack(mystack);
	pushToBottom(mystack, top_element);
}

void printStack(stack<int> &mystack)
{
	while(!mystack.empty())
	{
		cout << mystack.top() << endl;
		mystack.pop();
	}
	cout << endl;
}

void fillStack(stack<int> &mystack)
{
	for(int i=1 ; i<=5 ; i++)
	{
		mystack.push(i*10);
	}
}

int main()
{
	stack<int> mystack;

	fillStack(mystack);

	cout << "Original Stack is:- " << endl;
	printStack(mystack);

	fillStack(mystack);

	reverseStack(mystack);

	cout << "Reverse Stack is:- " << endl;
	printStack(mystack);
	return 0;
}