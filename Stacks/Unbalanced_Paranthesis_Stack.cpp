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

bool isClosingBracket(char ch)
{
	return ch == ')' || ch == '}' || ch == ']';
}

bool isBalanced(string input)
{
	int length = input.length();

	stack<char> mystack;

	for(int i=0 ; i<length ; i++)
	{
		if(isClosingBracket(input[i]))
		{
			if(mystack.empty())
			{
				return false;
			}
			else if(input[i] == ')' && mystack.top() == '(') 
			{
				mystack.pop();
			}
			else if(input[i] == '}' && mystack.top() == '{')
			{
				mystack.pop();
			}
			else if(input[i] == ']' && mystack.top() == '[')
			{
				mystack.pop();
			}
			else
			{
				return false;
			}
		}
		else
		{
			mystack.push(input[i]);
		}
	}
	return mystack.empty();
}

int main()
{
	if(isBalanced("[{()}]"))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}

	return 0;
}