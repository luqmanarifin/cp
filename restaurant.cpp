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

double dp[55][55][55];
int a[55];

/*
	dp[a][b][c] (banyak cara / n) artine
	a banyak orang sekarang
	b banyak orang yg masuk restoran
	c panjang meja yg dibutuhkan cuuk
*/

int main(void)
{
	int n, i, j, k, p;
	sf("%d", &n);
	FOR(i,1,n) sf("%d", &a[i]);
	sf("%d", &p);
	
	dp[0][0][0] = 1.0;
	FOR(i,1,n)
		FOR(j,0,i) {
			double temp = j*1.0 / i;
			FOR(k,0,p) {
				dp[i][j][k] = dp[i-1][j][k] * (1 - temp);
				if(a[i] <= k)
					dp[i][j][k] += dp[i-1][j-1][k-a[i]] * temp;
			}
		}
		
	double ans = 0;
	FOR(i,1,n)
		FOR(j,0,p)
			ans += dp[n][i][j];
			
	pf("%.10lf\n", ans);
	
	return 0;
}
