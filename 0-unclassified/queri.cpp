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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];
LL pre[N][10], c[10][10], fact[10];

long long get(int power, int l, int r) {
	LL temp = pre[r][power] - pre[l-1][power];
	if(temp < 0) temp += mod;
	return temp;
}

struct segtree {
public:
	segtree(int _n) : n(_n) {
		push.resize(4*n);
		int i;
		FORS(i, 10) num[i].resize(4*n);
		build(1, 1, n);
	};
	void ganti(int l, int r, int val) {
		replace(1, 1, n, l, r, val);
	}
	long long cari(int l, int r, int k) {
		return find(1, 1, n, l, r, k, 1 - l);
	}
private:
	void build(int p, int l, int r) {
		push[p] = -1;
		int i;
		if(l == r) {
			FOR(i, 0, 5) {
				num[i][p] = get(i, l, r)*a[l];
				num[i][p] %= mod;
			}
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		build(lef, l, mid);
		build(rig, mid+1, r);
		gather(p, l, r);
	}
	void relax(int p, int l, int r) {
		if(push[p] != -1) {
			int i;
			FOR(i, 0, 5) {
				num[i][p] = get(i, l, r)*push[p];
				num[i][p] %= mod;
			}
			if(l != r) {
				int lef = p << 1, rig = lef | 1;
				push[lef] = push[p];
				push[rig] = push[p];
			}
			push[p] = -1;
		}
	}
	void gather(int p, int l, int r) {
		int i, lef = p << 1, rig = lef | 1;;
		FOR(i, 0, 5) {
			num[i][p] = num[i][lef] + num[i][rig];
			if(num[i][p] >= mod) num[i][p] -= mod;
		}
	}
	void replace(int p, int l, int r, int ll, int rr, int val) {
		if(l == ll && r == rr) {
			push[p] = val;
		}
		relax(p, l, r);
		if(r < ll || rr < l) return;
		if(l == ll && r == rr) return;
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		replace(lef, l, mid, ll, min(rr, mid), val);
		replace(rig, mid+1, r, max(ll, mid+1), rr, val);
		gather(p, l, r);
	}
	long long find(int p, int l, int r, int ll, int rr, int k, LL shi) {
		relax(p, l, r);
		if(r < ll || rr < l) return 0;
		if(l == ll && r == rr) {
			LL ret = num[k][p], now = 1;
			int i;
			FORD(i, k-1, 0) {
				now *= shi;
				now %= mod;
				LL cur = now*c[k][k-i] % mod;
				cur = cur*num[i][p] % mod; 
				ret += cur;
			}
			ret %= mod;
			if(ret < 0) ret += mod;
			return ret;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		LL ret = 0;
		ret += find(lef, l, mid, ll, min(rr, mid), k, shi);
		ret += find(rig, mid+1, r, max(mid+1, ll), rr, k, shi);
		gather(p, l, r);
		if(ret >= mod) ret -= mod;
		return ret;
	}
	vector<LL> push, num[10];
	int n;
};

int main(void)
{
	int i, j, n, m;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) {
		pre[i][0] = 1;
		FOR(j, 1, 5) {
			pre[i][j] = pre[i][j-1]*i;
			pre[i][j] %= mod;
		}
	}
	FOR(j, 0, 5) FOR(i, 1, n) {
		pre[i][j] += pre[i-1][j];
		if(pre[i][j] >= mod) pre[i][j] -= mod;
	}
	fact[0] = 1;
	FOR(i, 1, 9) fact[i] = fact[i-1]*i;
	FORS(i, 6) FORS(j, 6) {
		if(i < j) {
			c[i][j] = 0;
			continue;
		}
		c[i][j] = fact[i]/fact[j]/fact[i-j];
	}
	
	FOR(i, 1, n) sf("%d", a + i);
	segtree seg(n);
	while(m--) {
		char s, junk[5];
		int l, r, x;
		sf("\n%c %d %d %d", &s, &l, &r, &x);
		if(s == '=') seg.ganti(l, r, x);
		else pf("%d\n", (int) seg.cari(l, r, x));
	}
	return 0;
}
