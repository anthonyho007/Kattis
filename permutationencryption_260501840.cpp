#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	int num;
	int count = 0;
	while (cin >> num)
	{
		if (num == 0){
			break;
		}

		vector<int> sequence;
		for (int i = 0; i < num; i++){
			int n;
			cin >> n;
			sequence.push_back(n -1);
		}
		cin.ignore();
		string message;
		getline(cin, message);
		cout << message << '\n';
		int remaining = 0;
		if ( message.size() % num )
		    remaining = num - (message.size() % num);
		int total = remaining + message.size();
		for (int j = 0; j < remaining; j++){
			message	+= ' ';
		}
		string final(total , ' ' );
		int interval = count * num;
		for (int x = 0; x < total; x++)
		{
			int target = sequence[x - interval];
			char character = message[target + interval];
			final[x] = character;
			count += 1;
		}

		cout << '\'' << final << '\'' << '\n';
		 
	}
}