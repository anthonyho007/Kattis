#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
	int n, index, p, q;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d/%d", &index, &p, &q);
		vector<int> pos;
		while (p != q)
		{
			if (p > q)
			{
				p = p -q;
				pos.push_back(1);
			}else {
				pos.push_back(0);
				q = q -p;
			}
		}
		int init = 1;
		int curr;
		while ( !pos.empty())
		{
			curr = pos.back();
			pos.pop_back();
			if ( curr == 0)
			{
				init = init *2;
			} else {
				init = init	*2 + 1;
			}
		}
		printf("%d %d\n", index, init);
	}
}