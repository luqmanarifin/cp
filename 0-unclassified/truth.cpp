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
const int N = 1e4 + 4;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dad[N], dp[N][2];
int at[N];
vector<int> first, son[N];

int dfs(int pos, int id) {
	if(dp[pos][id] != -1) return dp[pos][id];
	int temp = (id != at[pos]), i;
	FORS(i, son[pos].size()) {
		int near = son[pos][i];
		if(id) temp += dfs(near, 1);
		else temp += min(dfs(near, 0), dfs(near, 1));
	}
	return dp[pos][id] = temp;
}

int main(void)
{
	int t, tt, i;
	sf("%d", &t);
	FOR(tt, 1, t) {
		reset(dad, 0);
		reset(dp, -1);
		reset(at, 0);
		first.clear();
		FORS(i, N) son[i].clear();
		int n;
		sf("%d", &n);
		FOR(i, 1, n) {
			sf("%d", &dad[i]);
			if(dad[i] == 0) first.push_back(i);
			else son[dad[i]].push_back(i);
		}
		FOR(i, 1, n) sf("%d", &at[i]);
		int sz = (int) first.size();
		int ans = 0;
		FORS(i, sz) {
			ans += min(dfs(first[i], 0), dfs(first[i], 1));
		}
		pf("Case #%d: %d\n", tt, ans);
	}
	
	return 0;
}
