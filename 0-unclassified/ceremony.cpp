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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], last[N];

struct segtree {
public:
	segtree (int _n) : n(_n) {
		num.resize(n << 2);
		build(1, 1, n);
	};
	pair<int,int> cari(int l, int r) {
		return find(1, 1, n, l, r);
	}
private:
	void build(int p, int l, int r) {
		if(l == r) {
			num[p] = mp(a[l], l);
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		build(lef, l, mid);
		build(rig, mid+1, r);
		num[p] = min(num[lef], num[rig]);
	}
	pair<int,int> find(int p, int l, int r, int ll, int rr) {
		if(l == ll && r == rr) {
			return num[p];
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		pair<int,int> ret = mp(inf, inf);
		if(ll <= mid) ret = min(ret, find(lef, l, mid, ll, min(rr, mid)));
		if(mid < rr) ret = min(ret, find(rig, mid+1, r, max(ll, mid+1), rr));
		return ret;
	}
	int n;
	vector<pair<int,int> > num;
};

int solve(int l, int r, int h, segtree *seg) {
	if(r < l) return 0;
	int now = inf;
	if(last[l] == last[r]) {
		now = min(a[l] - h, r - l + 1);
	} else {
		pair<int,int> rmq = seg->cari(l, r);
		now = min(r - l + 1, rmq.first - h
		+ solve(l, rmq.second-1, rmq.first, seg)
		+ solve(rmq.second+1, r, rmq.first, seg));
	}
	pf("%d %d %d %d\n", l, r, h, now);
	return now;
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FOR(i, 1, n) {
		sf("%d", &a[i]);
		last[i] = i;
		if(a[i] == a[i-1]) last[i] = last[i-1];
	}
	segtree seg(n);
	cout << solve(1, n, 0, &seg) << endl;
	
	return 0;
}
