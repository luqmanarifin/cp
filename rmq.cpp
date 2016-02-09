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
#define open freopen("segtree.txt","w",stdout)
#define close fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define fi first
#define se second

vector<LL> num;

struct Segtree {
public:
	Segtree(int _n) : n(_n) {
		a.resize(2*n);
		c.resize(2*n);
		t.resize(2*n);
		tmp.resize(2*n);
		int i;
		sz = num.size();
		FORS(i, n) c[n+i].fi = c[n+i].se = i;
		FORD(i, n-1, 1) {
			int le = i*2;
			int ri = i*2 + 1;
			c[i].fi = c[le].fi;
			c[i].se = c[ri].se;
		}
		FORS(i, 2*n) a[i] = INF, t[i] = tmp[i] = 0;
	};
	void build(int pos) {
		if(pos >= n) {
			if(pos-n < sz)
				a[pos] = num[pos-n];
			return;
		}
		int lef = 2*pos;
		int rig = 2*pos + 1;
		build(lef);
		build(rig);
		a[pos] = min(a[lef], a[rig]);
	}
	void update(int l, int r, LL x) {
		_lazy(1, l); _lazy(1, r);
		if(l > r) {
			_update(1, 0, r, x);
			_update(1, l, sz-1, x);
		} else
			_update(1, l, r, x);
	}
	LL find(int l, int r) {
		if(l > r) return
			min(_find(1, 0, r), _find(1, l, sz-1));
		return _find(1, l, r);
	}
	void debug() {
		int i;
		FOR(i, 1, 2*n-1) pf("%d ", i); nl;
		puts("a : ");
		FOR(i, 1, 2*n-1) pf("%I64d ", a[i]); nl;
		puts("t : ");
		FOR(i, 1, 2*n-1) pf("%I64d ", t[i]); nl;
		puts("tmp : ");
		FOR(i, 1, 2*n-1) pf("%I64d ", tmp[i]); nl;
		nl;
	}
private:
	void _lazy(int pos, int x) {
		if(pos >= n) return;
		int lef = 2*pos;
		int rig = 2*pos + 1;
		LL waris = t[pos] + tmp[pos];
		a[lef] += waris - t[lef];
		// if(c[rig].fi <= x)
		a[rig] += waris - t[rig];
		t[lef] = t[rig] = waris;
		if(x <= c[lef].se)
			_lazy(lef, x);
		else
			_lazy(rig, x);
	}
	void _update(int pos, int l, int r, LL x) {
		if(c[pos].fi == l && c[pos].se == r) {
			a[pos] += x;
			if(pos < n) tmp[pos] += x;
			_upd(pos/2);
			return;
		}
		int lef = pos*2;
		int rig = pos*2 + 1;
		if(l <= c[lef].se)
			_update(lef, l, min(r, c[lef].se), x);
		if(c[rig].fi <= r)
			_update(rig, max(l, c[rig].fi), r, x);
	}
	void _upd(int pos) {
		if(pos == 0) return;
		a[pos] = min(a[2*pos], a[2*pos+1]);
		_upd(pos/2);
	}
	long long _find(int pos, int l, int r) {
		LL waris = t[pos/2] + tmp[pos/2];
		a[pos] += waris - t[pos];
		t[pos] = waris;
		if(c[pos].fi == l && c[pos].se == r) {
			return a[pos];
		}
		int lef = pos*2;
		int rig = pos*2 + 1;
		LL cur = INF;
		if(l <= c[lef].se)
			cur = min(cur, _find(lef, l, min(r, c[lef].se)));
		if(c[rig].fi <= r)
			cur = min(cur, _find(rig, max(l, c[rig].fi), r));
		return cur;
	}
	LL n, sz;
	vector<LL> a, tmp, t;
	vector<pair<int,int> > c;
	/*
		a[i] = elemen terkecil di pada segmen ke-i
		tmp[i] = inc tepat pada segmen ke-i
		t[i] = inc yg SUDAH dilakukan oleh segmen ke-i
		c[i].first = merujuk nomer elemen pertama yg dinaungi segmen i
		c[i].second = merujuk nomer elemen terakhir yg dinaungi segmen i
	*/
};

LL d[3];

bool space(char c) {
	if(('0' <= c && c <= '9') || c == '-') return 0;
	return 1;
}

int main(void)
{
	//open;
	int n, i, j, p = 1; 
	char junk[105];
	sf("%d", &n);
	FORS(i, n) {
		int x; sf("%d", &x);
		num.push_back(1LL*x);
	}
	while(p < n) p *= 2;
	Segtree seg(p);
	seg.build(1);
	
	int q, tt = 0; sf("%d", &q);
	gets(junk);
	FOR(j, 1, q) {
		gets(junk);
		LL l, r, x;
		stringstream ss(junk);
		ss >> l >> r;
		if(ss >> x)
			seg.update(l, r, x);
		else
			pf("%I64d\n", seg.find(l, r));
		//seg.debug();
	}
	//close;
	return 0;
}
