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
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int main(void)
{
	int t, tt;
	cin >> t;
	FOR(tt, 1, t) {
		string s, mini, maxi;
		cin >> s;
		mini = maxi = s;
		int i, j, n = s.length();
		FORS(i, n) FOR(j, i + 1, n - 1) {
			swap(s[i], s[j]);
			if(s[0] == '0' && n > 1) {
				swap(s[i], s[j]);
				continue;
			}
			mini = min(mini, s);
			maxi = max(maxi, s);
			swap(s[i], s[j]);
		}
		pf("Case #%d: %s %s\n", tt, mini.c_str(), maxi.c_str());
	}
	
	return 0;
}
