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

vector<int> edge[55];
bool done[55];

int dfs(int a){
	int i; int now = 0;
	if(edge[a].size())
	FORS(i, edge[a].size())
		if(!done[edge[a][i]]) {
			done[edge[a][i]] = 1;
			now += 1 + dfs(edge[a][i]);
		}
	return now;
}

int main(void)
{
	int n, m, ans = 0, i;
	sf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	FOR(i, 1, n) {
		done[i] = 1;
		ans += dfs(i);
	}
	cout << (1LL << ans) << endl;
	return 0;
}
