#include <unordered_map>
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
bool isPalindrome(int length, const char word[])
{
	bool check{true};
	
	int i{};
	while(word[i] != '\0')
	{
		if(word[i] != word[length-1-i])
		{
			check = false;
			break;
		}
		i++;
	}
	return check;
}

int main()
{
	int length{};
	cout << "Enter the length of the word: ";
	cin >> length;

	char word[length+1];
	cout << "\nEnter the word: ";
	cin >> word;

	cout << endl;

	if(isPalindrome(length, word))
	{
		cout << word << " is plaindrome." << endl;
	}
	else
	{
		cout << word << " is not a palindrome." << endl;
	}
	return 0;
}

