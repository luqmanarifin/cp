#include <bits/stdc++.h>

/**
 * CompFest 2014 Preliminary Round - Perguruan Tinggi
 * Problem : D
 * Gajah Wangi
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct segtree {
public:
	segtree (int _n) : n(_n) {
		num.resize(4*n);
		mak.resize(4*n);
		build(1, 1, n);
	};
	void ubah(int l, int val, int maks) {
		flip(1, 1, n, l, l, val, maks);
	}
	pair<int,int> cari(int l, int r) {
		return find(1, 1, n, l, r);
	}
private:
	void build(int p, int l, int r) {
		if(l == r) {
			num[p] = (l == 1? 0 : inf);
			mak[p] = (l == 1? 0 : -inf);
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		build(lef, l, mid);
		build(rig, mid+1, r);
		num[p] = min(num[lef], num[rig]);
		mak[p] = max(mak[lef], mak[rig]);
	}
	void flip(int p, int l, int r, int ll, int rr, int val, int maks) {
		if(l == ll && r == rr) {
			num[p] = val;
			mak[p] = maks;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		if(ll <= mid) flip(lef, l, mid, ll, min(mid, rr), val, maks);
		if(mid < rr) flip(rig, mid+1, r, max(mid+1, ll), rr, val, maks);
		num[p] = min(num[lef], num[rig]);
		mak[p] = max(mak[lef], mak[rig]);
	}
	pair<int,int> find(int p, int l, int r, int ll, int rr) {
		if(l == ll && r == rr) {
			return mp(num[p], mak[p]);
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1, cur = inf, maks = -inf;
		if(ll <= mid) {
			pair<int,int> now = find(lef, l, mid, ll, min(mid, rr));
			cur = min(cur, now.first);
			maks = max(maks, now.second);
		}
		if(mid < rr) {
			pair<int,int> now = find(rig, mid+1, r, max(mid+1, ll), rr);
			cur = min(cur, now.first);
			maks = max(maks, now.second);
		}
		return mp(cur, maks);
	}
	int n;
	vector<int> num, mak;
};

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, n, m;
		sf("%d %d", &n, &m);
		segtree seg(n);
		FOR(i, 2, n) {
			int a, b;
			sf("%d %d", &a, &b);
			pair<int,int> rmq = seg.cari(a, b);
			seg.ubah(i, rmq.first^1, rmq.second^1);
		}
		int sum = 0;
		FORS(i, m) {
			int x;
			sf("%d", &x);
			pair<int,int> now = seg.cari(x, x);
			//pf("kandi %d %d\n", now.first, now.second);
			if(now.first) sum++;
		}
		//pf("%d\n", sum);
		if(sum & 1) puts("Marko");
		else puts("Ferde");
		//FOR(i, 1, n) pf("%d ", seg.cari(i, i).first); nl;
		//FOR(i, 1, n) pf("%d ", seg.cari(i, i).second); nl;
	}
	return 0;
}
