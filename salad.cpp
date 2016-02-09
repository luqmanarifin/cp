#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define tas first
#define kal second

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int dp[105][20005], tas[105], kal[105];
// dp [initial number][balance]
// balance = difference of k*kalori ambek taste 

int main(void)
{
	int i, j, n, k, baru;
	memset(dp,-1,sizeof(dp));
	sf("%d %d", &n, &k);
	FOR(i,1,n) sf("%d", &tas[i]);
	FOR(i,1,n) sf("%d", &kal[i]);
	dp[0][10000] = 0;
	FOR(i,1,n) {
		FOR(j,0,20000) {
			if(dp[i-1][j] != -1) {
				baru = j + tas[i] - k*kal[i];
				dp[i][j] = max(dp[i-1][j], dp[i][j]);
				if(baru >= 0 && baru <= 20000)
					dp[i][baru] = max(dp[i-1][j]+tas[i], dp[i][baru]);
				//pf("%d %d %d\n",i,j,dp[i][j]);
				//pf("%d %d %d\n",i,baru,dp[i][baru]);
			}
		}
	}
	if(dp[n][10000]) cout << dp[n][10000] << endl;
	else puts("-1");
	
	return 0;
}