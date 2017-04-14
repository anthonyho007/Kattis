#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
//#include <cfloat>
using namespace std;

// struct for calls
struct Call
{
	int start;
	int end;
};

int main ()
{
	int N, M, source, dest;
	int first, last;
	int start, duration, end, count, begin, final;
	struct Call calls[100007];
	scanf("%d %d", &N, &M);
	while (N != 0 || M != 0)
	{
		// count the number of calls in each interval
		for (int i = 0; i < N; i ++)
		{
			scanf("%d %d %d %d", &source, &dest, &start, &duration);
			end = start + duration;
			calls[i].start = start;
			calls[i].end = end;
		}

		//search for the maximum # of call in each interval
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d", &begin, &final);
			count = 0;
			end = final + begin;
			for (int j = 0; j < N; j++)
			{
				first = calls[j].start;
				last = calls[j].end;
				if ( max(first, begin) < min(last, end))
				{
					count+= 1;
				}
			}

			printf("%d\n", count);
		}
		scanf("%d %d", &N, &M);
		//delete[] calls;
	}

}