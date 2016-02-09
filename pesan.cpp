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

bool done[26];

int main(void)
{
	char junk[25], s[(int) 1e5 + 5];
	sf("%s", junk);
	int n, q;
	sf("%d %d", &n, &q);
	sf("%s", s);
	while(q--) {
		int l, r;
		int i, now = 0;
		sf("%d %d", &l, &r);
		l--, r--;
		reset(done, 0);
		char ans[(int) 1e5 + 5];
		FOR(i, l, r) {
			if(i == l || s[i] != s[i-1])
				ans[now++] = s[i];
		}
		pf("%d", now);
		if(now < 10) {
			pf(" ");
			FORS(i, now) pf("%c", ans[i]);
		}
		nl;
	}
	
	return 0;
}
