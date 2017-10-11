#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main ()
{
	int w, n;
	scanf("%d %d", &w, &n);
	int number;
	vector<int> arr;
	set<int> result;
	arr.push_back(0);
	arr.push_back(w);
	result.insert(w);
	for( int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		for(int j = 0; j < arr.size(); j++)
		{
			result.insert(abs(number - arr[j]));
		}
		arr.push_back(number);
	}

	for( set<int>::iterator it = result.begin(); it != result.end(); it++)
	{
		printf("%d ", *it);
	}
	printf("\n");

}