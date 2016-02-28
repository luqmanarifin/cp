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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[100][100], b[100][100];

int main(void)
{
	int i, j, n;
	sf("%d %d", &n, &n);
	FORS(i, n) FORS(j, n) sf("%d", &a[i][j]);
	sf("%d %d", &n, &n);
	FORS(i, n) FORS(j, n) sf("%d", &b[i][j]);
	
	bool valid = 1;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[i][j]) valid = 0;
	if(valid) {
		puts("0");
		return 0;
	}
	
	valid = 1;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[j][n-1-i]) valid = 0;
	if(valid) {
		puts("90");
		return 0;
	}
	
	valid = 1;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[n-1-i][n-1-j]) valid = 0;
	if(valid) {
		puts("180");
		return 0;
	}
	
	valid = 1;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[n-1-j][i]) valid = 0;
	if(valid) {
		puts("270");
		return 0;
	}
	puts("tidak sama");
	return 0;
}
