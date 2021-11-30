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

int precedence(char op)
{
	if(op == '^')
	{
		return 3;
	}
	else if(op == '*' || op == '/')
	{
		return 2;
	}
	else if(op == '+' || op == '-')
	{
		return 1;
	}
	else
		return -1;

}

string infixToPostfix(string infix_exp)
{
	string postfix_exp = "";

	int length = infix_exp.length();
	stack<char> mystack;

	for(int i=0 ; i<length ; i++)
	{
		if(infix_exp[i] >= 'a' && infix_exp[i] <= 'z')
		{
			postfix_exp += infix_exp[i];
		}
		else if(precedence(infix_exp[i]) == -1)
		{
			if(infix_exp[i] == '(')
			{
				mystack.push(infix_exp[i]);
			}
			else
			{
				while(!mystack.empty())
				{
					if(mystack.top() != '(')
					{
						postfix_exp += mystack.top();
					}
					mystack.pop();
				}
			}
		}
		else if(!mystack.empty() && precedence(mystack.top()) > precedence(infix_exp[i]))
		{
			postfix_exp += mystack.top();
			mystack.pop();
			mystack.push(infix_exp[i]);
		}
		else
		{
			mystack.push(infix_exp[i]);
		}
	}

	while(!mystack.empty())
	{
		postfix_exp += mystack.top();
		mystack.pop();
	}
	return postfix_exp;
}

string reverseExpression(string exp)
{
	string reverse = "";
	int length = exp.length();

	for(int i=0 ; i<length ; i++)
	{
		if(exp[i] == '(')
		{
			reverse = ")" + reverse;
		}
		else if(exp[i] == ')')
		{
			reverse = "(" + reverse;
		}
		else
			reverse = exp[i] + reverse;
	}

	return reverse;
}

string infixToPrefix(string infix_exp)
{
	return reverseExpression(infixToPostfix(reverseExpression(infix_exp)));
}

int main()
{
	string infix_exp =  "(a-b/c)*(a/k-l)";

	cout << "Infix Expression: " << infix_exp << endl;

	cout << "\nReverse Expression: " << reverseExpression(infix_exp) << endl;
	cout << "\nPrefix Expression: " << infixToPrefix(infix_exp) << endl;
	cout << "\nPostfix Expression: " << infixToPostfix(infix_exp) << endl;
	return 0;
}