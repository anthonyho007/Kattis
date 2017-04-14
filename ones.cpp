#include <iostream>
using namespace std;

int main ()
{
	int num;
	while (cin >> num)
	{
		int counter = 1;
		int start = 1;
		while ( start % num	!= 0)
		{
			start = (start*10 + 1) %num;
			counter++;
		}
		printf("%d\n", counter);
	}
}