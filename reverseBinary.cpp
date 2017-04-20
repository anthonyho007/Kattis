#include <iostream>


using namespace std;
int main ()
{
	int num;
	int ans = 0;
	cin >> num;
	while ( num > 0)
	{
		ans = ans << 1;
		ans = ans | (num & 1);
		num = num >> 1;
	}
	cout << ans << endl;
}