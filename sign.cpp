#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const int inf = 1e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	int n, k, i, ans = 0, absMinimum = inf;
	sf("%d %d", &n, &k);
	while(n--) {
		int x;
		sf("%d", &x);
		absMinimum = min(absMinimum, abs(x));
		if(k && x < 0) {
			k--;
			ans += -x;
		}
		else ans += x;
	}
	if(k&1) ans -= 2*absMinimum;
	pf("%d\n", ans);
	return 0;
}
