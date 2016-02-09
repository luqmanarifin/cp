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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[N];
int sum[N];
int bit[N], n;

// lazy propagation for segmented tree stuff
vector<int> num[N << 2];
int push[N << 2];

void relax(int p, int l, int r) {
	if(push[p]) {
		push[p] %= 3;
		if(push[p] == 0) return;
		int i, mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
		if(l < r) {
			push[lef] += push[p];
			push[rig] += push[p];
		}
		if(push[p] == 1) {
			int temp = num[p][2];
			FORD(i, 2, 1) num[p][i] = num[p][i-1];
			num[p][0] = temp;
		}
		if(push[p] == 2) {
			int temp = num[p][0];
			FOR(i, 0, 1) num[p][i] = num[p][i+1];
			num[p][2] = temp;
		}
		push[p] = 0;
	}
}

void build(int p, int l, int r) {
	num[p].resize(3, 0);
	if(l == r) {
		num[p][sum[l] % 3]++;
		return;
	}
	int i, mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
	build(lef, l, mid);
	build(rig, mid+1, r);
	FORS(i, 3) num[p][i] = num[lef][i] + num[rig][i];
}

void update(int p, int l, int r, int ll, int rr, int swap) {
	if(l == ll && r == rr) {
		push[p] += swap;
	}
	relax(p, l, r);
	if(r < ll || rr < l) return;
	if(l == ll && r == rr) return;
	int i, mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
	update(lef, l, mid, ll, min(mid, rr), swap);
	update(rig, mid+1, r, max(mid+1, ll), rr, swap);
	FORS(i, 3) num[p][i] = num[lef][i] + num[rig][i];
}

vector<int> find(int p, int l, int r, int ll, int rr) {
	int i;
	relax(p, l, r);
	if(l == ll && r == rr) return num[p];
	if(r < ll || rr < l) {
		vector<int> nol;
		FORS(i, 3) nol.push_back(0);
		return nol;
	}
	int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
	vector<int> left = find(lef, l, mid, ll, min(mid, rr));
	vector<int> right = find(rig, mid+1, r, max(mid+1, ll), rr);
	FORS(i, 3) num[p][i] = num[lef][i] + num[rig][i];
	FORS(i, 3) left[i] += right[i];
	return left;
}

void debug(vector<int> a) {
	int i;
	FORS(i, a.size()) pf("%d ", a[i]); nl;
}

void add(int i, int v) {
	for(; i <= n; i |= i + 1) {
		bit[i] += v;
	}
}

int get(int i) {
	int temp = 0;
	for(; i >= 0; i = (i & (i + 1)) - 1) {
		temp += bit[i];
	}
	return temp;
}

int main(void)
{
	//open;
	int m, i;
	sf("%d %d", &n, &m);
	sf("%s", &s[1]);
	FOR(i, 1, n) {
		s[i] -= '0';
		add(i, (int) s[i]);
		sum[i] = sum[i-1] + s[i];
	}
	build(1, 1, n);
	while(m--) {
		int t, a, b;
		sf("%d %d %d", &t, &a, &b);
		if(t == 1) {
			int dif = b - s[a];
			dif %= 3;
			if(dif < 0) dif += 3;
			update(1, 1, n, a, n, dif);
			add(a, (int) -s[a]);
			s[a] = b;
			add(a, (int) s[a]);
		} else {
			vector<int> ret = find(1, 1, n, a, b);
			int trans = get(a - 1) % 3;
			while(trans--) {
				int temp = ret[0];
				FOR(i, 0, 1) ret[i] = ret[i+1];
				ret[2] = temp;
			}
			ret[0]++;
			LL ans = 0;
			FORS(i, 3) ans += (LL) ret[i] * (ret[i] - 1) / 2;
			pf("%lld\n", ans);
		}
	}
	
	//close;
	return 0;
}
