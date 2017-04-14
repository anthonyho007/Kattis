#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main ()
{
	unsigned long long N, T, A, B, C, t;
	scanf("%llu %llu", &N, &T);
	unsigned long long timeSpent[N];
	scanf("%llu %llu %llu %llu", &A, &B, &C, &t);
	timeSpent[0] = t;
	for (int i = 1; i < N; i++)
	{
		timeSpent[i] = (A*t+B)%C + 1;
		t = timeSpent[i];
	}
	sort(timeSpent, timeSpent+N);
	unsigned long long penalty = 0;
	unsigned long long minutes = 0;
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		if (minutes + timeSpent[i] > T){
			break;
		}
		penalty = (penalty + timeSpent[i] + minutes) % 1000000007;
		minutes += timeSpent[i];
		counter++;
	}
	printf("%d %llu\n", counter, penalty);
}