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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int at[1005], done[1005];

int main(void)
{
	int n, m, k, i;
	sf("%d %d %d", &n, &m, &k);
	while(n--) {
		int a, c;
		sf("%d %d", &a, &c);
		if(done[a]) at[a] = min(at[a], c);
		else at[a] = c, done[a] = 1;
	}
	int ans = 0;
	FOR(i, 1, m) ans += at[i];
	cout << min(ans, k) << endl;
	return 0;
}
