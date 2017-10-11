#include <iostream>

using namespace std;

int grid[31][31];

int main ()
{
	for(int i = 0; i < 31; i++)
	{
		grid[0][i] = 0;
		grid[i][0] = 1;
	}

	for(int i = 1; i < 31; i++)
	{
		for(int j = 1; j < 31; j++)
		{
			grid[i][j] = grid[i-1][j] + grid[i-1][j-1];
		}
	}

	int num, n, m;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", grid[n][m-1]);
	}
	return 0;

}