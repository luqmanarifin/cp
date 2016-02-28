#include <bits/stdc++.h>

/**
 * Codeforces Round #261 (Div. 2)
 * Problem : E
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
const int N = 3e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> side[N];
int len[N], sorted[N];
pair<int,int> edge[N];

#define x first
#define y second

bool cmp(int a, int b) {
	return edge[a].y < edge[b].y;
}

int dfs(int now, int prev) {
	if(len[now] != -1) return len[now];
	int node = edge[now].x;
	int cost = edge[now].y;
	int l = 0, r = side[node].size(), i, j;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(edge[side[node][mid]].y > cost) r = mid;
		else l = mid + 1;
	}
	len[now] = 0;
	for(i = l; i < side[node].size(); i++) {
		int id = side[node][i];
		len[now] = max(len[now], dfs(id, cost));
	}
	return ++len[now];
}

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i, m) {
		int a, b, w;
		sf("%d %d %d", &a, &b, &w);
		edge[i] = mp(b, w);
		side[a].push_back(i);
		sorted[i] = i;
	}
	reset(len, -1);
	sort(sorted, sorted + m, cmp);
	FOR(i, 1, n) {
		if(side[i].size())
			sort(side[i].begin(), side[i].end(), cmp);
	}
	int ans = -1;
	FORS(i, m) {
		ans = max(ans, dfs(sorted[i], -1));
	}
	cout << ans << endl;
	return 0;
}