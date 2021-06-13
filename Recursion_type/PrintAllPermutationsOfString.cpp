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

void allPermutations(string str, string fixed = "")
{
	if(str.length() == 1)
	{
		cout << fixed + str << endl;
	}
	else
	{
		int length = str.length();
		for(int i=0 ; i<length ; i++)
		{
			string new_string = str.substr(0, i) + str.substr(i+1); //new string without the fixed letter.
			allPermutations(new_string, fixed+str[i]);
		}
	}
}

int main()
{
	cout << "Enter the string to print all it's permutations: ";
	string str{};
	cin >> str;

	allPermutations(str);
	return 0;
}

