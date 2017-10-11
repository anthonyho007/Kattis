#include <iostream>

using namespace std;

int main()
{
	int num, limit, number;
	scanf("%d %d", &num	, &limit);
	int count = 0;
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &number);
		sum += number;
		if ( sum > limit)
		{
			break;
		} else {
			count++;
		}

	}
	printf("%d\n", count);
	return 0;
}