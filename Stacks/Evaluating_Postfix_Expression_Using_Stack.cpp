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

int postfixEvaluate(string exp)
{
	int length = exp.length();
	stack<int> operands;

	for(int i=0 ; i<length ; i++)
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
					operands.push(opr2 - opr1);
					break;
				case '*':
					operands.push(opr2 * opr1);
					break;
				case '/':
					operands.push(opr2 / opr1);
					break;
				case '^':
					operands.push(pow(opr2,  opr1));
					break;
				case '%':
					operands.push(opr2 % opr1);
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

	//Example exp: 46+2/5*7+
	//Result: 25

	cout << "\nResult: " << postfixEvaluate(prefix_exp) << endl;
	return 0;
}