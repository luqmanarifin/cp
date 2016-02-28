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
const int N = 1e4 + 5;
 
int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL tot;
int n;
vector<pair<int,int> > edge[N];

int dfs(int now, int prev) {
	int i, j, son = 0;
	FORS(i, edge[now].size()) {
		int side = edge[now][i].first;
		int cost = edge[now][i].second;
		if(side == prev) continue;
		int cucu = dfs(side, now);
		son += cucu;
		tot += 1LL*cucu*(n - cucu)*cost;
	}
	return son + 1;
}

int main(void)
{
	int t, i, j;
	sf("%d", &t);
	while(t--) {
		tot = 0;
		FORS(i, N) edge[i].clear();
		sf("%d", &n);
		FORS(i, n - 1) {
			int a, b, c;
			sf("%d %d %d", &a, &b, &c);
			edge[a].push_back(mp(b, c));
			edge[b].push_back(mp(a, c));
		}
		int ampas = dfs(0, -1);
		pf("%.18lf\n", (double) tot / (1LL*(n - 1)*n/2));
	}
	
	return 0;
}
