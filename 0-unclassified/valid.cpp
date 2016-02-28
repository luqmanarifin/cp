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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> adj[2005];
int cost[2005], d, n;

inline LL dfs(int now, int prev, int id) {
	LL ret = 1, i;
	FORS(i, adj[now].size()) {
		int near = adj[now][i];
		if(near == prev) continue;
		if(cost[id] < cost[near] && cost[near] <= cost[id] + d
		||(cost[id] == cost[near] && id < near)) {
			ret *= (dfs(near, now, id) + 1);
			ret %= mod;
		}
	}
	return ret;
}

int main(void)
{
	int i, j;
	sf("%d %d", &d, &n);
	FOR(i, 1, n) sf("%d", &cost[i]);
	FORS(i, n-1) {
		int a, b;
		sf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	FOR(i, 1, n) {
		ans += dfs(i, -1, i);
		if(ans >= mod) ans -= mod;
	}
	cout << ans << endl;
	return 0;
}
