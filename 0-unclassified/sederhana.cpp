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
const int N = 5e4 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int child[N];
vector<int> edge[N];

int dfs(int pos, int prev) {
	int i, j;
	FORS(i, edge[pos].size()) {
		int near = edge[pos][i];
		if(near == prev) continue;
		child[pos] += dfs(near, pos);
	}
	return ++child[pos];
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j, n, a, b, id = 0;
		reset(child, 0);
		sf("%d", &n);
		FOR(i, 1, n) edge[i].clear();
		FORS(i, n-1) {
			sf("%d %d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		int inas = dfs(1, -1);
		LL ans = 0;
		FOR(i, 2, n) ans += 2LL*child[i]*(n - child[i]);
		pf("%lld\n", ans);
	}
	return 0;
}
