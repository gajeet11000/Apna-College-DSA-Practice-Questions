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
		primary_q.push(data);
		N++;
	}

	int pop()
	{
		int top = -1;

		if(primary_q.empty())
		{
			cout << "Stack is empty, nothing to pop" << endl;
			return top;
		}

		while(!primary_q.empty())
		{
			if(N==1)
			{
				top = primary_q.front();
			}
			else
			{
				secondary_q.push(primary_q.front());
			}
			primary_q.pop();
			N--;
		}

		N = secondary_q.size();
		swap(primary_q, secondary_q);
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

	for(int i=0 ; i<3 ; i++)
	{
		cout << mystack.pop() << endl;
	}
	
	cout << mystack.size()<< endl;
	return 0;
}