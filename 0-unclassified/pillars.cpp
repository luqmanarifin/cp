#include <bits/stdc++.h>

/** 
 * Codeforces Round #271 (Div. 2)
 * Problem : E
 * بسم الله الرحمان الرحيم
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<LL, int> a[N];
LL h[N];
int seq[N], prev[N], inSegtree[N];

struct segtree {
public:
	segtree(int _n) : n(_n) {
		num.resize(n << 2);
		pos.resize(n << 2);
		build(1, 1, n);
	};
	void ganti(int x, int val) {
		update(1, 1, n, x, val);
	}
	pair<int,int> cari(int l, int r) {
		if(r == 0 || l == n + 1) return mp(0, 0);
		return find(1, 1, n, l, r);
	}
private:
	void build(int p, int l, int r) {
		if(l == r) {
			num[p] = 0;
			pos[p] = a[l].second;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		build(lef, l, mid);
		build(rig, mid+1, r);
		if(num[lef] > num[rig])
			num[p] = num[lef], pos[p] = pos[lef];
		else
			num[p] = num[rig], pos[p] = pos[rig];
	}
	void update(int p, int l, int r, int x, int val) {
		if(l == r) {
			num[p] = val;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		if(mid < x) update(rig, mid+1, r, x, val);
		else update(lef, l, mid, x, val);
		if(num[lef] > num[rig])
			num[p] = num[lef], pos[p] = pos[lef];
		else
			num[p] = num[rig], pos[p] = pos[rig];
	}
	pair<int,int> find(int p, int l, int r, int ll, int rr) {
		if(l == ll && r == rr) {
			return mp(num[p], pos[p]);
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		pair<int,int> ret = mp(0, 0);
		if(ll <= mid) ret = max(ret, find(lef, l, mid, ll, min(mid, rr)));
		if(mid < rr) ret = max(ret, find(rig, mid+1, r, max(mid+1, ll), rr));
		return ret;
	}
	int n;
	vector<int> num, pos;
};

void print(int now) {
	if(now == 0) return;
	print(prev[now]);
	pf("%d ", now);
}

int main(void)
{
	int i, j, n, d;
	sf("%d %d", &n, &d);
	FOR(i, 1, n) {
		sf("%I64d", &h[i]);
		a[i] = mp(h[i], i);
	}
	sort(a + 1, a + 1 + n);
	segtree seg(n);
	FOR(i, 1, n) inSegtree[a[i].second] = i;
	
	FOR(i, 1, n) {
		int lower = lower_bound(a + 1, a + 1 + n, mp(h[i] - d, inf)) - a - 1;
		int upper = lower_bound(a + 1, a + 1 + n, mp(h[i] + d, 0)) - a;
		pair<int,int> cur = max(seg.cari(1, lower), seg.cari(upper, n));
		if(cur.first) prev[i] = cur.second;
		seq[i] = cur.first + 1;
		seg.ganti(inSegtree[i], cur.first + 1);
	}
	int ans = 0, start = 0;
	FOR(i, 1, n) {
		if(seq[i] > ans) {
			ans = seq[i];
			start = i;
		}
	}
	pf("%d\n", ans);
	print(start); nl;
	return 0;
}
