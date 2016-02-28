#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int h[50005];

int main(void) {
	int t;
	sf("%d", &t);
	while(t--) {
		int n, m, i;
		sf("%d %d", &n, &m);
		FORS(i, n) sf("%d", h + i);
		sort(h, h + n);
		int ans1 = 1, cost1 = 0, cost2 = 0, ans2 = 1;
		FOR(i, 1, n - 1) {
			cost1 += abs(h[i] - h[i-1]);
			if(cost1 > m) break;
			else ans1++;
		}
		FORD(i, n - 2, 0) {
			cost2 += abs(h[i] - h[i+1]);
			if(cost2 > m) break;
			else ans2++;
		}
		pf("%d\n",  max(ans1, ans2));
	}
	return 0;
}
