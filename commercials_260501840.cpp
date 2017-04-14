#include <stdio.h>

int main ()
{
	int num_breaks;
	int price;
	int num;
	scanf("%d %d", &num_breaks, &price);
	int max = 0;
	int curr = 0;
	for (int i = 0; i < num_breaks; i++)
	{
		scanf("%d", &num);
		curr = num - price + curr;
		if ( curr < 0)
			curr = 0;
		if ( curr > max)
			max = curr;
	}
	printf("%d", max);
}