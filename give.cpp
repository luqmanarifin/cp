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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int cnt[10005];

int main(void)
{
	int tt, t, i, j, n, m, c;
	sf("%d", &t);
	FOR(tt, 1, t) {
		reset(cnt, 0);
		sf("%d %d %d", &m, &n, &c);
		FORS(i, m) {
			int a;
			sf("%d", &a);
			cnt[a]++;
		}
		vector<pair<int,int> > num; 
		// number of goods and which type cuk
		FOR(i, 1, n) {
			if(cnt[i])
				num.push_back(mp(cnt[i], i));
		}
		sort(num.begin(), num.end());
		reverse(num.begin(), num.end());
		LL now = 0, bef = inf, ans = 0;
		FORS(i, num.size()) {
			int type = num[i].second;
			int muncul = num[i].first;
			now += (type*type) % c;
			bef = min(bef, (LL) muncul);
			ans = max(ans, now*bef);
		}
		pf("Case %d: %I64d\n", tt, ans);
	}
	
	return 0;
}
