#include <iostream>
#include <stdio.h>

int main () 
{
	int h1, m1, s1, h2, m2, s2;
	scanf("%02d:%02d:%02d", &h1, &m1, &s1);
	scanf("%02d:%02d:%02d", &h2, &m2, &s2);

	// to calculate the time difference
	int carry1 = 0;
	int carry2 = 0;
	int h3, m3, s3;
	if ( s2 >= s1)
	{
		s3 = s2 - s1;
	} else {
		carry1 =1;
		//printf("%d %d\n", s2, s1);
		s3 = 60 + s2 -s1;
		//printf("%d\n", s3);
	}
	// if (s3 == 60)
	// {
	// 	s3 = 0;
	// }

	if ( m2 >= (m1 + carry1))
	{
		m3 = m2 - m1 - carry1;
	} else {
		carry2 = 1;
		m3 = 60 + m2 -m1 -carry1;
	}
	// if (s2 == 60)
	// {
	// 	s2 = 0;
	// }

	if ( h2 >= (h1+carry2))
	{
		h3 = h2 -h1 -carry2;
	} else {
		h3 = 24 + h2 -h1 -carry2;
	}

	// if (h3 == 24)
	// {
	// 	h3 = 0;
	// }
	if ( h3 == 0 && m3 == 0 && s3 == 0)
	{
		h3 = 24;
	}


	printf("%02d:%02d:%02d\n", h3, m3, s3);
}