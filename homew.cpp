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

const LL mod = 1e9;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 2e5 + 20;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];
LL fib[N];

inline long long get(int id, long long so, long long si) {
	if(id == 0) return so;
	if(id == 1) return si;
	return (fib[id-2]*so + fib[id-1]*si) % mod;
}

struct Segtree {
public:
	Segtree(int _n) : n(_n) {
		so.resize(4*n);
		si.resize(4*n);
		temp.resize(4*n);
		_build(1, 1, n);
	};
	void update(int at, int val) {
		_update(1, 1, n, at, val);
	}
	void add(int l, int r, int val) {
		_add(1, 1, n, l, r, val);
	}
	long long find(int l, int r) {
		return _find(1, 1, n, l, r, l);
	}
private:
	inline void _gather(int p, int l, int r) {
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		so[p] = so[lef] + get(mid+1-l, so[rig], si[rig]);
		si[p] = si[lef] + get(mid+2-l, so[rig], si[rig]);
		if(so[p] >= mod) so[p] -= mod;
		if(si[p] >= mod) si[p] -= mod;
	}
	inline void _lazy(int p, int l, int r) {
		if(temp[p]) {
			int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
			so[p] += temp[p]*(fib[r-l+2] - 1);
			si[p] += temp[p]*(fib[r-l+3] - 2);
			so[p] %= mod;
			si[p] %= mod;
			if(so[p] < 0) so[p] += mod;
			if(si[p] < 0) si[p] += mod;
			if(lef < 4*n) {
				temp[lef] += temp[p];
				temp[lef] %= mod;
			}
			if(rig < 4*n) {
				temp[rig] += temp[p];
				temp[rig] %= mod;
			}
			temp[p] = 0;
		}
	}
	inline void _build(int p, int l, int r) {
		temp[p] = 0;
		if(l == r) {
			so[p] = a[l];
			si[p] = a[l];
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		_build(lef, l, mid);
		_build(rig, mid+1, r);
		_gather(p, l, r);
	}
	inline void _update(int p, int l, int r, int at, int v) {
		_lazy(p, l, r);
		if(r < at || at < l) return;
		if(l == r) {
			so[p] = v;
			si[p] = v;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		_update(lef, l, mid, at, v);
		_update(rig, mid+1, r, at, v);
		_gather(p, l, r);
	}
	inline void _add(int p, int l, int r, int ll, int rr, int v) {
		if(l == ll && r == rr) {
			temp[p] += v;
			if(temp[p] >= mod) temp[p] -= mod;
		}
		_lazy(p, l, r);
		if(r < ll || rr < l) return;
		if(l == ll && r == rr) return;
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		_add(lef, l, mid, ll, min(rr, mid), v);
		_add(rig, mid+1, r, max(mid+1, ll), rr, v);
		_gather(p, l, r);
	}
	inline long long _find(int p, int l, int r, int ll, int rr, int id) {
		_lazy(p, l, r);
		if(r < ll || rr < l)
			return 0;
		if(l == ll && r == rr) {
			return get(l - id, so[p], si[p]);
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		long long ret = 0;
		ret += _find(lef, l, mid, ll, min(rr, mid), id);
		ret += _find(rig, mid+1, r, max(mid+1, ll), rr, id);
		if(ret >= mod) ret -= mod;
		_gather(p, l, r);
		return ret;
	}
	long long n;
	vector<long long> so, si, temp;
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
		int t, l, r, v;
		sf("%d %d %d", &t, &l, &r);
		if(t == 1) seg.update(l, r);
		if(t == 2) pf("%d\n", (int) seg.find(l, r));
		if(t == 3) {
			sf("%d", &v);
			seg.add(l, r, v);
		}
	}
	return 0;
}
