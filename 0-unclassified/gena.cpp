#include <bits/stdc++.h>

using namespace std;

const long long inf = 4e18;

int x[105], k[105], mask[105];
long long dp[(1 << 20)+5];

int main(void)
{
	int n, m, b, i, j, can, num;
	scanf("%d %d %d", &n, &m, &b);
	for(i = 0; i < n; ++i) {
		scanf("%d %d %d", &x[i], &k[i], &can);
		mask[i] = 0;
		while(can--) {
			scanf("%d", &num);
			mask[i] |= (1 << (num - 1));
		}
	}
	for(i = 0; i < n; ++i)
		for(j = i + 1; j < n; ++j)
			if(k[i] > k[j]) {
				swap(x[i], x[j]);
				swap(k[i], k[j]);
				swap(mask[i], mask[j]);
			}
	
	for(i = 0; i < (1 << m); ++i)
		dp[i] = inf;
		
	long long ans = inf;
	
	dp[0] = 0;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < (1 << m); ++j)
			if(dp[j] + x[i] < dp[j | mask[i]])
				dp[j | mask[i]] = dp[j] + x[i];
		long long now = dp[(1 << m) - 1];
		now += (long long) b * k[i];
		if(now < ans) ans = now;
	}
	cout << ((ans == inf)? -1 : ans) << endl;
	
	return 0;
}