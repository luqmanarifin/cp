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

int a[105];
bool done[105];
vector<int> ans[3];

int main(void)
{
	int n, i, j, k;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	FORS(i, n) if(a[i] < 0) {
		ans[0].push_back(a[i]);
		done[i] = 1;
		break;
	}
	FORS(i, n) if(a[i] > 0 && !done[i]) {
		ans[1].push_back(a[i]);
		done[i] = 1;
		break;
	}
	if(ans[1].empty()) {
		int need = 2;
		FORS(i, n) if(need && a[i] < 0 && !done[i]) {
			ans[1].push_back(a[i]);
			done[i] = 1;
			need--;
		}
	}
	FORS(i, n) if(!done[i]) ans[2].push_back(a[i]);
	FORS(i, 3) {
		pf("%d ", ans[i].size());
		FORS(j, ans[i].size()) pf("%d ", ans[i][j]);
		nl;
	}
	return 0;
}
