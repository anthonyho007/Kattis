#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
	string num;
	cin >> num;
	int i;
	int end_p = num.size() -1;
	int max = num[end_p] -48;
	priority_queue<int> pq;
	pq.push(max);
	for ( i = (end_p -1); i >= 0; i--)
	{
		int target = num[i] - 48;
		if ( target < max){
			pq.push(target);
			break;
		}
		pq.push(target);
	}
	int temp = i++;
	for ( int j = i; j < num.size(); j++)
	{
		num[j] = to_string(pq.top());
		pq.pop();
	}
	num[temp] = to_string(pq.top())
	cout << num ;
}