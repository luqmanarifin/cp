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

multiset<int> ada;
int a[N];
// begin, end, index
pair<pair<int,int>,int> need[N];

bool available(int b, int c, int i) {
	multiset<int>::iterator it = ada.lower_bound(b);
	if(it != ada.end() && *it == a[i]) {
		it++;
	}
	return it != ada.end() && *it <= c;
}

int main(void)
{
	int t, i, j, tt, n;
	sf("%d", &t);
	FOR(tt, 1, t) {
		ada.clear();
		int ans = 0;
		sf("%d", &n);
		FORS(i, n) {
			sf("%d %d %d", &a[i], &need[i].x.x, &need[i].x.y);
			need[i].y = i;
			if(ada.find(a[i]) == ada.end()) {
				ans++;
				ada.insert(a[i]);
			}
		}
		//cout << ans << endl;
		sort(need, need + n);
		FORS(i, n) {
			if(!available(need[i].x.x, need[i].x.y, need[i].y)) {
				ans++;
				int c = need[i].x.y;
				while(i + 1 < n && need[i+1].x.x <= c) {
					if(!available(need[i+1].x.x, need[i+1].x.y, need[i+1].y)) {
						c = min(c, need[i+1].x.y);
					}
					i++;
				}
				ada.insert(c);
			}
		}
		pf("Case #%d: %d\n", tt, ans);
	}	
	
	return 0;
}
