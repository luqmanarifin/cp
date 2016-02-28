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
const int N = 1e4 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n[5], t[5], need[5], dp[N][5];

int main(void)
{
	int k, i, j;
	sf("%d", &k);
	FOR(i, 1, 3) sf("%d", n + i);
	FOR(i, 1, 3) {
		sf("%d", t + i);
	}
	FORD(i, 3, 1) {
		need[i] = need[i+1] + t[i];
	}
	FOR(i, 1, k) {
		int last[5];
		FOR(j, 1, 3) {
			last[j] = (i > n[j]? dp[i-n[j]][j] : 0);
			last[j] += need[j];
		}
		int pos, now = -1;
		FOR(j, 1, 3) {
			if(last[j] > now) {
				now = last[j];
				pos = j;
			}
		}
		FOR(j, 1, 3)
			dp[i][j] = now - need[j+1];
	}
	pf("%d\n", dp[k][3]);
	return 0;
}
