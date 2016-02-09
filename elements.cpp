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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n;
int a[105][105];
bool ok[105][105];

int main(void)
{
	//open;
	int i, j, n;
	sf("%d", &n);
	FORS(i, n) FORS(j, n) {
		sf("%d", &a[i][j]);
	}
	FORS(i, n) ok[i][i] = 1;
	FORS(i, n) ok[i][n-1-i] = 1;
	FORS(i, n) ok[i][n/2] = 1;
	FORS(i, n) ok[n/2][i] = 1;
	int ans = 0;
	FORS(i, n) FORS(j, n) if(ok[i][j]) ans += a[i][j];
	cout << ans << endl;
	
	
	//close;
	return 0;
}
