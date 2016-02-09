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

int xmax, xmin, ymax, ymin;

bool cek(int x, int y) {
	return xmin <= x && x <= xmax && ymin <= y && y <= ymax;
}

int main(void)
{
	int xg, yg, tg, lg, xb, yb, tb, lb;
	sf("%d %d %d %d %d %d %d %d", &xg, &yg, &tg, &lg, &xb, &yb, &tb, &lb);
	xmin = xb;
	xmax = xb + lb;
	ymax = yb;
	ymin = yb - tb;
	int i, j;
	FOR(i, 0, lg) FOR(j, 0, tg) {
		int xn = xg + i;
		int yn = yg - j;
		if(cek(xn, yn)) {
			puts("Tidak aman!");
			pf("%d %d\n", xn, yn);
			return 0;
		}
	}
	puts("Aman!");
	return 0;
}
