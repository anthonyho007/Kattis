#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool stringCompare(string i, string j)
{

	if (i[0] < j[0]){
		return i[0] < j[0];
	}else if ( i[0] == j[0]){
		return i[1] < j[1];
	}
	return false;
}

void main(){
	int num;
	int count = 0;
	while (cin >> num)
	{
		if (count != 0){
			cout << "\n";
			count++;
		}
		if (num == 0)
			return ;
		vector<string> myStrings;
		vector<string>::iterator Iter;
		string chars;
		for (int i = 0; i < num; i++)
		{
			cin >> chars;
			myStrings.push_back(chars);
		}
		sort(myStrings.begin(), myStrings.end(), stringCompare);
		for (Iter = myStrings.begin(); Iter != myStrings.end(); ++Iter)
			cout << *Iter << '\n';
		cout << "\n";

	}

}
