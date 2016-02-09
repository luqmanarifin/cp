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

map<string, int> to;
int cnt[30];

int main(void)
{
	int t;
	cin >> t;
	while(t--) {
		to.clear();
		reset(cnt, 0);
		int n, i, j, tt = 1;
		cin >> n;
		FORS(i, n) {
			string s, junk;
			int v;
			cin >> s >> v >> junk;
			if(to[s] == 0)
				cnt[tt] = v, to[s] = tt++;
			else
				cnt[to[s]] += v;
		}
		sort(cnt + 1, cnt + tt);
		int ans = 0;
		FOR(i, 1, tt - 3) ans += cnt[i];
		pf("%d Juta\n", ans);
	}
	return 0;
}
