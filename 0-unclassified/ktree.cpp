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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const int mod = 1e9 + 7;
const int inf = -mod; 

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int dp[105][2], n, k, d;

int main(int argc, char ** argv)
{
	sf("%d %d %d", &n, &k, &d);
	int i, j;
	dp[0][1] = 1;
	FOR(i,1,n)
		FOR(j,1, min(i,k)) {
			dp[i][0] = (dp[i][0] + dp[i-j][j >= d]) % mod;
			dp[i][1] = (dp[i][1] + dp[i-j][1]) % mod;
		}
	
	cout << dp[n][0] << endl;
	return 0;
}
