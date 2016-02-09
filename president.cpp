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

LL dist[505][505];
int len[505][505];
bool done[505];
vector<pair<int,int> > edge[505];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	while(m--) {
		int a, b, w;
		sf("%d %d %d", &a, &b, &w);
		edge[a].push_back(mp(b, w));
		edge[b].push_back(mp(a, w));
	}
	FORS(i, 505) FORS(j, 505) dist[i][j] = INF;
	FOR(i, 1, n) {
		reset(done, 0);
		priority_queue<pair<LL, int> > pq;
		dist[i][i] = 0;
		pq.push(mp(0, i));
		while(!pq.empty()) {
			int now = pq.top().second;
			LL cost = -pq.top().first;
			pq.pop();
			if(cost != dist[i][now]) continue;
			FORS(j, edge[now].size()) {
				LL ncos = edge[now][j].second;
				int near = edge[now][j].first;
				if(dist[i][now] + ncos < dist[i][near]) {
					dist[i][near] = dist[i][now] + ncos;
					pq.push(mp(-dist[i][near], near));
					len[i][near] = len[i][now] + 1;
					if(done[now]) len[i][near] -= len[i][now];
					done[now] = 1;
				} else if(dist[i][now] + ncos == dist[i][near]) {
					len[i][near] += len[i][now] + 1;
					if(done[now]) len[i][near] -= len[i][now];
					done[now] = 1;
				}
			}
		}
	}
	FOR(i, 1, n) FOR(j, i + 1, n) {
		if(dist[i][j] == INF) pf("0 ");
		else pf("%d ", max(len[i][j], len[j][i]));
	}
	nl; return 0;
}
