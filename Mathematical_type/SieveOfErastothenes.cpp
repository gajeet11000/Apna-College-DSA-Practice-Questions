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

void sievePrimes(int range)
{
	int size{range + 1};

	int prime_array[size]{};

	for(int i=2 ; i<size ; i++)
	{
		if(prime_array[i] == 0)
		{
			for(int j=i*i ; j<size ; j+=i)
			{
				prime_array[j] = 1;
			}	
		}
	}

	for(int i=2 ; i<size ; i++)
	{
		if(prime_array[i] == 0)
			cout << i << " ";
	}

}

int main()
{
	cout << "The range between the prime numbers are to be found: ";
	int range{}; 
	cin >> range;

	cout << "\nThe prime numbers till " << range << " are:-" << endl;
	sievePrimes(range);

	return 0;
}

