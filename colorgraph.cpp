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
const int N = 1e5 + 5;

int par[N];
int last[N];
int id[N];
set<int> memb[N];
vector<int> unit[N];
int num_units;

set<pair<int,int>> udah;
map<pair<int,int>, int> ans;

vector<pair<int,int>> edge[N];

int find(int u) {
	if(par[u] != u) par[u] = find(par[u]);
	return par[u];
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	par[u] = v;
}

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i, m) {
		int u, v, c;
		sf("%d %d %d", &u, &v, &c);
		edge[c].emplace_back(u, v);
	}
	
	FOR(i, 1, m) {
		for(auto it : edge[i]) {
			par[it.first] = it.first;
			par[it.second] = it.second;
		}
		for(auto it : edge[i]) {
			merge(it.first, it.second);
		}
		for(auto it : edge[i]) {
			int u = it.first;
			int v = it.second;
			int root = find(u);
			if(last[root] != i) {
				num_units++;
				id[root] = num_units;
				last[root] = i;
			}
			int id_unit = id[root];
			vector<int> temp {it.first, it.second};
			for(auto node : temp) {
				memb[id_unit].insert(node);
				if(unit[node].empty() || unit[node].back() != id_unit) {
					unit[node].emplace_back(id_unit);
				}
			}
		}
	}
	int q;
	sf("%d", &q);
	while(q--) {
		int u, v;
		sf("%d %d", &u, &v);
		if(unit[u].size() > unit[v].size()) swap(u, v);
		pair<int,int> cur = mp(u, v);
		if(udah.count(cur)) {
			pf("%d\n", ans[cur]);
			continue;
		}
		int jawab = 0;
		for(auto it : unit[u]) jawab += memb[it].count(v);
		pf("%d\n", jawab);
		ans[cur] = jawab;
		udah.insert(cur);
	}
	
	return 0;
}
