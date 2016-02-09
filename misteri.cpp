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
char s[N];

struct segtree {
public:
	segtree(int _n) : n(_n) {
		push.resize(4*n);
		num.resize(4*n);
		build(1, 0, n-1);
	};
	void flip(int pos) {
		if(s[pos] == '(')
			add(1, 0, n-1, pos, n-1, -2), s[pos] = ')';
		else
			add(1, 0, n-1, pos, n-1, 2), s[pos] = '(';
	}
	void cek() {
		if(find(1, 0, n-1, n-1, n-1) == 0 && find(1, 0, n-1, 0, n-1) >= 0)
			pf("Y");
		else
			pf("T");
	}
private:
	void build(int p, int l, int r) {
		push[p] = 0;
		if(l == r) {
			num[p] = a[l];
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		build(lef, l, mid);
		build(rig, mid+1, r);
		num[p] = min(num[lef], num[rig]);
	}
	void add(int p, int l, int r, int ll, int rr, int val) {
		if(l == ll && r == rr) {
			push[p] += val;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		if(ll <= mid) add(lef, l, mid, ll, min(rr, mid), val);
		if(mid < rr) add(rig, mid+1, r, max(ll, mid+1), rr, val);
		num[p] = min(num[lef] + push[lef], num[rig] + push[rig]);
	}
	int find(int p, int l, int r, int ll, int rr) {
		if(l == ll && r == rr) {
			return num[p] + push[p];
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		int ret = inf;
		if(ll <= mid) ret = min(ret, find(lef, l, mid, ll, min(rr, mid)));
		if(mid < rr) ret = min(ret, find(rig, mid+1, r, max(mid+1, ll), rr));
		return ret + push[p];
	}
	vector<int> push, num;
	int n;
};

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		sf("%s", s);
		int n = strlen(s), i, j, type, pos;
		FORS(i, n) a[i] = (s[i] == '('? 1 : -1);
		FOR(i, 1, n-1) a[i] += a[i-1];
		segtree seg(n);
		while(true) {
			sf("%d", &type);
			if(type == -1) break;
			if(type) {
				sf("%d", &pos);
				seg.flip(pos);
			} else
				seg.cek();
		}
		nl;
	}
	
	return 0;
}
