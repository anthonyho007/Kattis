#include <iostream>
#include <algorithm>
using namespace std;

struct Index
{
	int value;
	int ind;
};
typedef struct Index Index;

bool compareBy(const Index &a, const Index &b)
{
	if (a.value < b.value)
		return 1;
	return 0;
}

int main ()
{
	int n, number;
	scanf("%d", &n);
	Index array[n];
	int array_original[n];
	int vis[n];
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
		scanf("%d", &number);
		array[i].value = number;
		array[i].ind = i;
		array_original[i] = number;
	}
	sort(array, array+n, compareBy);
	int result =0;
	for (int i = 0; i < n; i++)
	{

		if (vis[i] || array[i].ind == i)
		{
			continue;
		}
		int counter = 0;
		int curr = i;
		while (!vis[curr])
		{
			vis[curr] = 1;
			curr = array[curr].ind;
			counter++;
		}

		result += counter -1;
	}
	printf("%d\n", result);

}