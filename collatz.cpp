#include <iostream>
#include <vector>
using namespace std;

long long  collatz_num(long long x)
{
	if ( x %2 == 0)
	{
		return x /2 ;
	} else {
		return 3 *x + 1;
	}
}

void step_print(int numa, int numb, int step1, int step2, long long  ind)
{
	printf("%d needs %d steps, %d needs %d steps, they meet at %lld\n", numa, step1, numb, step2, ind);
}


int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	while( num1 != 0 && num2 != 0)
	{
		// main logic of the program

		// do the collaz for the first number
		long long collanum = (long long)num1;
		vector<long long> array1 ;
		array1.push_back(collanum);

		while ( collanum != 1)
		{
			collanum = collatz_num(collanum);
			array1.push_back(collanum);
		}
		
		long long collanum2 = (long long)num2;
		vector<long long> array2;
		array2.push_back(collanum2);
		while( collanum2 != 1)
		{
			collanum2 = collatz_num(collanum2);
			array2.push_back(collanum2);
		}

		int pos1 = array1.size() -1;
		int pos2 = array2.size() -1;
		while ( array1[pos1] == array2[pos2] && pos1 >= 0 && pos2 >= 0)
		{
			pos1--;
			pos2--;
		}
		pos2++;
		pos1++;
		step_print(num1, num2, pos1, pos2, array2[pos2]);

		scanf("%d %d", &num1, &num2);
	}
}