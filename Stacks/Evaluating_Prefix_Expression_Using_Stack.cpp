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

int prefixEvaluate(string &exp)
{
	int length = exp.length();
	stack<int> operands;

	for(int i=length-1 ; i>=0 ; i--)
	{
		if(exp[i] >= '0' && exp[i] <= '9')
		{
			operands.push(exp[i] - '0');
		}
		else
		{
			int opr1 = operands.top();
			operands.pop();
			int opr2 = operands.top();
			operands.pop();

			switch(exp[i])
			{
				case '+':
					operands.push(opr1 + opr2);
					break;
				case '-':
					operands.push(opr1 - opr2);
					break;
				case '*':
					operands.push(opr1 * opr2);
					break;
				case '/':
					operands.push(opr1 / opr2);
					break;
				case '^':
					operands.push(pow(opr1,  opr2));
					break;
				case '%':
					operands.push(opr1 % opr2);
					break;
			}
		}
	}
	return operands.top();
}

int main()
{	
	string prefix_exp = "";
	cout << "Enter the prefix expression to evaluate:-" << endl;
	cin >> prefix_exp;

	//Example exp: -+7*45+20
	//Result: 25

	cout << "\nResult: " << prefixEvaluate(prefix_exp) << endl;
	return 0;
}