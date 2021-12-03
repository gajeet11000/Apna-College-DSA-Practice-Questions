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
#include <queue>

#define ll long long

using namespace std;

class Stack
{
	int N;
	queue<int> primary_q, secondary_q;

public:

	Stack()
	{
		N = 0;
	}

	void push(int data)
	{
		secondary_q.push(data);

		while(!primary_q.empty())
		{
			secondary_q.push(primary_q.front());
			primary_q.pop();
		}
		//transfer all the elements in secondary_q to primary_q
		//which becomes empty after the above while loop
		//so after this secondary_q will be empty again
		swap(primary_q, secondary_q);
		N++;
	}

	int pop()
	{
		if(primary_q.empty())
		{
			cout << "Nothing to pop the stack is empty." << endl;
			return -1;
		}
		int top = primary_q.front();
		primary_q.pop();
		N--;
		return top;
	}

	int size()
	{
		return N;
	}

};

int main()
{
	Stack mystack;

	for(int i=0 ; i<5 ; i++)
	{
		mystack.push((i+1)*10);
	}

	cout << "Size: " << mystack.size() << endl;

	for(int i=0 ; i<5 ; i++)
	{
		cout << mystack.pop() << " ";
	}
	cout << endl;
	mystack.pop();
	return 0;
}