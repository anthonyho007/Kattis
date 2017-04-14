#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int prime(int number)
{
	if (number == 2)
	{
		return 1;
	} else if ( number == 3)
	{
		return 1;
	}else if ( number % 2 == 0)
	{
		return 0;
	} else if ( number % 3 == 0)
	{
		return 0;
	}

	// using interval for 2 4 
	int i = 5;
	int j = 2;
	while ( i * i <= number)
	{
		if ( number % i == 0)
		{
			return 0;
		}
		i += j;
		j = 6 -j;
	}
	return 1;
}


void primeSum(int number)
{
	int counter = 0;
	vector<pair<int,int> > answers;
	for ( int i = 2; i <= number/2; i++)
	{
		if ( prime(i) == 1 && prime(number -i) == 1)
		{
			counter++;
			pair<int, int> p( i, number-i);
			answers.push_back(p);
		}
	}
	printf("%d has %d representation(s)\n",number, counter);

	for(int i = 0; i < counter; i++)
	{
		printf("%d+%d\n", answers[i].first, answers[i].second);
	}
	printf("\n");
}

int main()
{
	int n;
	cin >> n;
	int number;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		primeSum(number);
	}
}