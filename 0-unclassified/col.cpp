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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct fenwick {
public:
	fenwick(int _n) : n(_n) {
		a.resize(n + 1);
		at.resize(n + 1);
	};
	void update(int l, int r, long long val) {
		_update(l, val, l * val);
		_update(r + 1, -val, (r + 1)*-val);
	}
	long long find(int l, int r) {
		return find(r) - find(l - 1);
	}
private:
	void _update(int pos, long long aval, long long atval) {
		for(; pos <= n; pos |= pos + 1) {
			a[pos] += aval;
			at[pos] += atval;
		}
	}
	long long find(int pos) {
		int r = pos;
		long long aval = 0, atval = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			aval += a[pos];
			atval += at[pos];
		}
		return (r + 1) * aval - atval;
	}
	vector<LL> a, at;
	int n;
};

struct item {
	item(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {};
	int l, r, val;
};

bool operator < (const item &a, const item &b) {
  return a.l < b.l || (a.l == b.l && a.r < b.r) || (a.l == b.l && a.r == b.r && a.val < b.val);
}

set<item> f;

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	fenwick fen(n);
	FORS(i, n) f.insert(item(i, i, i + 1));
	while(m--) {
		int t, l, r, x;
		sf("%d %d %d", &t, &l, &r);
		--l, --r;
		if(t == 1) {
			sf("%d", &x);
			set<item>::iterator it = f.upper_bound(item(l, n + 5, inf)), tmp;
			it--;
			while(it != f.end()) {
				if(r < it->l) break;
				if(it->l < l)
					f.insert(item(it->l, l - 1, it->val));
				if(r < it->r)
					f.insert(item(r + 1, it->r, it->val));
				fen.update(max(l, it->l), min(r, it->r), abs(x - it->val));
				tmp = it; it++;
				f.erase(tmp);
			}
			f.insert(item(l, r, x));
		} else {
			pf("%I64d\n", fen.find(l, r));
		}
	}
	return 0;
}
