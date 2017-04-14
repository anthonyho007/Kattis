#include <iostream>
#include <climits>

using namespace std;
int main () {
	long int num;
	int counter = 1;
	while (cin >> num)
	{
		long int min = LONG_MAX;
		long int max = LONG_MIN;
		for (int i = 0; i < num; i++){
			long int number;
			cin >> number;
			if (number > max){
				max = number;
			}
			if (number < min){
				min = number;
			}
		}
		int range = max - min;
		cout << "Case " << counter << ": " << min << " " << max << " " << range << '\n';
		counter +=1;

	}
}