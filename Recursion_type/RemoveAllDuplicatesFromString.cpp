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

string removeDuplicates(string str, string check = "")
{
	if(str.empty())
	{
		return check; 
	}

	if(check.find(str[0]) == string::npos)
	{
		check += str[0];
	}

	return removeDuplicates(str.substr(1), check);	
}

int main()
{
	cout << "Enter a string with duplicate characters: ";
	string str;
	cin >> str;

	cout << "\nRemoved duplicate string: " << removeDuplicates(str) << endl;
	return 0;
}

