#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main ()
{
	int B, F;
	double s, e, m, result, maxP, p;
	scanf("%d", &B);
	double taxBand[B][2];
	int index = -1;
	for(int i = 0; i < B; i++)
	{
		scanf("%lf %lf", &s, &p);
		taxBand[i][0] = s;
		taxBand[i][1] =(double) p/100;
	}
	scanf("%lf", &maxP);
	maxP =(double) maxP / 100;
	scanf("%d", &F);

	for(int i = 0; i < F; i++)
	{
		scanf("%lf %lf", &e, &m);
		double current = e;
		double tax = 0; 
		for(int j = 0; j < B; j++)
		{
			if ( (current = current - taxBand[j][0]) <= 0)
			{
				if ( current + (m /(1-taxBand[j][1])) < 0)
				{
					tax =(double) tax + m /(1-taxBand[j][1]);
					m = 0;
					break;
				}
				else {
					tax = (double) tax - current;
					m =(double) m - current*taxBand[j][1] + current;
					current = 0;
				}
			}
		}
		if ( m > 0)
		{
			tax = tax + (double)m /(1- maxP);
		}
		printf("%.6lf\n", tax);
	}
	return 0;
}