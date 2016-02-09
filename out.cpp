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

const LL mod = 1e9 + 7;
const int N = 1005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int m, n, asal[N][N];
int a[N][N], b[N][N], c[N][N], d[N][N];
LL ans = 0;

void generate() {
	int i, j;
	FORS(i,n) FORS(j,m)
		a[i][j] = max(a[i][j-1], a[i-1][j]) + asal[i][j];
	
	FORS(i,n) FORM(j,m)
		b[i][j] = max(b[i-1][j], b[i][j+1]) + asal[i][j];
	
	FORM(i,n) FORS(j,m)
		c[i][j] = max(c[i+1][j], c[i][j-1]) + asal[i][j];
	
	FORM(i,n) FORM(j,m)
		d[i][j] = max(d[i][j+1], d[i+1][j]) + asal[i][j];
}

int main(void)
{
	sf("%d %d", &n, &m); int i, j;
	FORS(i,n) FORS(j,m) sf("%d", &asal[i][j]);
	reset(a,0); reset(b,0); reset(c,0); reset(d,0);
	generate();
	
	FOR(i,1,n-2) FOR(j,1,m-2) {
		LL cur = 0LL + a[i-1][j] + d[i+1][j] + b[i][j+1] + c[i][j-1];
		LL cuh = 0LL + a[i][j-1] + d[i][j+1] + b[i-1][j] + c[i+1][j];
		ans = max(ans, max(cur, cuh));
	}
	
	cout << ans << endl;
	return 0;
}
