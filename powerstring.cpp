#include <iostream>
#include <string>
using namespace std;
int main ()
{

	string word;
	while (cin >> word && word[0]!= '.')
	{
		int length = word.length();
		int flag = 0;
		int interval;
		for (interval = 1; interval < length -1; interval++)
		{
			if ( length %interval != 0)
			{

			} else {
				for ( int j = interval; j < length; j++)
				{
					if ( word[j%interval]!= word[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					flag = 0;
				} else {
					break;
				}
			}
		}
		if ( flag )
		{
			printf("%d\n", interval);
		} else {
			printf("%d\n", length/interval);
		}
		//cin >> word;

	}

}