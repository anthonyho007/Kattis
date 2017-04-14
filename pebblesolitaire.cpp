#include <iostream>
#include <string>

int main ()
{
	string word;
	cin >> word;
	while (s[0]!= '.')
	{
		int length = word.length();
		int flag = 0;
		int i;
		for (i = 1; i < length -1; i++)
		{
			if ( length %i != 0)
			{
				// skip
			} else {
				for ( int j = i; j < length; j++)
				{
					if ( word[j%i]!= word[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					break;
				} else {
					flag = 0;
				}
			}
		}
		if ( flag )
		{
			printf("%d\n", length);
		} else {
			printf("%d\n", length/i);
		}

	}

}