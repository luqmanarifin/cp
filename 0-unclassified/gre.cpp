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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL ans[N];
int lef[N], rig[N], v[N], a[N], op[N];

int main(void)
{
	int i, n, m, k;
	sf("%d %d %d", &n, &m, &k);
	FORS(i, n) sf("%d", a + i);
	FORS(i, m) {
		sf("%d %d %d", lef + i, rig + i, v + i);
		--lef[i]; --rig[i];
	}
	FORS(i, k) {
		int l, r;
		sf("%d %d", &l, &r);
		op[l-1]++; op[r]--;
	}
	FORS(i, m) {
		if(i) op[i] += op[i-1];
		ans[lef[i]] += 1LL*v[i]*op[i];
		ans[rig[i]+1] -= 1LL*v[i]*op[i];
	}
	FORS(i, n) {
		if(i) ans[i] += ans[i-1];
		pf("%I64d ", ans[i] + a[i]);
	}
	nl; return 0;
}
