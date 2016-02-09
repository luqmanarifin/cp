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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int par[2005];
vector<int> edge[2005];
bool done[2005];
bool gak[2005];

int find(int a) {
	if(a != par[a]) par[a] = find(par[a]);
	return par[a];
}

int dfs(int a) {
	int i;
	if(done[a]) return 0;
	done[a] = 1;
	int ret = 1;
	FORS(i, edge[a].size()) {
		int near = edge[a][i];
		ret += dfs(near);
	}
	return ret;
}

void benci(int a) {
	int i;
	if(gak[a]) return;
	gak[a] = 1;
	FORS(i, edge[a].size()) {
		int near = edge[a][i];
		benci(near);
	}
}

int main(void)
{
	//open;
	int n, i, j;
	sf("%d", &n);
	FORS(i, 2005) par[i] = i;
	int q;
	sf("%d", &q);
	while(q--) {
		int a, b;
		sf("%d %d", &a, &b);
		if(find(a) != find(b)) {
			par[find(a)] = b;
		}
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	sf("%d", &q);
	while(q--) {
		int a, b;
		sf("%d %d", &a, &b);
		if(find(a) == find(b)) {
			benci(a);
		}
	}
	int ans = 0;
	FOR(i, 1, n) {
		if(!gak[i] && !done[i]) ans = max(ans, dfs(i));
	}
	cout << ans << endl;
	//close;
	return 0;
}
