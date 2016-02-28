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

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int c, d, n, m, k, i, j, ans = 10000;
	sf("%d %d %d %d %d", &c, &d, &n, &m, &k);
	FOR(i,0,10000)
		FOR(j,0,10000)
			if(i*n + j >= n*m - k)
				ans = min(ans, i*c + j*d);
	cout << ans << endl;
	
	return 0;
}