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

int a[3005];
vector<pair<int,int> > ans;

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", &a[i]);
	}
	FORS(i, n) {
		int now = inf, pos = -1;
		FOR(j, i, n-1) {
			if(a[j] < now) {
				now = a[j];
				pos = j;
			}
		}
		ans.push_back(mp(i, pos));
		swap(a[i], a[pos]);
	}
	cout << ans.size() << endl;
	FORS(i, ans.size()) pf("%d %d\n", ans[i].first, ans[i].second);
	
	return 0;
}
