#include <iostream>
#include <cmath>
using namespace std;

int fact(int n) {
	int factorial = 1;
	for(int i=1; i<=n; i++) {
		factorial = factorial*i;
	}
	return factorial;
}

int permutations(int n, int r) {
	return fact(n)/(fact(n-r)*fact(r));
}

int main() {
	int n, m, cases = 0;

	while(scanf("%d", &n) != EOF) {
		cases++;
		long long inputs[1000];
		long long possibilities[permutations(n,2)];

		for(int i=0; i<n; i++) {
			scanf("%lld", &inputs[i]);
		}
		
		int indexp=0;
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				possibilities[indexp] = inputs[i]+inputs[j];
				indexp++;
			}
		}

		printf("Case %d:\n", cases);
		scanf("%d", &m);

		for(int i=0; i<m; i++) {
			long long query, sum, max = 1000000;
			scanf("%lld", &query);
			for(int j=0; j<indexp; j++) {
				if(max > abs(possibilities[j] - query)) {
					max = abs(possibilities[j] - query);
					sum = possibilities[j];
				}
			}
			printf("Closest sum to %lld is %lld.\n", query, sum);
		}
	}
	return 0;
}