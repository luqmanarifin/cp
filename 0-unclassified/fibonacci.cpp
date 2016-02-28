#include <bits/stdc++.h>

/**
 * Codeforces Round #FF (Div. 2)
 * Problem : E
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

const LL mod = 1e9 + 9;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 3e5;
const int N5 = N + 5;

#define upd(x) if(x >= mod) x -= mod

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct fenwick {
public:
	fenwick(int _n) : n(_n) {
		a.resize(n + 1);
		at.resize(n + 1);
	};
	void update(int l, int r, long long val) {
		_update(l, val, (val * l) % mod);
		_update(r + 1, -val, (-val * (r + 1)) % mod);
	}
	long long find(int l, int r) {
		LL res = find(r) - find(l - 1);
		if(res < 0) res += mod;
		return res;
	}
private:
	void _update(int pos, long long aval, long long atval) {
		for(; pos <= n; pos |= pos + 1) {
			a[pos] += aval; upd(a[pos]);
			at[pos] += atval; upd(at[pos]);
		}
	}
	long long find(int pos) {
		int r = pos;
		long long aval = 0, atval = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			aval += a[pos]; upd(aval);
			atval += at[pos]; upd(atval);
		}
		LL cur = (r + 1) * aval - atval;
		cur %= mod;
		if(cur < 0) cur += mod;
		return cur;
	}
	vector<LL> a, at;
	int n;
};

int fib[N5];

int main(void)
{
	int n, m, i, j, x;
	sf("%d %d", &n, &m);
	fenwick fen(n);
	FORS(i, n) {
		sf("%d", &x);
		fen.update(i, i, x);
	}
	fib[1] = 1;
	fib[2] = 1;
	FOR(i, 3, n) {
		fib[i] = fib[i-1] + fib[i-2];
		upd(fib[i]);
	}
	while(m--) {
		int t, l, r;
		sf("%d %d %d", &t, &l, &r);
		--l, --r;
		if(t == 1) {
			FOR(i, l, r) fen.update(i, i, fib[i-l+1]);
		} else
			pf("%I64d\n", fen.find(l, r));
	}
	return 0;
}
