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

char s[2005], p[2005];
int first[2005][26];
int last[2005];
set<pair<int,int>> upd[2005];
int ans[2005];

int main(void)
{
	int i, j, n, m;
	FORS(i, 2005) FORS(j, 26) first[i][j] = inf;
	FORS(i, 2005) last[i] = inf;
	
	sf("%s %s", &s[1], &p[1]);
	n = strlen(&s[1]);
	m = strlen(&p[1]);

	FORD(i, n, 1) {
		FORS(j, 26) first[i][j] = first[i+1][j];
		first[i][s[i]-'a'] = i;
	}
	FOR(i, 1, n) {
		int now = i;
		if(s[i] == p[1]) {
			for(j = 1; j <= m && now <= n; j++) {
				now = first[now][p[j]-'a'];
				if(j < m) now++;
			}
			if(now <= n) last[i] = now;
		}
	}
	//FOR(i, 1, n) pf("%d ", last[i]); nl;
	FORS(i, 2005) ans[i] = -1;
	ans[0] = 0;
	FOR(i, 1, n) {
		for(auto it : upd[i]) {
			ans[it.first] = max(ans[it.first], it.second);
		}
		if(last[i] != inf) {
			int dif = last[i] - i + 1 - m;
			FOR(j, dif, n) {
				if(ans[j-dif] != -1) {
					upd[last[i] + 1].insert(mp(j, ans[j-dif] + 1));
				}
			}
		}
	}
	FOR(i, 0, n) pf("%d ", ans[i]); nl;
	
	return 0;
}
