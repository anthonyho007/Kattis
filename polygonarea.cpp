#include <iostream>
#include <cmath>
using namespace std;
int array1[1000][2];
int main () 
{
	int num_edge, x_cor, y_cor;
	cin >> num_edge;
	while ( num_edge != 0)
	{
		for (int i = 0; i < num_edge; i++)
		{
			cin >> x_cor;
			cin >> y_cor;
			array1[i][0] = x_cor;
			array1[i][1] = y_cor;
		}
		long double area = 0.0;
		long double left;
		long double right;
		for ( int i = 0; i < num_edge -1; i++)
		{
			left = array1[i][0]*array1[i+1][1];
			right = array1[i+1][0]*array1[i][1];
			area = area + left -right;
		}
		area = area + array1[num_edge -1][0]* array1[0][1] - array1[0][0]*array1[num_edge-1][1];
		area = area * 0.5;
		if ( area < 0)
		{
			cout << "CW";
		} else {
			cout << "CCW";
		}
		long double area_new = abs (area);
		printf(" %.1LF\n", area_new);
		cin >> num_edge;
	}
}