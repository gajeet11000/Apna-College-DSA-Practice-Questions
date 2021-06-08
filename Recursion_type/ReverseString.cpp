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

string reverse(string str)
{
	if(str.empty())
		return "";

	return reverse(str.substr(1)) + str[0];
}


int main()
{
	string str;
	cout << "Enter a string to reverse: ";
	cin >> str;

	cout << "\nReverse: " << reverse(str) << endl;
	return 0;
}
