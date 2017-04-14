#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

void scan (int n1, int n2, double cut)
{
	int flagx = 1;
	int flagy = 1;
	double length[n1];

	for (int i = 0; i < n1; i++)
	{
		cin >> length[i];
	}
	sort(length, length + n1);
	for (int i = 1; i <= n1; i++)
	{
		if (length[i] -length[i-1] > cut)
		{
			flagx = 0;
			break;
		}
	}


	double width[n2];
	for (int i = 0; i < n2; i++)
	{
		cin >> width[i];
	}
	sort(width, width+n2);
	for (int i = 1; i <=n2; i++)
	{
		if (width[i] -width[i-1] > cut)
		{
			flagy = 0;
			break;
		}
	}
	int flag = 1;
	//double x1, x2, y1, y2;

	if ( (length[0] - cut/2) > 0  || (75 -length[n1 -1]) > (cut/2) )
	{
			flag = 0;
	}
	if ((width[0] -cut/2) > 0 || (100 -width[n2 -1] > cut/2))
	{
		flag = 0;
	}

	if (flagx == 1 && flagy == 1 && flag == 1)
	{
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main()
{
	int n1, n2;
	double cut;
	cin >> n1 >> n2 >> cut;
	while ( n1 != 0 && n2 != 0 && cut != 0)
	{
		scan(n1, n2, cut);
		cin >> n1 >> n2 >> cut;
	}

	return 0;
}