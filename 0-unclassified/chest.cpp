#include <bits/stdc++.h>

/**
 * Codeforces Round #259 (Div. 1)
 * Problem : B
 * Luqman Arifin (kadalbonek)
 */

using namespace std;

const int inf = 2e9;
const int big = (1 << 16);

vector<int> prime;
bool is[105];
int dp[105][big+5], to[105][big+5], be[105][big+5];
int a[105], b[105], fact[105], n;

int main(void)
{
	int i, j, k;
	memset(is, 1, sizeof(is));
	is[0] = is[1] = 0;
	for(i = 2; i < 60; i++) {
		if(is[i]) {
			prime.push_back(i);
			if(i*i < 60)
			for(j = i*i; j < 60; j += i)
				is[j] = 0;
		}
	}
	for(i = 1; i < 60; i++)
		for(j = 0; j < prime.size(); j++)
			if(i % prime[j] == 0)
				fact[i] |= (1 << j);
				
	scanf("%d", &n);
	for(i = 0; i <= n; i++)
		for(j = 0; j < big; j++)
			dp[i][j] = inf;
	
	dp[0][0] = 0;
	int ans = inf, pos = -1;
	for(i = 1; i <= n; i++) {
		scanf("%d", a + i);
		for(j = 1; j < 59; j++) {
			int belum = (~fact[j] & (big - 1));
			for(k = belum; ; k = ((k - 1) & belum)) {
				if(dp[i][k | fact[j]] >= dp[i - 1][k] + abs(a[i] - j)) {
					dp[i][k | fact[j]] = dp[i - 1][k] + abs(a[i] - j);
					to[i][k | fact[j]] = k;
					be[i][k | fact[j]] = j;
					if(dp[i][k | fact[j]] <= ans && i == n) {
						ans = dp[i][k | fact[j]];
						pos = (k | fact[j]);
					}
				}
				if(k == 0) break;
			}
		}
	}
	for(i = n; i ; pos = to[i--][pos]) {
		b[i] = be[i][pos];
	}
	for(i = 1; i <= n; i++) printf("%d ", b[i]);
	puts(""); return 0;
}
