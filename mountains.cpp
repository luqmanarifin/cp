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
const int N = 1e5 + 5;

int h[N], num[N << 2];

void build(int p, int l, int r) {
	if(l == r) {
		num[p] = h[l];
		return;
	}
	int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
	build(lef, l, mid);
	build(rig, mid+1, r);
	num[p] = max(num[lef], num[rig]);
}

int find(int p, int l, int r, int ll, int rr) {
	//pf("%d %d %d %d %d\n", p, l, r, ll, rr);
	if(ll > rr || rr < l || r < ll) return -1;
	if(l == ll && r == rr) return num[p];
	int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
	int ret = -1;
	ret = max(ret, find(lef, l, mid, ll, min(mid, rr)));
	ret = max(ret, find(rig, mid+1, r, max(mid+1, ll), rr));
	return ret;
}

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	FOR(i, 1, n) sf("%d", &h[i]);
	build(1, 1, n);
	int q;
	sf("%d", &q);
	while(q--) {
		int a, b;
		sf("%d %d", &a, &b);
		puts(find(1, 1, n, a + 1, b - 1) > h[a]? "NO" : "YES");
	}
	
	return 0;
}
