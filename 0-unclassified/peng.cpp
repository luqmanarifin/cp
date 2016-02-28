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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[N];

int main(void)
{
	int n, m, i, d;
	sf("%d %d %d", &n, &m, &d);
	n *= m;
	FORS(i, n) {
		sf("%d", a + i);
		if(i && a[i] % d != a[i-1] % d) {
			puts("-1");
			return 0;
		}
	}
	sort(a, a + n);
	int mid = a[n/2], ans = 0;
	FORS(i, n) {
		ans += abs(a[i] - mid)/d;
	}
	cout << ans << endl;
	return 0;
}
