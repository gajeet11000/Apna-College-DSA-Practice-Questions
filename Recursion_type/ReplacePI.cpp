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

string replacePI(string str)
{
	if(str.length() < 2)
	{
		return str;
	}
	if(str.substr(0, 2) == "pi")
	{
		return "3.14" + replacePI(str.substr(2));
	}

	return str[0] + replacePI(str.substr(1));
}

int main()
{
	cout << "Enter a string with \"pi\" in it: ";
	string str;
	cin >> str;

	cout << "\nReplaced string: " << replacePI(str) << endl;

	return 0;
}

