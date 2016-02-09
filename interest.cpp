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
		build(1, 1, n);
	};
	bool update(int l, int r, int val) {
		return chan(1, 1, n, l, r, val);
	}
	int cari(int l) {
		return find(1, 1, n, l);
	}
private:
	void build(int p, int l, int r) {
		if(l == r) {
			num[p] = 0;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		build(lef, l, mid);
		build(rig, mid+1, r);
		num[p] = 0;
	}
	bool chan(int p, int l, int r, int ll, int rr, int val) {
		if(l == ll && r == rr) {
			if(num[p]) return 1;
			num[p] = val;
			return 0;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		bool ret = 0;
		if(ll <= mid) ret = (ret || chan(lef, l, mid, ll, min(rr, mid), val));
		if(mid < rr) ret = (ret || chan(rig, mid+1, r, max(ll, mid+1), rr, val));
		return ret;
	}
	int find(int p, int l, int r, int pos) {
		if(l == r) {
			return num[p];
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		int son = 0;
		if(pos <= mid) son = find(lef, l, mid, pos);
		else son = find(rig, mid+1, r, pos);
		if(son == -1) return -1;
		if((~son & num[p] != 0) && son) return -1;
		return son | num[p];
	}	
	int n;
	vector<int> num;
};

int ans[N];

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	segtree seg(n);
	while(m--) {
		int l, r, val;
		sf("%d %d %d", &l, &r, &val);
		if(seg.update(l, r, val)) {
			puts("NO");
			return 0;
		}
	}
	FOR(i, 1, n) {
		ans[i] = seg.cari(i);
		if(ans[i] == -1) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	FOR(i, 1, n) pf("%d ", ans[i]); nl;
	
	return 0;
}
