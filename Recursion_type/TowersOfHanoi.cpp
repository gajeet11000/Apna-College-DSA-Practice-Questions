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

void towersOfHanoi(int dics, char from, char spare, char to)
{
	if(dics == 1)
	{
		cout << "Moving from " << from << " to " << to << "." << endl;
	}
	else
	{
		towersOfHanoi(dics-1, from, to, spare);

		cout << "Moving from " << from << " to " << to << "." << endl;

		towersOfHanoi(dics-1, spare, from, to);
	}
}

int main()
{
	cout << "Enter the number of dics: ";
	int dics{};
	cin >> dics;

	towersOfHanoi(dics, 'A', 'B', 'C');
	return 0;
}

