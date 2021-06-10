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

void allSubstrings(string str, string ans = "")
{
	if(str.empty())
	{
		cout << ans << endl;
		return;
	}
	string remaining_string = str.substr(1);

	allSubstrings(remaining_string, ans);

	allSubstrings(remaining_string, ans + str[0]);
}

int main()
{
	cout << "Enter a string to find all it's substrings: ";
	string str{};
	cin >> str;

	cout << "The substrings of " << str << " are:-" << endl;
	allSubstrings(str);

	return 0;
}

