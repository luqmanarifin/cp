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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[80][80], b[80][80];

int main(void)
{
	int n, i, j;
	sf("%d %d", &n, &n);
	FORS(i, n) FORS(j, n) sf("%d", &a[i][j]);
	sf("%d %d", &n, &n);
	FORS(i, n) FORS(j, n) sf("%d", &b[i][j]);
	bool yo = 1;
	FORS(i, n) FORS(j, n) if(yo && a[i][j] != b[i][j]) {
		yo = 0;
		break;
	}
	if(yo) {
		puts("identik");
		return 0;
	}
	
	yo = 1;
	FORS(i, n) FORS(j, n) if(yo && a[i][j] != b[n-i-1][j]) {
		yo = 0;
		break;
	}
	if(yo) {
		puts("horisontal");
		return 0;
	}
	
	yo = 1;
	FORS(i, n) FORS(j, n) if(yo && a[i][j] != b[i][n-1-j]) {
		yo = 0;
		break;
	}
	if(yo) {
		puts("vertikal");
		return 0;
	}
	
	yo = 1;
	FORS(i, n) FORS(j, n) if(yo && a[i][j] != b[n-1-j][n-1-i]) {
		yo = 0;
		break;
	}
	if(yo) {
		puts("diagonal kiri bawah");
		return 0;
	}
	
	yo = 1;
	FORS(i, n) FORS(j, n) if(yo && a[i][j] != b[j][i]) {
		yo = 0;
		break;
	}
	if(yo) puts("diagonal kanan bawah");
	else puts("tidak identik");
	return 0;
}
