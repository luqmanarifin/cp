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

set<int> ada;
int a[N];
pair<int,int> need[N];

int main(void)
{
	int i, j, n, t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		ada.clear();
		sf("%d", &n);
		int ans = 0;
		FORS(i, n) {
			sf("%d %d %d", a + i, &need[i].first, &need[i].second);
			if(ada.find(a[i]) == ada.end()) {
				ada.insert(a[i]);
				ans++;
			}
		}
		vector<pair<int,int> > ss;
		FORS(i, n) {
			set<int>::iterator it = ada.lower_bound(need[i].first);
			if(it != ada.end() && *it == a[i]) it++;
			if(it == ada.end() || need[i].second < *it) {
				ss.push_back(need[i]);
			}
		}
		sort(ss.begin(), ss.end());
		FORS(i, ss.size()) {
			int c = ss[i].second;
			while(i + 1 < ss.size() && ss[i+1].first <= c) {
				c = min(c, ss[i+1].second);
				i++;
			}
			ans++;
		}
		pf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
