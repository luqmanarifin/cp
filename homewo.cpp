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
const int N = 2e5 + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL fib[N], x;

struct fenwick {
public:
	fenwick (int _n) : n(_n) {
		ad.resize(n + 1);
		co.resize(n + 1);
		ci.resize(n + 1);
	};
	void modify(int pos, int val) {
		pair<LL, LL> del = _cari(pos);
		_add(pos, 0, -del.first, -del.second);
		_add(pos, 0, (val*fib[pos]) % mod, (val*fib[pos+1]) % mod);
	}
	long long find(int l, int r) {
		long long cur = _find(l-1, r) - _find(l-1, l-1);
		return (cur < 0? cur + mod : cur);
	}
	void add(int l, int r, long long val) {
		long long ctrlo = (val*(fib[l+1] - 1)) % mod;
		long long ctrli = (val*(fib[l+2] - 2)) % mod;
		_add(l, val, -ctrlo, -ctrli);
		_add(r+1, -val + mod, (ctrlo + val*(fib[r+2] - fib[l+1])) % mod,
		(ctrli + val*(fib[r+3] - fib[l+2])) % mod);
	}
private:
	long long _find(int id, int pos) {
		int r = pos;
		long long idsi = (id == -1? 0 : fib[id]);
		long long idso = fib[id+1];
		long long temp = 0, ctrlo = 0, ctrli = 0;
		if(id & 1) idsi *= -1;
		else idso *= -1;
		
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			temp += ad[pos];
			ctrlo += co[pos];
			ctrli += ci[pos];
		}
		temp %= mod;
		ctrlo = (temp*(fib[r+2] - 1) + ctrlo) % mod;
		ctrli = (temp*(fib[r+3] - 2) + ctrli) % mod;

		long long cur = (ctrlo*idso + ctrli*idsi) % mod;
		return (cur < 0? cur + mod : cur);
	}
	void _add(int pos, long long val, long long ctrlo, long long ctrli) {
		if(ctrlo < 0) ctrlo += mod;
		if(ctrli < 0) ctrli += mod;
		if(val >= mod) val -= mod;
		for(; pos <= n; pos |= pos + 1) {
			ad[pos] += val;
			co[pos] += ctrlo;
			ci[pos] += ctrli;
			if(ad[pos] >= mod) ad[pos] -= mod;
			if(co[pos] >= mod) co[pos] -= mod;
			if(ci[pos] >= mod) ci[pos] -= mod;
		}
	}
	pair<LL,LL> _cari(int pos) {
		int r = pos;
		long long temp = 0, ctrlo = 0, ctrli = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			temp += ad[pos];
			ctrlo += co[pos];
			ctrli += ci[pos];
		}
		temp %= mod;
		ctrlo = (temp*(fib[r+2] - 1) + ctrlo) % mod;
		ctrli = (temp*(fib[r+3] - 2) + ctrli) % mod;
		
		pos = --r;
		long long tempp = 0, ctrlop = 0, ctrlip = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			tempp += ad[pos];
			ctrlop += co[pos];
			ctrlip += ci[pos];
		}
		tempp %= mod;
		ctrlop = (tempp*(fib[r+2] - 1) + ctrlop) % mod;
		ctrlip = (tempp*(fib[r+3] - 2) + ctrlip) % mod;
		
		ctrlo -= ctrlop;
		ctrli -= ctrlip;
		if(ctrlo < 0) ctrlo += mod;
		if(ctrli < 0) ctrli += mod;
		return mp(ctrlo, ctrli);
	}
	int n;
	vector<long long> ad, co, ci;
};

int main(void)
{
	int i, j, k, n, q;
	fib[0] = fib[1] = 1;
	FOR(i, 2, N-1) {
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] >= mod) fib[i] -= mod;
	}
	sf("%d %d", &n, &q);
	fenwick fen(n);
	FORS(i, n) {
		sf("%d", &x);
		fen.modify(i, x);
	}

	while(q--) {
		int t, l, r, val;
		sf("%d %d %d", &t, &l, &r);
		l--; r--;
		if(t == 1) fen.modify(l, r+1);
		else if(t == 2) pf("%d\n", (int) fen.find(l, r));
		else {
			sf("%d", &val);
			fen.add(l, r, 1LL*val);
		}
	}
	return 0;
}
