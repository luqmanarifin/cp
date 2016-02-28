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

int main(void)
{
	int n, i, cnt = 0;
	sf("%d", &n);
	if(n < 4) {
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n & 1) {
		puts("4 * 5 = 20");
		puts("2 - 1 = 1");
		puts("3 + 1 = 4");
		puts("20 + 4 = 24");
		if(n > 5) {
			for(i = 6; i <= n; i += 2) {
				pf("%d - %d = 1\n", i + 1, i);
				cnt++;
			}
			FORS(i, n - 6 - cnt) puts("1 * 1 = 1");
			puts("24 * 1 = 24");
		}
	} else {
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		puts("24 * 1 = 24");
		if(n > 4) {
			for(i = 6; i <= n; i += 2) {
				pf("%d - %d = 1\n", i, i - 1);
				cnt++;
			}
			FORS(i, n - 5 - cnt) puts("1 * 1 = 1");
			puts("24 * 1 = 24");
		}
	}
	return 0;
}
