#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;
int main () 
{
	int height;
	string c;
	scanf("%d", &height);
	//int root = pow(2, height) -1;
	int pos = 1;
	cin >> c;
	if ( c[0] != 'L' && c[0] != 'R')
	{
		int final = pow(2, height +1) -1;
		printf("%d\n", final);
		return 0;
	}
	int count = c.length();
	//cout << c << count << endl;
	//char *g = "L";
	for (int i = 0; i < count ; i++)
	{
		pos = pos *2;
		//cout << c[i].compare('L');
		if (c[i] == 'L')
		{
			pos = pos;
		} else 
		{
			pos = pos + 1;
		}
		//printf("%d\n", pos);
	}
	//printf("%d\n", pos);
	int final = pow(2, height +1) -pos;
	printf("%d\n", final);

}