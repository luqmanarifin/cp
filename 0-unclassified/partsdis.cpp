#include <bits/stdc++.h>

/**
 * Codeforces Round #283 (Div. 2)
 * Problem : E
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define nl printf("\n")
#define mp make_pair

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

// begin, cap, end, index
vector<pair<pair<int,int>, pair<int,int> > > item;
// end, cap, index
set<pair<pair<int,int>, int> > actor;
int ans[N];

int main(void)
{
	int i, j, n, m;
	sf("%d", &n);
	FORS(i, n) {
		int a, b;
		sf("%d %d", &a, &b);
		item.push_back(mp(mp(a, inf), mp(b, i)));
	}
	sf("%d", &m);
	FORS(i, m) {
		int a, b, c;
		sf("%d %d %d", &a, &b, &c);
		item.push_back(mp(mp(a, c), mp(b, i)));
	}
	sort(item.begin(), item.end());
	FORS(i, item.size()) {
		if(item[i].x.y == inf) {
			pair<pair<int,int>, int> cari = mp(mp(item[i].y.x, 0), 0);
			set<pair<pair<int,int>, int> >::iterator it = actor.lower_bound(cari);
			if(it == actor.end()) {
				puts("NO");
				return 0;
			}
			ans[item[i].y.y] = it->y;
			pair<pair<int,int>, int> newActor = *it;
			actor.erase(it);
			newActor.x.y--;
			if(newActor.x.y > 0) {
				actor.insert(newActor);
			}
		} else {
			actor.insert(mp(mp(item[i].y.x, item[i].x.y),  item[i].y.y));
		}
	}
	puts("YES");
	FORS(i, n) pf("%d ", ans[i] + 1); nl;
	return 0;
}
