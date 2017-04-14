#include <bits/stdc++.h>

using namespace std;

int memo[100][300000], c[100], lastvisit[100][300000];
int n, m, ct, caseNum;

int dp(int idx, int s_left) {
	// printf("%d %d\n", idx, s_left);
	if (idx == n) return 0;
	if (s_left == 0) return 1;
	// if (memo[idx][s_left] != -1) return memo[idx][s_left];
	if (lastvisit[idx][s_left] == caseNum) return memo[idx][s_left];
	lastvisit[idx][s_left] = caseNum;

	// Dont choose
	memo[idx][s_left] = dp(idx+1, s_left);
	// Choose
	if (s_left - c[idx] >= 0) memo[idx][s_left] += dp(idx, s_left - c[idx]);
	if (memo[idx][s_left] > 1000) memo[idx][s_left] = 1000;
	return memo[idx][s_left];
}

void print(int idx, int s_left) {
	if (s_left <= 0 || idx == n) return;
	// printf("idx:%d s_left:%d dp:%d memo:%d \n", idx, s_left, dp(idx+1, s_left - c[idx]), memo[idx][s_left]);
	
	if (dp(idx+1, s_left) ==  1) {
		if (ct != 0) printf("%d ", idx+1);
		print(idx+1, s_left);
	}

	if (s_left - c[idx] >= 0) {
		if (dp(idx, s_left - c[idx]) == 1) {
			printf("%d ", idx+1);
			print(idx, s_left - c[idx]);
		}	
	}
	ct++;
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	scanf("%d\n", &m);
	memset(lastvisit, -1, sizeof(lastvisit));
	for (int i = 0; i < m; i++) {
		int in;
		scanf("%d", &in);
		// memset(memo, -1, sizeof(memo));
		int out = dp(0, in);
		if (out == 0)
			printf("Impossible\n");
		else if (out == 1) {
			ct = 0;
			print(0, in);
			printf("\n");
		}
		else
			printf("Ambiguous\n");
	}
}