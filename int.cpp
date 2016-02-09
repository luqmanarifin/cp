#include <bits/stdc++.h>

/**
 * Codeforces Round #275 (Div. 1)
 * Problem : B
 * Luqman Siswanto
 */

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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct segtree {
public:
	segtree(int _n) : n(_n) {
		num.resize(4 * n);
	};
	void update(int l, int r, int val) {
		chan(1, 1, n, l, r, val);
	}
	int cari(int l, int r) {
		return find(1, 1, n, l, r);
	}
private:
	void chan(int p, int l, int r, int ll, int rr, int val) {
		if(l == ll && r == rr) {
			num[p] |= val;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		if(ll <= mid) chan(lef, l, mid, ll, min(rr, mid), val);
		if(mid < rr) chan(rig, mid+1, r, max(ll, mid+1), rr, val);
	}
	int find(int p, int l, int r, int ll, int rr) {
		if(l == ll && r == rr) {
			return num[p];
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		int ret = -1;
		if(ll <= mid) ret = ret & find(lef, l, mid, ll, min(rr, mid));
		if(mid < rr) ret = ret & find(rig, mid+1, r, max(ll, mid+1), rr);
		return ret | num[p];
	}
	int n;
	vector<int> num;
};

int l[N], r[N], val[N];

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	segtree seg(n);
	FORS(i, m) {
		sf("%d %d %d", &l[i], &r[i], &val[i]);
		seg.update(l[i], r[i], val[i]);
	}
	FORS(i, m) {
		if(seg.cari(l[i], r[i]) != val[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	FOR(i, 1, n) pf("%d ", seg.cari(i, i)); nl;
	
	return 0;
}
