#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")
#define vi vector<int>

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
const int big = (1 << 18) + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];

struct Segtree {
public:
	Segtree(int _n) : n(_n) {
		op.resize(4*n);
		_build(1, 0, n-1);
	};
	void update(int ll, int rr, int x) {
		_update(1, 0, n-1, ll, rr, x);
	}
	long long find(int ll, int rr) {
		vi cur = _find(1, 0, n-1, ll, rr);
		LL i, ret = 0LL;
		FORS(i, 41) ret += (1LL << i)*cur[i];
		return ret;
	}
private:
	void _build(int pos, int l, int r) {
		int i;
		if(l == r) {
			op[pos] = 0;
			reset(mask[pos], 0);
			FORS(i, 41) if((1LL << i) & a[l]) mask[pos][i]++;
			return;
		}
		int lef = pos << 1, rig = lef | 1, mid = (l + r) >> 1;
		_build(lef, l, mid);
		_build(rig, mid+1, r);
		
		reset(mask[pos], 0);
		FORS(i, 41) mask[pos][i] += mask[lef][i] + mask[rig][i]; 
		op[pos] = 0;
	}
	void _update(int pos, int l, int r, int ll, int rr, LL x) {
		int cnt = r - l  + 1, i;
		if(l == ll && r == rr) {
			FORS(i, 41)
				if((1LL << i) & x)
					mask[pos][i] = cnt - mask[pos][i];
			op[pos] ^= x;
			return;
		}
		int lef = pos << 1, rig = lef | 1, mid = (l + r) >> 1;
		if(ll <= mid) _update(lef, l, mid, ll, min(rr, mid), x);
		if(mid < rr) _update(rig, mid+1, r, max(mid+1, ll), rr, x);

		FORS(i, 41) {
			int cur = mask[lef][i] + mask[rig][i];
			mask[pos][i] = ((1LL << i) & op[pos]? cnt - cur : cur);
		}
	}
	vi _find(int pos, int l, int r, int ll, int rr) {
		vi a, b;
		int i, cnt = r - l + 1;
		FORS(i, 41) {
			a.push_back(0);
			b.push_back(0);
		}
		if(l == ll && r == rr) {
			FORS(i, 41) a[i] = mask[pos][i];
			return a;
		}
		int lef = pos << 1, rig = lef | 1, mid = (l + r) >> 1;
		if(ll <= mid)
			a = _find(lef, l, mid, ll, min(rr, mid));
		if(mid < rr)
			b = _find(rig, mid+1, r, max(mid+1, ll), rr);
		FORS(i, 41) {
			a[i] += b[i];
			a[i] = ((1LL << i) & op[pos]? cnt - a[i] : a[i]);
		}
		return a;
	}
	int n;
	vector<int> op;
	int mask[big][41];
};

int main(void)
{
	int n, i, q;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	
	Segtree seg(n);
	
	sf("%d", &q);
	while(q--) {
		int t, l, r, x;
		sf("%d %d %d", &t, &l, &r);
		--l, --r;
		if(t == 2) {
			sf("%d", &x);
			seg.update(l, r, x);
		} else
			pf("%I64d\n", seg.find(l, r));
	}
	return 0;
}
