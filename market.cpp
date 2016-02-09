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

int n, d, a[55], ans;
bool done[55];
LL day;

int main(void)
{
	int i, j, will = 1;
	sf("%d %d", &n, &d);
	FORS(i, n) sf("%d", a + i);
	sort(a, a + n);
	reverse(a, a + n);
	while(will) {
		will = 0;
		FORS(i, n) {
			if(will + a[i] <= d && !done[i]) {
				done[i] = 1;
				will += a[i];
				ans += a[i];
			}
		}
		if(!will) {
			FORS(i, n) {
				if(will + a[i] <= ans + d && !done[i]) {
					done[i] = 1;
					will += a[i];
					ans += a[i];
				}
			}
			if(will) day *= 2LL;
		}
		if(will) day++;
	}
	pf("%d %I64d\n", ans, day);
	return 0;
}
