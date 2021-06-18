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

int tilingWays(int n)
{
	if(n < 3)
	{
		return n;
	}
	
	return tilingWays(n-1) + tilingWays(n-2);
}

int main()
{
	cout << "Enter n for (2 x n): ";
	int n{};
	cin >> n;

	cout << "Number of ways to tile the blocks are: "
		 << tilingWays(n);
	return 0;
}

