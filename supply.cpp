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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int next[1005], prev[1005], water[1005];
vector<pair<int, pair<int,int> > > ans;

#define x first
#define y second

pair<int, int> dfs(int now) {
	if(!next[now]) return mp(now, water[now]);
	pair<int,int> temp = dfs(next[now]);
	if(water[now] < temp.y)
		temp = mp(temp.x, water[now]);
	return temp;
}

int main(void)
{
	int n, p, i; sf("%d %d", &n, &p);
	while(p--) {
		int a, b, w;
		sf("%d %d %d", &a, &b, &w);
		next[a] = b;
		prev[b] = a;
		water[b] = w;
	}
	
	FOR(i,1,n)
		if(!prev[i] && next[i]) {
			pair<int,int> cur = dfs(next[i]);
			ans.push_back(mp(i, mp(cur.x, cur.y)));
		}
	
	cout << ans.size() << endl;
	if(ans.size())
		FORS(i, ans.size())
			pf("%d %d %d\n", ans[i].x, ans[i].y.x, ans[i].y.y);
	
	return 0;
}
