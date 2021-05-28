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

/**
 * @param number: an integer in which bit is to be found.
 * @param position: the position at which bit is to be
 * 					 found in the given number.
 */
bool getBit(int number, int position)
{
	return (number & (1 << position))!=0;
}

int setBit(int number, int position)
{
	return (number | (1 << position));
}

int clearBit(int number, int position)
{
	int ones_complement = ~(1 << position);
	return number & ones_complement;
}

/* Clears the bit at the given position
 * and then updates it with the given bit value at that position.
 */
int updateBit(int number, int bit_value, int position)
{
	number = clearBit(number, position);
	return (number | (bit_value << position));
}

int main()
{
	cout << "Get bit result: " << getBit(9, 0) << endl;
	cout << "Set bit result: " << setBit(21, 3) << endl;
	cout << "Clear bit result: " << clearBit(21, 2) << endl;    
	cout << "Update bit result: " << updateBit(21, 0, 2) << endl;

	return 0;
}

