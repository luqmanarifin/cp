#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 100005;

int bit[N];

void add(int i) {
	for(; i < N; i |= i + 1) bit[i]++;
}

int find(int i) {
	int temp = 0;
	for(; i >= 0; i = (i & (i + 1)) - 1) temp += bit[i];
	return temp;
}

int a[N];

int main(void)
{
	int t, i, j, x, m, n;
	sf("%d", &t);
	while(t--) {
		reset(bit, 0);
		sf("%d %d %d", &n, &m, &x);
		FORS(i, n) {
			sf("%d", &a[i]);
			add(a[i] % m);
		}
		LL ans = 0;
		FORS(i, n) {
			int l, r;
			l = m - (a[i] % m);
			r = m + x - (a[i] % m);
			l %= m;
			r %= m;
			if(l < r) ans += find(r) - find(l - 1);
			else ans += find(m - 1) - find(l - 1) + find(r);
		}
		pf("%lld\n", ans);
	}
	
	return 0;
}
