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

string maximumFrequencyUsingMap(string sentence)
{
	map<char, int> char_frequency;
	int length = sentence.length();

	transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper);

	for(int i=0 ; i<length ; i++)
	{
		if(sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			char_frequency[sentence[i]]++;
		}
	}

	int max_frequency{-1};
	string frequent_chars = "";

	for(auto i: char_frequency)
	{
		if(max_frequency < i.second)
		{
			max_frequency = i.second;
			frequent_chars.clear();
			frequent_chars.append(1, i.first).append(" ");
		}
		else if(max_frequency == i.second)
		{
			frequent_chars.append(1, i.first).append(" ");
		}
	}
	
	frequent_chars = "Frequent characters: " + frequent_chars;
	frequent_chars += "\nFrequency: " + to_string(max_frequency);

	return frequent_chars;
}

string maximumFrequencyUsingArray(string sentence)
{
    
	int length = sentence.length();

	int char_frequency[26]{};

	transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper);

	for(int i=0 ; i<length ; i++)
	{
		if(sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			char_frequency[(int)sentence[i] - 65]++ ;
		}
	}

	int max_frequency{-1};
	string frequent_chars = "";

	for(int i=0 ; i<26 ; i++)
	{
		if(max_frequency < char_frequency[i])
		{
			max_frequency = char_frequency[i];
			frequent_chars.clear();
			frequent_chars.append(1, (char)('A'+i)).append(" ");
		}
		else if(max_frequency == char_frequency[i])
		{
			frequent_chars.append(1, (char)('A'+i)).append(" ");
		}
	}
	
	frequent_chars = "Frequent characters: " + frequent_chars;
	frequent_chars += "\nFrequency: " + to_string(max_frequency);
	

	return frequent_chars;
}

int main()
{
	string sentence;
	cout << "Enter the string: ";
	getline(cin, sentence);

	cout << "\nUsing Map:-" << endl;

	cout << maximumFrequencyUsingMap(sentence) << endl << endl;

	cout << "Using Array:-" << endl;

	string answer = maximumFrequencyUsingArray(sentence);
	cout << answer << endl;
	cout << endl << "Done";

	return 0;
}

