#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 2e5 + 5;

int dp[N][25];
bool done[N][25];
vector<int> edge[N];
queue<pair<int,int>> q;

void dfs(int now, int col) {
	if(done[now][col]) return;
	done[now][col] = 1;
	int i, j;
	FORS(i, edge[now].size()) {
		FOR(j, 1, 20) if(j != col) {
			dfs(edge[now][i], j);
		}
	}
	q.emplace(now, col);
}

int main(void)
{
	int n, i, j, tt, t;
	sf("%d", &t);
	FOR(tt, 1, t) {
		reset(done, 0);
		FORS(i, N) FORS(j, 21) dp[i][j] = -1;
		FORS(i, N) edge[i].clear();
		sf("%d", &n);
		FOR(i, 1, n) {
			int a;
			sf("%d", &a);
			edge[a].push_back(i);
		}
		FOR(i, 1, 20) dfs(1, i);
		while(!q.empty()) {
			int now, col;
			tie(now, col) = q.front();
			q.pop();
			dp[now][col] = col;
			FORS(i, edge[now].size()) {
				int cur = inf;
				FOR(j, 1, 20) if(j != col) {
					cur = min(cur, dp[edge[now][i]][j]);
				}
				dp[now][col] += cur;
			}
		}
		int ans = inf;
		FOR(i, 1, 20) ans = min(ans, dp[1][i]);
		pf("Case #%d: %d\n", tt, ans);
	}
	
	return 0;
}
