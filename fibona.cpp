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

const LL mod = 1e9 + 9;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 3e5 + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL fib[N], a[N];

LL sum(int l, int r) {
	LL cur = fib[r + 2] - fib[l + 1];
	if(cur < 0) cur += mod;
	return cur;
}

struct Segtree {
public:
	Segtree (int _n) : n(_n) {
		at.resize(4*n);
		temp.resize(4*n);
		_build(1, 1, n);
	};
	void add(int l, int r) {
		_add(1, 1, n, l, r, l);
	}
	long long find(int l, int r) {
		return _find(1, 1, n, l, r);
	}
private:
	void _build(int p, int l, int r) {
		if(l == r) {
			at[p] = a[l];
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		_build(lef, l, mid);
		_build(rig, mid+1, r);
		_gather(p, l, r);
	}
	void _gather(int p, int l, int r) {
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		at[p] = at[lef] + at[rig];
		if(at[p] >= mod) at[p] -= mod;
	}
	void _relax(int p, int l, int r) {
		if(!temp[p].empty()) {
			int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1, i;
			FORS(i, temp[p].size()) {
				int now = temp[p][i];
				at[p] += sum(now, now + r - l);
				if(at[p] >= mod) at[p] -= mod;
				if(l < r) temp[lef].push_back(now);
				if(l < r) temp[rig].push_back(now + mid + 1 - l);
			}
			temp[p].clear();
		}
	}
	void _add(int p, int l, int r, int ll, int rr, int id) {
		if(l == ll && r == rr) {
			temp[p].push_back(l - id);
		}
		_relax(p, l, r);
		if(r < ll || rr < l) return;
		if(l == ll && r == rr) return;
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		_add(lef, l, mid, ll, min(mid, rr), id);
		_add(rig, mid+1, r, max(mid+1, ll), rr, id);
		_gather(p, l, r);
	}
	long long _find(int p, int l, int r, int ll, int rr) {
		_relax(p, l, r);
		if(r < ll || rr < l) return 0;
		if(l == ll && r == rr) {
			return at[p];
		}
		LL ret = 0;
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		ret += _find(lef, l, mid, ll, min(mid, rr));
		ret += _find(rig, mid+1, r, max(mid+1, ll), rr);
		if(ret >= mod) ret -= mod;
		return ret;
	}
	int n;
	vector<long long> at;
	vector<vector<long long> > temp;
};

int main(void)
{
	int i, j, n, m;
	fib[0] = fib[1] = 1;
	FOR(i, 2, N-1) {
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] >= mod) fib[i] -= mod;
	}
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%d", a + i);
	
	Segtree seg(n);
	while(m--) {
		int type, l, r;
		sf("%d %d %d", &type, &l, &r);
		if(type == 1) seg.add(l, r);
		else pf("%d\n", (int) seg.find(l, r));
	}
	return 0;
}
