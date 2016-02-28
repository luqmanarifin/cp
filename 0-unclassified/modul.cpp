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
const int N = 2e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int at[N], a;

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	while(n--) {
		sf("%d", &a);
		at[a] = a;
	}
	FOR(i, 1, N-1) if(at[i] == 0) at[i] = at[i-1];
	int ans = 0;
	FOR(i, 2, 1000000) if(at[i] == i) {
		for(j = 2*i - 1; j < N; j += i) {
			ans = max(ans, at[j] % at[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
