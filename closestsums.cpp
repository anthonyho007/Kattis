#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <sstream>

using namespace std;

void closest_sum (int list[], int number, int size)
{
	int diff;
	int sum = 0;

	int min = INT_MAX;
	int min_sum = sum;
	int start = 0;
	int end = size -1;
	while ( start < end)
	{
		sum = list[start] + list[end];
		diff = abs( number - sum);
		if (diff == 0)
		{
			cout << sum << ".\n";
			return;
		}
		if ( diff < min){
			min = diff;
			min_sum = sum;
		}
		if ( sum > number)
			end--;
		else
			start++;
	}
	cout << min_sum << ".\n";
}

int main ()
{

	int num_query = 0;
	int query;
	int counter = 1;
	int num_array;

	while (cin >> num_array)
	{
		int num_list[num_array];
		for (int i = 0; i < num_array; i++)
		{
			cin >> num_list[i];
		}
		sort(num_list, num_list + num_array);
		cin >> num_query;
		cout << "Case " << counter++ << ":\n";
		for ( int i = 0; i < num_query; i++)
		{
			cin >> query;
			cout << "Closest sum to " << query << " is ";
			closest_sum(num_list, query, num_array);
		}
	}
	return 0;
}