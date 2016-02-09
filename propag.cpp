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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dad[N], op[N], a[N];
vector<int> edge[N];

void build(int now) {
	int i;
	if(edge[now].size())
	FORS(i, edge[now].size()) {
		int near = edge[now][i];
		if(near == dad[now]) continue;
		dad[near] = now;
		build(near);
	}
}

int find(int now, int id) {
	int temp = op[now];
	if(id & 1) temp *= -1;
	return temp + (now == 1? 0 : find(dad[now], id ^ 1));
}

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%d", a + i);
	FORS(i, n-1) {
		int a, b;
		sf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	build(1);
	while(m--) {
		int type, x, val;
		sf("%d %d", &type, &x);
		if(type == 1) {
			sf("%d", &val);
			op[x] += val;
		} else
			pf("%d\n", find(x, 0) + a[x]);
	}
	return 0;
}
