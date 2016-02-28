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

int node[505], udah[505];
vector<pair<int,int> > side[505];
bool done[505];

double val(pair<LL, LL> a) {
	if(!a.second) return 0;
	return (DB) a.first / a.second;
}	

pair<LL,LL> add(int prev, int a, LL v, LL e) {
	int i;
	//cout << a << ' '<< v << ' ' << e << endl;
	LL ver = v + node[a];
	LL edg = e;
	FORS(i, side[a].size()) {
		pair<int,int> now = side[a][i];
		if(done[now.first]) {
			if(now.first != prev)
				ver += node[now.first];
			edg += now.second;
		}
	}
	done[a] = 1;
	pair<LL, LL> cur = mp(ver, edg);
	FORS(i, side[a].size()) {
		if(!done[side[a][i].first]) {
			if(side[a][i].first == prev) continue;
			if(udah[side[a][i].first]) continue;
			pair<LL, LL> dfs = add(a, side[a][i].first, cur.first, cur.second);
			if(val(dfs) > val(cur))
				cur = dfs;
		}
	}
	//cout << prev << ' ' << a << ' ' << cur.first << ' ' << cur.second; nl;
	if(val(cur) > val(mp(v + node[a], e)))
		udah[a] = 1;
	return cur;
}

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%d", &node[i]);
	while(m--) {
		int a, b, c;
		sf("%d %d %d", &a, &b, &c);
		side[a].push_back(mp(b, c));
		side[b].push_back(mp(a, c));
	}
	double ans = 0;
	FOR(i, 1, n) {
		reset(done, 0);
		if(udah[i]) continue;
		udah[i] = 1;
		done[i] = 1;
		pair<LL, LL> cur = mp(node[i], 0);
		FORS(j, side[i].size()) {
			pair<LL, LL> dfs = add(i, side[i][j].first, cur.first, cur.second);
			if(val(dfs) > val(cur))
				cur = dfs;
		}
		if(val(cur) > ans)
			ans = val(cur);
	}
	pf("%.12f\n", ans);
	return 0;
}
