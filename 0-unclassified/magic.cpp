#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for((i) = (a); (i) <= (b); ++(i))
#define FORD(i,a,b) for((i) = (a); (i) >= (b); --(i))
#define FORS(i,n) for((i) = 0; (i) < (n); ++(i))
#define FORM(i,n) for((i) = (n) - 1; (i) >= 0; --(i))
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1e6+5;

int n, dp[N], i, ans = 0, x;

int main(void)
{
	sf("%d", &n);
	memset(dp, 0, sizeof(dp));
	FOR(i,1,n) dp[i] = dp[i-1]^i;
	FOR(i,2,n) {
		if((n/i)%2) ans ^= dp[i-1];
		ans ^= dp[n%i];
	}
	while(n--) {
		sf("%d", &x);
		ans ^= x;
	}
	
	cout << ans << endl;
	
	return 0;
}