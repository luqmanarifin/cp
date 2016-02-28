#include <bits/stdc++.h>

/**
 * Codeforces Round #270
 * Problem : C
 * Luqman A. Siswanto (kadalbonek)
 */

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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

string a[N][2];
int p[N], n, memo[N][2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i, j;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i][0] >> a[i][1];
	}
	FORS(i, n) cin >> p[i];
	
	memo[0][0] = memo[0][1] = 1;
	FOR(i, 1, n-1) FORS(j, 2) {
		if(a[p[i-1]][0] < a[p[i]][j])
			memo[i][j] = (memo[i][j] || memo[i-1][0]);
		if(a[p[i-1]][1] < a[p[i]][j])
			memo[i][j] = (memo[i][j] || memo[i-1][1]);
		//pf("memo %d %d : %d\n", i, j, memo[i][j]);
	}
	puts(memo[n-1][0] || memo[n-1][1]? "YES" : "NO");
	return 0;
}
