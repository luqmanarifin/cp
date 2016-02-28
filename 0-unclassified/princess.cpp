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
int lcm(int a, int b) { return a*b / gcd(a, b); }

char a[105][105];

int main(void)
{
	int m, i, j, mx, my, px, py;
	sf("%d", &m);
	sf("%d %d", &mx, &my);
	FORS(i, m) sf("%s", a[i]);
	FORS(i, m)
		FORS(j, m) {
			if(a[i][j] == 'p') {
				px = i;
				py = j;
			}
		}
	int ver = px - mx;
	int hor = py - my;
	if(ver < 0) {
		puts("UP");
		return 0;
	} else if(ver) {
		puts("DOWN");
		return 0;
	}
	if(hor < 0)
		puts("LEFT");
	else
		puts("RIGHT");
	return 0;
}
