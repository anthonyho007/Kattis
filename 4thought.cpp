#include <iostream>
#include <string.h>
using namespace std;
int result[256];

bool n_expr (const char *&s, int &result);
bool p_expr (const char *&s, int &result);
bool o_expr (const char *&s, int &result, int eos);


bool expr (const char *&s, int &result, int eos = 0) {
    while (isspace(*s)) ++s;
    if (*s == eos) return false;
    if (isdigit(*s)) {
        if (!n_expr(s, result)) return false;
    } else if (*s == '(') {
        if (!p_expr(s, result)) return false;
    } else return false;
    while (isspace(*s)) ++s;
    if (*s == eos) return true;
    return o_expr(s, result, eos);
}

bool n_expr (const char *&s, int &result) {
    int n = 0;
    while (isdigit(*s)) n = 10 * n + (*s++ - '0');
    result = n;
    return true;
}

bool p_expr (const char *&s, int &result) {
    if (expr(++s, result, ')')) {
        ++s;
        return true;
    }
    return false;
}

bool o_expr (const char *&s, int &result, int eos) {
    int oresult = 0;
    const char *op = strchr("+-*/", *s);
    if (op == 0) return false;
    if (!expr(++s, oresult, eos)) return false;
    switch (*op) {
    case '+': result += oresult; break;
    case '-': result -= oresult; break;
    case '*': result *= oresult; break;
    case '/': result /= oresult; break;
    default: return false;
    }
    return true;
}


void compute ()
{
	char expression[7];
	int number;
	expression[0] = '4';
	expression[2] = '4';
	expression[4] = '4';
	expression[6] = '4';
	for (int i = 3; i >= 0; i--)
	{
		if (i == 0)
		{
			expression[1] = '+';
		} else if (i ==1)
		{
			expression[1] = '-';
		} else if ( i == 2)
		{
			expression[1] = '*';
		} else {
			expression[1] = '/';
		}
		for (int j= 3; j >=0; j--)
		{

			if (j == 0)
			{
				expression[3] = '+';
			} else if (j ==1)
			{
				expression[3] =  '-';
			} else if ( j == 2)
			{
				expression[3] =  '*';
			} else {
				expression[3] = '/';
			}

			for (int x= 3; x >= 0; x--)
			{
				if (x == 0)
				{
					expression[5] = '*';
				} else if (x ==1)
				{
					expression[5] = '-';
				} else if ( x == 2)
				{
					expression[5] = '*';
				} else {
					expression[5] = '/';
				}
				expr(expression, number);
				result[number] = 1;

			}
		}
	}
}

int main ()
{
	for (int i = 0; i < 256; i++)
	{
		result[i] = 0;
	}
	compute();


}