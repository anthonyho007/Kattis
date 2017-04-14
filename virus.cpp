#include <iostream>
using namespace std;

int main()
{
	string string1;
	string string2;
	cin >> string1 >> string2;
	int countEnd1 = string1.length() -1;
	int countEnd2 = string2.length()-1;
	int size;
	if ( countEnd1 < countEnd2)
		size = countEnd1 + 1;
	else
		size = countEnd2 + 1;
	int start = -1;
	for (int i = 0; i < size; ++i)
	{
		if (string1[i] != string2[i]){
			start = i;
			break;
		}
	}
	if ( start == -1)
	{
		if (string1.length() >= string2.length()){
			cout << "0" << '\n';
			return 0;
		} else {
			cout << string2.length() - string1.length() << "\n";
			return 0;
		}
	}

	// while (string1[countFront] == string2[countFront] && countFront <= countEnd1 && countFront <= countEnd2)
	// {
	// 	countFront++;
	// }
	long int end;
	while (countEnd1 >= 0 && countEnd2 >= 0)
	{
		if (string1[countEnd1] != string2[countEnd2]){
			end = countEnd2;
			break;
		}
		countEnd1--;
		countEnd2--;
	}
	int diff = end - start + 1;
	if (countEnd2 < start)
		diff = 0;
	cout << diff << "\n";
	return 0;
}