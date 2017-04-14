#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int num_stone, allow_pick, pick;
	while ( cin >> num_stone)
	{
		cin >> allow_pick;
		int arrayPick[allow_pick+1];
		int arrayGame[num_stone+5];
		for (int i = 0; i <= num_stone; i++)
		{
			arrayGame[i] = 0;
		}
		for (int i = 0; i < allow_pick; i++)
		{
			cin >> pick;
			arrayPick[i] = pick;
		}
		for (int i = 1 ; i <= num_stone; i++)
		{
			for( int j = 0; j < allow_pick; j++)
			{
				if ( i >= arrayPick[j] && !arrayGame[i - arrayPick[j]])
				{
					arrayGame[i] = 1;
					break;
				}
			}
		}
		if ( arrayGame[num_stone] == 1)
		{
			printf("Stan wins\n");
		} else {
			printf("Ollie wins\n");
		}
	}

}