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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int good[N], a[N];

int main(void)
{
	int n, i;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", a + i);
		a[n + i] = a[i];
	}
	FOR(i, 1, 2*n - 1) {
		if(a[i-1] <= a[i]) good[i]++;
		good[i] += good[i-1];
	}
	int ans = -1;
	FORS(i, n)
		if(good[i+n-1] - good[i] == n-1) {
			ans = (n - i) % n;
			if(ans == 0) break;
		}
	
	cout << ans << endl;
	return 0;
}
