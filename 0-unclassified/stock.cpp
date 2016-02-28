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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], h[N], m[N];

struct segtree {
public:
	segtree(int _n) : n(_n) {
		num.resize(4*n);
		push.resize(4*n);
		build(1, 1, n);
	}
	void ganti(int l, int r, int val) {
		if(l > r) return;
		update(1, 1, n, l, r, val);
	}
	int cari(int l, int r) {
		if(l > r) return 0;
		return find(1, 1, n, l, r);
	}
private:
	inline void build(int p, int l, int r) {
		if(l == r) {
			num[p] = a[l];
			push[p] = -1;
			return;
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		build(lef, l, mid);
		build(rig, mid + 1, r);
		num[p] = num[lef] + num[rig];
		push[p] = -1;
	}
	inline void relax(int p, int l, int r) {
		if(push[p] != -1) {
			int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
			num[p] = push[p];
			if(l < r) {
				push[lef] = push[p];
				push[rig] = push[p];
			}
			push[p] = -1;
		}
	}
	inline void update(int p, int l, int r, int ll, int rr, int val) {
		if(l == ll && r == rr) {
			push[p] = val;
			relax(p, l, r);
			return;
		}
		relax(p, l, r);
		if(r < ll || rr < l) return;
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		update(lef, l, mid, ll, min(rr, mid), val);
		update(rig, mid+1, r, max(mid+1, ll), rr, val);
		num[p] = num[lef] + num[rig];
	}
	inline int find(int p, int l, int r, int ll, int rr) {
		relax(p, l, r);
		if(r < ll || rr < l) return 0;
		if(l == ll && r == rr) {
			return num[p];
		}
		int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		int ret = 0;
		ret += find(lef, l, mid, ll, min(rr, mid));
		ret += find(rig, mid+1, r, max(mid+1, ll), rr);
		num[p] = num[lef] + num[rig];
		return ret;
	}
	vector<int> num, push;
	int n;
};

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j, n;
		sf("%d", &n);
		vector<pair<int,int> > wil;
		FOR(i, 1, n) {
			sf("%d %d %d", &a[i], &h[i], &m[i]);
			wil.push_back(mp(h[i], i));
		}
		sort(wil.begin(), wil.end());
		segtree seg(n);
		
		//FOR(i, 1, n) pf("%d %d\n", i, seg.cari(1, i));
		
		int ans = 0;
		FORM(i, n) {
			int id = wil[i].second;
			int sell = min(seg.cari(1, id), m[id]);
			int l = 1, r = id + 1;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(seg.cari(mid, id) <= sell) r = mid;
				else l = mid + 1;
			}
			int diff = sell - seg.cari(l, id);
			seg.ganti(l, id, 0);
			seg.ganti(l-1, l-1, seg.cari(l-1, l-1) - diff);
			ans += sell*h[id];
			//pf("sampai %d : %d %d %d\n", l, id, sell, h[id]);
			//FOR(j, 1, n) pf("%d ", seg.cari(j, j)); nl;
		}
		pf("%d\n", ans);
	}
	
	return 0;
}
