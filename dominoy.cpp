#include <bits/stdc++.h>

/**
 * Good Bye 2014
 * Problem : E
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
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
const double eps = 1e-13;
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int num[N << 2];
LL bit[N];
int n;
int p[N], l[N], to[N];	// to[i] bisa reach sampe mana domino ke-i
int cost[N];				// berapa harga satu komponen ke next komponen terpisah 

vector<pair<int,int> > query[N];
int ans[N];

void update(int i, LL val) {
	for(; i <= n; i |= i + 1) {
		bit[i] += val;
	}
}

LL get(int i) {
	LL ret = 0;
	for(; i >= 0; i = (i & (i + 1)) - 1) {
		ret += bit[i];
	}
	return ret;
}

void build(int p, int l, int r) {
	if(l == r) {
		num[p] = to[l];
		return;
	}
	int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
	build(lef, l, mid);
	build(rig, mid+1, r);
	num[p] = max(num[lef], num[rig]);
}

int rmq(int p, int l, int r, int ll, int rr) {
	if(r < ll || rr < l) {
		return -inf;
	}
	if(l == ll && r == rr) {
		return num[p];
	}
	int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
	int ret = -inf;
	ret = max(ret, rmq(lef, l, mid, ll, min(mid, rr)));
	ret = max(ret, rmq(rig, mid+1, r, max(mid+1, ll), rr));
	return ret;
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d %d", &p[i], &l[i]);
		to[i] = p[i] + l[i];
	}
	int q;
	sf("%d", &q);
	FORS(i, q) {
		int a, b;
		sf("%d %d", &a, &b);
		a--; b--;
		query[a].push_back(mp(b, i));
	}
	build(1, 0, n-1);
	
	set<int> komp;
	FORM(i, n) {
		int unreach = upper_bound(p, p + n, to[i]) - p;
		set<int>::iterator it = komp.begin();
		while(it != komp.end() && *it < unreach) {
			int awal = *it;
			set<int>::iterator del = it;
			update(awal, -cost[awal]);
			cost[awal] = 0;
			it++;
			komp.erase(del);
		}
		if(it != komp.end()) {
			int pos = *it;
			update(pos, -cost[pos]);
			cost[pos] = p[pos] - rmq(1, 0, n-1, i, pos-1);
			update(pos, cost[pos]);
		}
		FORS(j, query[i].size()) {
			int last = query[i][j].first;
			int id = query[i][j].second;
			ans[id] = get(last);
		}
		komp.insert(i);
	}
	FORS(i, q) pf("%d\n", ans[i]);
	
	return 0;
}
