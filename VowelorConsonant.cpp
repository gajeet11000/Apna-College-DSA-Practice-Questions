#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

bool isVowel(char ch)
{
	ch = (char) tolower(ch);
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char ch;
	cout << "Enter an alphabet: ";
	cin >> ch;

	if(isVowel(ch))
	{
		cout << ch << " is a Vowel." << endl;
	}
	else
	{
		cout << ch << " is a Consonant." << endl;
	}
	return 0;
}

