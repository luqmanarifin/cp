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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool isEqual(DB a, DB b) {
	return abs(a - b) < eps;
}

int a[10005];

int main(void)
{
	int t, tt, i, j;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int n;
		double ans = inf;
		sf("%d", &n);
		FORS(i, n) sf("%d", &a[i]);
		pair<int, pair<int,int> > jaw = mp(inf, mp(inf, inf));
		sort(a, a + n);
		double med = (DB) n / 4;
		FOR(i, 0, 160) {
			FOR(j, i+1, 160) {
				int bbound = upper_bound(a, a + n, i) - a;
				int cbound = upper_bound(a, a + n, j) - a;
				int mid = (n + cbound)/2;
				int delta;
				FOR(delta, -1, 1) {
					if(mid+delta < 0 || mid+delta >= n) continue;
					int kk = a[mid+delta], dd;
					FOR(dd, -1, 1) {
						int k = kk + dd;
						if(k < 0 || k > 160 || j > k) continue;
						int dbound = upper_bound(a, a + n, k) - a;
						
						int numa = bbound;
						int numb = cbound - bbound;
						int numc = dbound - cbound;
						int numd = n - dbound;
						double cur = abs(med - numa) + abs(med - numb) + abs(med - numc) + abs(med - numd);
						if(isEqual(cur, ans)) {
							ans = cur;
							jaw = min(jaw, mp(i, mp(j, k)));
						} else if(cur < ans) {
							ans = cur;
							jaw = mp(i, mp(j, k));
						}
					}
				}
			}
		}
		//cout << "jawab " << ans << endl;
		pf("Case %d: %d %d %d\n", tt, jaw.first, jaw.second.first, jaw.second.second);
	}
	
	return 0;
}
