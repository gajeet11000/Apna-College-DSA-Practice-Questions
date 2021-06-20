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

int stealingAttempt(int knapsack_weight, int number_of_items,
					int weight_of_items[], int cost_of_items[])
{
	if(knapsack_weight <= 0 || number_of_items == 0)
	{
		return 0;
	}
	if(weight_of_items[number_of_items -1]  > knapsack_weight)
	{
		return stealingAttempt(knapsack_weight, number_of_items-1, weight_of_items, cost_of_items);
	}	

	int including_this_item = stealingAttempt(knapsack_weight - weight_of_items[number_of_items-1], number_of_items-1, weight_of_items, cost_of_items) + cost_of_items[number_of_items-1];

	int without_including_this_item = stealingAttempt(knapsack_weight, number_of_items-1, weight_of_items, cost_of_items);

	return max(including_this_item, without_including_this_item);

}

void input(int array[], int size)
{
	for(int i=0 ; i<size ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	cout << "Enter the knapsack weight capacity: ";
	int knapsack_weight{};
	cin >> knapsack_weight;

	cout << "\nEnter the number of items: ";
	int number_of_items{};
	cin >> number_of_items;

	cout << "\nEnter the weight of the items:-" << endl;
	int weight_of_items[number_of_items]{};
	input(weight_of_items, number_of_items);

	cout << "\nEnter the cost of the items:-" << endl;
	int cost_of_items[]{};
	input(cost_of_items, number_of_items);

	cout << "\nThe maximum value the thief can get away with: "
		 << stealingAttempt(knapsack_weight, number_of_items, weight_of_items, cost_of_items) 
		 << endl;

	return 0;
}

