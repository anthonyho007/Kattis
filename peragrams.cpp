#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
	string word;
	unordered_map<char,int> character_map;
	int counter = 0;
	cin >> word;
	int size = word.size();
	for (int i = 0; i < size; i++){
	    if (character_map[word[i]]){
			if ( character_map[word[i]] % 2 == 0){
				counter += 1;
			} else {
				counter -= 1;
			}
			character_map[word[i]] += 1;
		} else {
			character_map[word[i]] = 1;
			counter += 1;
		}
	}
	if (counter <= 1){
		cout << 0;
	} else {
		cout << counter - 1;
	}
}