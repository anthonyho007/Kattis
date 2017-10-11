#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
	int n, index, p, q, p1, q1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d/%d", &index, &p, &q);
		int p1, q1;
		if ( q == 1)
		{
			p1= 1;
			q1= p+1;
		} else if ( p < q)
		{
			p1 = q;
			q1 = q-p;
			
		} else {
			int diff = p/q;
			p = p%q;
			q = q-p;
			p = p+q;
			p1 = p;
			q1 = q + diff*p;
		}

		printf("%d %d/%d\n", index, p1, q1);
	}
}