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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int now, a[int(1e5 + 5)], ans;

int main(void)
{
	int i, j = 0, n, t;
	sf("%d %d", &n, &t);
	FORS(i, n) sf("%d", a + i);
	FORS(i, n) {
		if(i) now -= a[i-1];
		if(j < i) {
			j = i;
			now = 0;
		}
		while(now + a[j] <= t && j < n) {
			now += a[j];
			j++;
		}
		ans = max(ans, j - i);
	}
	cout << ans << endl;
	return 0;
}
