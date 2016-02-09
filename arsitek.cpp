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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];

int main(void)
{
	int t, n, m, i, j;
	sf("%d", &t);
	while(t--) {
		LL now = 0;
		int ans = 1;
		sf("%d %d", &n, &m);
		FOR(i, 1, n) sf("%d", a + i);
		sort(a + 1, a + 1 + n);
		i = 1, j = 1;
		while(j < n) {
			while(j < n && now + abs(a[j] - a[j+1]) <= m) {
				now += abs(a[j] - a[j+1]);
				j++;
			}
			ans = max(ans, j - i + 1);
			if(i < n) {
				now -= abs(a[i] - a[i+1]);
				i++;
			}
		}
		pf("%d\n", ans);
	}
	return 0;
}
