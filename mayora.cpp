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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int m[N], r[N];
vector<pair<int,int> > ans;

int main(void)
{
	int n, i, j, win = 0;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d %d", &m[i], &r[i]);
		if(m[i] > r[i]) win++;
	}
	int part = n;
	FORS(i, n-1) {
		if(win > part / 2) break;
		if(m[i] <= r[i] && m[i+1] <= r[i+1]) {
			i++;
			part--;
			ans.push_back(mp(i, i + 1));
		} else if(m[i] > r[i] && m[i+1] > r[i+1]) {
		} else if(m[i] + m[i+1] > r[i] + r[i+1]) {
			i++;
			part--;
			ans.push_back(mp(i, i + 1));
		}
	}
	if(win > part / 2) {
		cout << ans.size() << endl;
		FORS(i, ans.size()) pf("%d %d\n", ans[i].first, ans[i].second);
	} else puts("-1");
	
	return 0;
}
