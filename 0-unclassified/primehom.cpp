#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e7 + 5;

vector<int> num[10];
char city[N];

int main(void)
{
	int i, j;
	FOR(i, 2, N-1) {
		if(!city[i]) {
			for(j = i; j < N; j += i) {
				city[j]++;
			}
		}
	}
	FOR(i, 2, N - 5) num[city[i]].emplace_back(i);
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int a, b, k;
		sf("%d %d %d", &a, &b, &k);
		pf("Case #%d: ", tt);
		if(k > 8) {
			puts("0");
			continue;
		}
		int upp = upper_bound(num[k].begin(), num[k].end(), b) - num[k].begin();
		int low = lower_bound(num[k].begin(), num[k].end(), a) - num[k].begin();
		pf("%d\n", upp - low);
	}
	return 0;
}
