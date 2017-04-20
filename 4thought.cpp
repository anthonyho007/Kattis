#include <iostream>
#include <string>
#include <vector>
#include <map>

#define MUL 0
#define DIV 1
#define ADD 2
#define SUB 3

using namespace std;

map<int, string> results;
char math_ops[4] = {'*', '/', '+', '-'};

int evaluate ( int a, int b , int op)
{
	if ( op == MUL	)
	{
		return a * b;

	} else if ( op == DIV)
	{
		return a / b;

	} else if ( op == ADD)
	{
		return	a + b;

	} else if ( op == SUB) {

		return a -b;
	}

	return -1;
}

void compute4s()
{
	for(int i = 0 ; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int k =0; k < 4; k++)
			{
				vector<int> numbers;
				for (int x  = 0; x < 4; ++x)
				{
					numbers.push_back(4);
				}
				vector<int> ops;
				ops.push_back(i);
				ops.push_back(j);
				ops.push_back(k);
				for( int x = 0; x < ops.size(); ++x)
				{
					if ( ops[x] == MUL	|| 	ops[x] == DIV)
					{
						numbers[x] = evaluate(numbers[x], numbers[x+1], ops[x]);
						numbers.erase(numbers.begin()+x+1);
						ops.erase(ops.begin() + x);
						--x;
					}
				}

				for( int x = 0; x < ops.size(); x++)
				{
					if ( ops[x] == ADD	|| 	ops[x] == SUB)
					{
						numbers[x] = evaluate(numbers[x], numbers[x+1], ops[x]);
						numbers.erase(numbers.begin() + x + 1);
						ops.erase(ops.begin() + x);
						--x;
					}
				}
				results[numbers[0]] = "4 " + string(1, math_ops[i]) + " 4 " + string(1, math_ops[j]) + " 4 " + string(1, math_ops[k]) + " 4 = " + to_string(numbers[0]);

			}
		}
	}
}

int main ()
{
	compute4s();
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		map<int, string>::iterator pos;
		pos = results.find(num);
		if ( pos != results.end())
		{
			cout << results[num] << endl;
		} else {
			cout << "no solution" << endl;
		}
	}
	return 0;
}







