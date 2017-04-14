#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
int size_of_table;
int table[30000][100];
vector<int> path;

void printMatches(int queries[], int query, int num_items, int num_query)
{

	if ( query <= 0)
		return;
	int pos = 0;
	//cout << query;
	//cout << num_items << "\n";
	for (int i = num_items -1; i >= 0; i--)
	{
		if ( table[query][i] == 0){
			pos = i+ 1;
			break;
		}
	}
	int new_query = query - queries[pos];
	if (new_query < 0)
		return;
	printMatches(queries, new_query, num_items, num_query);
	cout << pos + 1 << " ";
	//path.push_back(pos + 1);
}

void build_dp_table (int items[], int queries[], int num_items, int num_query)
{
	int i, j, x, y;
	size_of_table = queries[num_query -1] + 1;
	for ( i = 0; i < num_items; i++)
	{
		table[0][i] = 1;
	}

	for (i = 1; i < size_of_table; i++)
	{
		for(j = 0; j < num_items; j++)
		{
			if (i - items[j] >= 0)
			{
				x = table[i- items[j]][j];
			} else 
			{
				x = 0;
			}
			if (j >= 1)
				y = table[i][j-1];
			else
				y = 0;
			table[i][j] = x + y;
		}
	}
	for (i = 0; i < num_query; i++)
	{
		int count = table[queries[i]][num_items -1];
		if (count > 1){
			cout << "Ambiguous" << "\n";
		} else if (count < 1){
			cout << "Impossible" << "\n";
		} else {
			int q = queries[i];
			printMatches(items, q, num_items, num_query);
			// int counter = 1;
			// int pass_int = path[0];
			// cout << pass_int << " ";
			// for (vector<int>::iterator it = path.begin()+1; it != path.end(); it++)
			// {
			// 	if (pass_int == *it)
			// 	{
			// 		counter++;
			// 		//cout << *it << " ";
			// 		//cout << counter << "\n";
			// 	} else {
			// 		if (counter > 1)
			// 		{
			// 			cout << counter << " ";
			// 			counter = 1;
			// 		}
			// 		cout << *it << " ";
			// 		//counter++;
			// 	}
			// 	pass_int = *it;

			// }
			// if (counter > 1)
			// {
			// 	cout << counter << " ";
			// 	counter	= 0;
			// }
			cout << "\n";
			//path.clear();
		}
	}
}

int main ()
{
	// get menu item prices
	int num_item;
	scanf("%d", &num_item);
	int items[num_item];
	int price;
	for (int i = 0; i < num_item; i++)
	{
		scanf("%d", &price);
		items[i] = price;
	}
	int num_query;
	int number;
	scanf("%d", &num_query);
	int query[num_query];
	for (int i = 0; i < num_query; i++)
	{
		scanf("%d", &number);
		query[i] = number;
	}
	sort(query, query + num_query);
	build_dp_table(items, query, num_item, num_query);
	return 0;

}