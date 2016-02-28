#include <bits/stdc++.h>

#define LL int
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

#define open freopen("out.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 505 * 505;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int par[N];
vector<pair<LL, pair<int,int> > > edge;
int a[505][505];

int find(int u) {
	if(par[u] != u) par[u] = find(par[u]);
	return par[u];
}

void merge(int u, int v) {
	int root = find(v);
	par[root] = u;
}

int main(void)
{
	//open;
	int n, m, k, i, j;
	sf("%d %d %d", &n, &m, &k);
	FOR(i, 1, n) FOR(j, 1, m) sf("%d", &a[i][j]);
	FOR(i, 1, n/2) FOR(j, 1, m/2) {
		int id = (i - 1)*m/2 + j;
		int near;
		LL cost;
		if(i < n/2) {
			near = (i)*m/2 + j;
			cost = a[i*2][j*2] + a[i*2][j*2-1];
			cost += a[i*2 + 1][j*2] + a[i*2 + 1][j*2-1];
			edge.push_back(mp(cost, mp(near, id)));
		}
		if(j < m/2) {
			near = (i - 1)*m/2 + j + 1;
			cost = a[i*2][j*2] + a[i*2-1][j*2];
			cost += a[i*2][j*2 + 1] + a[i*2-1][j*2 + 1];
			edge.push_back(mp(cost, mp(near, id)));
		}
	}
	sort(edge.begin(), edge.end());
	vector<LL> temp;
	LL ans = 0;
	
	FORS(i, N) par[i] = i;
	FORS(i, edge.size()) {
		int u = edge[i].second.first;
		int v = edge[i].second.second;
		LL cost = edge[i].first;
		if(find(u) != find(v)) {
			ans += cost;
			temp.push_back(cost);
			merge(u, v);
			//pf("%d %d %I64d\n", u, v, cost);
		}
	}
	//pf("%d %d\n", n*m/4, temp.size());
	sort(temp.begin(), temp.end());
	reverse(temp.begin(), temp.end());
	FORS(i, k-1) {
		ans -= temp[i];
	}
	cout << ans << endl;
	//close;
	return 0;
}
