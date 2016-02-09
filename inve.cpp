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
#define END { puts("NO"); return 0; } 

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> pii;
#define x first
#define y second

int dis[2005][2005], asli[2005][2005];
vector<pii> adj[2005];
priority_queue<pair<int, pii> > pq;
bool done[2005];

void dfs(int sou, int now, int dist, int bef) {
	asli[sou][now] = dist;
	int i;
	FORS(i, adj[now].size()) {
		int near = adj[now][i].x;
		int will = adj[now][i].y;
		if(near == bef) continue;
		dfs(sou, near, dist + will, now);
	}
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) FORS(j, n) {
		sf("%d", &dis[i][j]);
		if(i == j) {
			if(dis[i][j]) END;
		} else {
			if(dis[i][j] == 0) END;
		}
	}
	FORS(i, n) FORS(j, n) {
		if(i == j) continue;
		if(dis[i][j] != dis[j][i]) END;
	}
	pq.push(mp(-dis[0][0], mp(0, 0)));
	while(!pq.empty()) {
		int dist = -pq.top().x;
		int now = pq.top().y.x;
		int bef = pq.top().y.y;
		pq.pop();
		if(done[now]) continue;
		done[now] = 1;
		adj[bef].push_back(mp(now, dist));
		adj[now].push_back(mp(bef, dist));
		FORS(i, n) if(!done[i]) {
			pq.push(mp(-dis[i][now], mp(i, now)));
		}
	}
	FORS(i, n) dfs(i, i, 0, -1);
	//FORS(i, n) { FORS(j, n) pf("%d ", asli[i][j]); nl; }
	FORS(i, n) FORS(j, n) if(dis[i][j] != asli[i][j]) END;
	puts("YES");
	return 0;
}
