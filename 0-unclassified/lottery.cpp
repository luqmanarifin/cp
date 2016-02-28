#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("B-small-practice.in","r",stdin); freopen("B-small-practice.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9+7;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int a, b, k, t, i, j, l;

int main(void)
{
	open;
	
	sf("%d", &t);
	FOR(i,1,t) {
		sf("%d %d %d", &a, &b, &k);
		int ans = 0;
		FORS(j,a)
			FORS(l,b)
				if((j & l) < k)
					ans++;
		pf("Case #%d: %d",i,ans); nl;
	}
	
	close;
	return 0;
}