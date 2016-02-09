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

int n, ans;
bool done[105];
vector<int> edge[105], lv[105];

void bfs(int pos, int id) {
	int i;
	if(edge[pos].size())
	FORS(i, edge[pos].size()) {
		int near = edge[pos][i];
		if(!done[near]) {
			lv[id+1].push_back(near);
			done[near] = 1;
		}
	}
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, m, z;
		ans = 0;
		reset(done, 0);
		sf("%d %d %d", &n, &m, &z);
		FORS(i, 105) {
			edge[i].clear();
			lv[i].clear();
		}
		while(m--) {
			int a, b;
			sf("%d %d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		lv[1].push_back(z);
		done[z] = 1;
		FOR(i, 1, 104) {
			if(lv[i].empty()) break;
			ans = i;
			int j;
			FORS(j, lv[i].size())
				bfs(lv[i][j], i);
		}
		pf("%d\n", ans); 
	}
	return 0;
}
