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

void allSubstringsASCII(string str, string ans = "")
{
	if(str.empty())
	{
		cout << ans << endl;
		return;
	}
	string remaining_string = str.substr(1);

	allSubstringsASCII(remaining_string, ans);

	allSubstringsASCII(remaining_string, ans + str[0]);

	allSubstringsASCII(remaining_string, ans + to_string((int)str[0]));
}

int main()
{
	cout << "Enter a string to find all it's substrings with ASCII: ";
	string str{};
	cin >> str;

	cout << "The substrings of " << str << " are:-" << endl;
	allSubstringsASCII(str);

	return 0;
}

