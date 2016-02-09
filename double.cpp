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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define x first
#define y second

set<int> ada;
pair<int, int> need[N];

int available(int a, int b) {
	set<int>::iterator it = ada.lower_bound(a);
	return it != ada.end() && *it <= b;
}

int main(void)
{
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		ada.clear();
		int ans = 0;
		int n, i, j;
		sf("%d", &n);
		FORS(i, n) {
			int a, b, c;
			sf("%d %d %d", &a, &b, &c);
			need[i] = mp(b, c);
			if(!available(a, a)) {
				ans++;
				ada.insert(a);
			}
		}
		sort(need, need + n);
		FORS(i, n) {
			int b = need[i].x;
			int c = need[i].y;
			if(!available(b, c)) {
				ans++;
				while(i + 1 < n && need[i+1].x <= c) {
					c = min(c, need[i+1].y);
					i++;
				}
			}
		}
		pf("Case #%d: %d\n", tt, ans);
	}
	
	return 0;
}
