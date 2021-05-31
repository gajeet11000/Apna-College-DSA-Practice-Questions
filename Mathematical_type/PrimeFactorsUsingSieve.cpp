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

void primeFactorsSieve(int number)
{
	int size{number+1};
	int smallest_prime_factor[size]{};

	for(int i=2 ; i<size ; i++)
	{
		smallest_prime_factor[i] = i;
	}

	for(int i=2 ; i<size ; i++)
	{
		if(smallest_prime_factor[i] == i)
		{
			for(int j=i*i ; j<size ; j+=i)
			{
				if(smallest_prime_factor[j] == j)
				{
					smallest_prime_factor[j] = i;
				}
			}
		}
	}

	while(number != 1)
	{
		cout << smallest_prime_factor[number] << " ";
		number /= smallest_prime_factor[number];
	}

	return;
}

int main()
{
	cout << "Enter a number to find it's prime factors: ";
	int number{};
	cin >> number;

	cout << "\nThe prime factors of " << number << " are:-" << endl;
	primeFactorsSieve(number);
	return 0;
}

