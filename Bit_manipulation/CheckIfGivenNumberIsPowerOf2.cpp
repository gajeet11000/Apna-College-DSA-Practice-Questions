#include <unordered_map>
#include <map>
#include <string>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

bool isPowerOf2(int number)
{
	return (number && !(number & (number-1)));
}

int main()
{
	cout << isPowerOf2(0);
	return 0;
}

