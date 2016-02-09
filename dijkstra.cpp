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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int last[N], n;
LL path[N];
pair<int, LL> edge[7*N];
vector<int> adj[N];

void dijkstra() {
	int i;
	FOR(i, 1, n) path[i] = INF, last[i] = inf;
	priority_queue<pair<LL, int> > p;	// cost && which city
	path[1] = 0;
	p.push(mp(0LL, 1));
	while(!p.empty()) {
		int now = p.top().second;
		LL cost = -p.top().first;
		p.pop();
		if(cost > path[now]) continue;
		FORS(i, adj[now].size()) {
			int id = adj[now][i];
			int near = edge[id].first;
			LL bakal = cost + edge[id].second;
			if(bakal < path[near])
				path[near] = bakal, last[near] = id, p.push(mp(-bakal, near));
			else if(bakal == path[near])
				last[near] = min(last[near], id);
		}
	}
}

int main(void)
{
	int m, k, i, j, a, b, x;
	sf("%d %d %d", &n, &m, &k);
	int id = 0;
	while(m--) {
		sf("%d %d %d", &a, &b, &x);
		edge[id] = mp(b, x);
		adj[a].push_back(id);
		id++;
		
		edge[id] = mp(a, x);
		adj[b].push_back(id);
		id++;
	}
	int lim = id;
	FORS(i, k) {
		sf("%d %d", &a, &x);
		edge[id] = mp(a, x);
		adj[1].push_back(id);
		id++;
	}
	
	dijkstra();

	int trainShortest = 0;
	FOR(i, 2, n) if(last[i] >= lim) ++trainShortest;
	cout << k - trainShortest << endl;
	return 0;
}
