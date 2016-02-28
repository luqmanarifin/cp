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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL path[N];
int prev[N];
vector<pair<int,int> > edge[N];

void print(int a) {
	if(a == 0) return;
	print(prev[a]);
	pf("%d ", a);
}

int main(void)
{
	int i, j, n, m;
	FORS(i, N) path[i] = INF;
	sf("%d %d", &n, &m);
	while(m--) {
		int a, b, c;
		sf("%d %d %d", &a, &b, &c);
		edge[a].push_back(mp(b, c));
		edge[b].push_back(mp(a, c));
	}
	priority_queue<pair<LL, int> > pq;
	path[1] = 0;
	pq.push(mp(0, 1));
	while(!pq.empty()) {
		int now = pq.top().second;
		LL cost = -pq.top().first;
		pq.pop();
		if(cost != path[now]) continue;
		FORS(i, edge[now].size()) {
			int near = edge[now][i].first;
			int ncos = edge[now][i].second;
			if(path[now] + ncos < path[near]) {
				path[near] = path[now] + ncos;
				prev[near] = now;
				pq.push(mp(-path[near], near));
			}
		}
	}
	if(path[n] == INF) puts("-1");
	else { 
		print(n); nl;
	}
	
	return 0;
}
