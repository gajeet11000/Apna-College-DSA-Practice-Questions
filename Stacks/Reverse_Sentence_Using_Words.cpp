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

void reverseSentence(string s)
{
	stack<string> reverse;
	int length = s.length();

	string word = "";

	for(int i=0 ; i<=length ; i++)
	{
		if(s[i] == ' ' || i == length)
		{
			reverse.push(word);
			word = "";
		}
		else
		{
			word += s[i];
		}
	}

	while(!reverse.empty())
	{
		cout << reverse.top() << " ";
		reverse.pop();
	}

}

int main()
{
	
	string str;
	cout << "Enter a sentence:-\n";
	getline(cin, str);

	cout << "\nReverse:-\n";
	reverseSentence(str);

	return 0;
}