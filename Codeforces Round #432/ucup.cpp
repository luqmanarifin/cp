#include<bits/stdc++.h>
using namespace std;

#define LL long long

const int MAXN = 1e6 + 5;

LL n, a[MAXN], x, y;
LL counter[MAXN], p[MAXN];
LL counter2[MAXN];

bool bol[MAXN];

int main() {
	scanf("%lld %lld %lld",&n, &x, &y);
	for(int i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
		p[a[i]] += 1;
	}

	memset(bol, true, sizeof bol);
	
	for(int i = 2; i < MAXN; i++) if (bol[i]) {
		counter[i] = p[i];
		counter2[i] = p[i-1];
		for(int j = i + i; j < MAXN; j += i) {
			bol[j] = false;
			counter[i] += p[j];
			counter2[i] += p[j-1];
		}
	}

	LL ans = 1e18;
	for(int i = 2; i < MAXN; i++) ans = min(ans, (n - counter[i])*x);

	for(int i = 2; i < MAXN; i++) {
		if (counter2[i] > 0) {
			LL k = counter2[i];

			ans = min(ans, k*y + (n - counter[i] - k)*x);
		}
	}	

	printf("%lld\n",ans);
}