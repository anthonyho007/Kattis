#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int i, int j)
{
	return i > j;
}

int main()
{
	int n, num;
	cin >> n;
	int items[n];
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		items[i] = num;
	}
	sort( items, items+n, comp);
	long discount = 0;
	for(int i = 0; i < n; i++)
	{
		if ( i % 3 == 2)
		{
			discount += items[i];
		}
	}
	cout << discount << endl;

}