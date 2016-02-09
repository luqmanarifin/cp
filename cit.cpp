#include <bits/stdc++.h>

/**
 * Codeforces Round #257 (Div. 2)
 * Problem : D
 * Luqman Arifin (kadalbonek)
 */

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

int udah, n;
bool done[N];
LL path[N];
vector<pair<int,int> > adj[N];	// isinya samping node brp sama lengthnya
int train[N];

void find(int pos) {
	//pf("%d\n", pos);
	if(udah == n) return;
	int i, j, next, near;
	LL cur = INF;
	FORS(i, adj[pos].size()) {
		near = adj[pos][i].first;
		LL len = adj[pos][i].second;
		
		if(!done[near]) {
			//pf("%d %d\n", pos, near);
			if(path[pos] + len < path[near])
				path[near] = path[pos] + len;
			if(path[near] <= cur) {
				next = near;
				cur = path[near];
			}
		}
	}

	if(udah == n) return;
	if(cur != INF) {
		done[near] = 1;
		udah++;
	}
	vector<pair<LL, int> > edge;
	FORS(i, adj[pos].size()) {
		near = adj[pos][i].first;
		if(!done[near])
			edge.push_back(mp(path[near], near));
	}
	sort(edge.begin(), edge.end());
	FORS(i, edge.size()) {
		near = edge[i].second;
		if(!done[near]) find(near);
	}
}

int main(void)
{
	int i, m, k;
	sf("%d %d %d", &n, &m, &k);
	while(m--) {
		int a, b, x;
		sf("%d %d %d", &a, &b, &x);
		adj[a].push_back(mp(b, x));
		adj[b].push_back(mp(a, x));
	}
	FORS(i, N) path[i] = INF;
	path[1] = 0; udah = 1;
	done[1] = 1;
	find(1);
	
	int ans = 0;
	FOR(i, 1, n) train[i] = inf;
	FORS(i, k) {
		int s, y;
		sf("%d %d", &s, &y);
		if(train[s] != inf)
			ans++;
		train[s] = min(train[s], y);
	}
	FOR(i, 2, n) if(train[i] >= path[i]) {
		if(train[i] != inf)
			ans++;
	}
	cout << ans << endl;
	//FOR(i, 1, n) pf("%I64d ", path[i]); nl;
	return 0;
}
