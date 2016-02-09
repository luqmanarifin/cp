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

int f[N], dp[N][3], k;

int get(int at) {
	return f[at] - f[max(0, at - k)];
}

int main(void)
{
	int n, i, j;
	sf("%d %d", &n, &k);
   FOR(i, 1, n) {
      sf("%d", &f[i]);
      f[i] += f[i-1];
   }
   int ans = -1;
	FOR(i, 1, n) {
		FOR(j, 1, 2) {
			int prev = max(0, i - k);
			dp[i][j] = max(dp[i-1][j], dp[prev][j-1] + get(i));
		}
	}
   cout << dp[n][2] << endl;
   return 0;
}