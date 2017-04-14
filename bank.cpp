#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int N, T;
	scanf("%d %d", &N, &T);
	int c, t;

	priority_queue<int> array[47];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &c, &t);
		array[t].push(c);
	}
	int max, position;
	int sum = 0;
	int spot[T];
	for (int x = 0; x < T; x++)
	{
		spot[x] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		max = 0;
		position = 0;
		for ( int j = 0; j < 47; j++)
		{
			if (!array[j].empty() && max <array[j].top())
			{
				max = array[j].top();
				position = j;
			}
		}
		array[position].pop();
		while (position >= 0)
		{
			if (spot[position] == 0)
			{
				//cout << max << endl;
				sum += max;
				spot[position] = 1;
				position = 0;
			}
			position--;
		}
	}

	printf("%d\n", sum);
}