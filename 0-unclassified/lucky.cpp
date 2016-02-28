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
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, k, ans;

void solve(int a) {
	int temp = 0, i;
	FOR(i,1,9) {
		if(a%10 == 7 || a%10 == 4)
			temp++;
		a /= 10;
	}
	if(temp <= k) ans++;
}

int main(void)
{
	int i, a;
	sf("%d %d", &n, &k);
	FOR(i,1,n) {
		sf("%d", &a);
		solve(a);
	}
	pf("%d\n", ans);
	return 0;
}
