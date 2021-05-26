#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int long addTwoBinaryNumbers(int long a, int long b)
{
	int carry{};
	int alast_digit{};
	int blast_digit{};
	int long multiplier{1};
	int long sum{};

	while(a > 0 && b > 0)
	{
		alast_digit = a % 10;
		blast_digit = b % 10;

		if(alast_digit == 0 && blast_digit == 0)
		{
			if(carry == 1)
			{
				sum += multiplier;
				carry = 0;
			}
		}
		else if((alast_digit == 1 && blast_digit == 0) || (alast_digit == 0 && blast_digit == 1))
		{
			sum += multiplier;
		}
		else
		{
			if(carry == 1)
			{
				sum += multiplier;
			}
			else
			{
				carry = 1;
			}
		}
		multiplier *= 10;
		a /= 10;
		b /= 10;
	}

	while(a > 0)
	{
		alast_digit = a % 10;
		if(alast_digit == 1)
		{
			if(carry == 0)
			{
				sum += multiplier;
			}
		}
		else if(carry == 1)
		{
			sum += multiplier;
			carry = 0;
		}
		a /= 10;
		
		multiplier *= 10;
	}

	while(b > 0)
	{
		blast_digit = b % 10;
		if(blast_digit == 1)
		{
			if(carry == 0)
			{
				sum += multiplier;
			}
		}
		else if(carry == 1)
		{
			sum += multiplier;
			carry = 0;
		}
		b /= 10;

		multiplier *= 10;
	}
	sum += carry * multiplier;


	return sum;

}

int main()
{
	int long a, b;
	cout << "Enter two binary numbers to add them: ";
	cin >> a >> b;

	cout << "\n" << addTwoBinaryNumbers(a, b);
	return 0;
}
