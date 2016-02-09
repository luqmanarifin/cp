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

int last[N];
LL path[N];
pair<int, LL> edge[7*N];
	// edge nyimpen jalan antar kota pake id
	// id gede berarti jalan punya rel kereta, otherwise punya daratan
vector<int> adj[N];
set<pair<LL, int> > s;

void find(int pos) {
	//pf("%d\n", pos);
	LL cost = path[pos];
	int i, j;
	FORS(i, adj[pos].size()) {
		int id = adj[pos][i];
		int near = edge[id].first;
		LL len = edge[id].second;
		if(cost + len < path[near]) {
			path[near] = cost + len;
			last[near] = id;
			s.insert(mp(path[near], near));
		} else if(cost + len == path[near])
			last[near] = min(last[near], id);
	}
	
	pair<LL, int> next;
	if(!s.empty())
		next = *s.begin();
	//pf("%d %d\n", pos, next.second);
	while(!s.empty() && next.first > path[next.second]) {
		s.erase(s.begin());
		if(s.empty()) break;
		next = *s.begin();
		//pf("%d %d\n", pos, next.second);
	}
	if(!s.empty()) {
		s.erase(s.begin());
		find(next.second);
	}
}

int main(void)
{
	int n, m, k, i, j;
	sf("%d %d %d", &n, &m, &k);
	int id = 0;
	while(m--) {
		int a, b, x;
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
		int a, x;
		sf("%d %d", &a, &x);
		edge[id] = mp(a, x);
		adj[1].push_back(id);
		id++;
	}
	FOR(i, 1, n) path[i] = INF, last[i] = inf;
	path[1] = 0;
	find(1);
	
	int trainShortest = 0;
	FOR(i, 2, n) if(last[i] >= lim) ++trainShortest;
	cout << k - trainShortest << endl;
	//FOR(i, 1, n) pf("%I64d ", path[i]); nl;
	//FOR(i, 1, n) pf("%d ", adj[i].size()); nl;
	return 0;
}
