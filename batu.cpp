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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n;
bool done[2][2000];
char s[2][2000];

int dfs(int a, int b) {
	if(a > 1 || a < 0 || b >= n || done[a][b] || s[a][b] == '0') return 0;
	done[a][b] = 1;
	int ret = 1;
	ret += dfs(a, b + 1);
	ret += dfs(a + 1, b);
	ret += dfs(a - 1, b);
	ret += dfs(a + 1, b + 1);
	ret += dfs(a - 1, b + 1);
	return ret;
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		reset(done, 0);
		int i, j;
		sf("%d", &n);
		FORS(i, 2) sf("%s", s[i]);
		int ans = 0;
		FORS(j, n) FORS(i, 2) {
			int temp = dfs(i, j);
			ans += temp/2 + (temp & 1);
		}
		pf("%d\n", ans);
	}
	return 0;
}
