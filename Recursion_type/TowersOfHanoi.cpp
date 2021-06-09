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

int step{1};

void towersOfHanoi(int dics, int from, int to)
{
	int temp = 6 - from -to;

	if(dics == 1)
	{
		cout << step++ << ". Moving from " << from << " to " << to << "." << endl;
	}
	else
	{
		towersOfHanoi(dics-1, from, temp);

		cout << step++ << ". Moving from " << from << " to " << to << "." << endl;

		towersOfHanoi(dics-1, temp, to);
	}
}

int main()
{
	cout << "Enter the number of dics: ";
	int dics{};
	cin >> dics;

	towersOfHanoi(dics, 1, 3);
	return 0;
}

