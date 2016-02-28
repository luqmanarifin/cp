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

int main(void)
{
	int a, b, c, d, e, f, g, h, i, x;
	sf("%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
	bool tukar = 0;
	if(!c) {
		swap(a,c);
		swap(g,i);
		tukar++;
	}
	FOR(x, 3, 300000) {
		a = x - b - c;
		e = x - d - f;
		i = x - g - h;
		bool q = a + d + g == b + e + h;
		bool w = c + f + i == a + e + i;
		bool v = a + e + i == g + e + c;
		bool r = b + e + h == c + f + i;
		bool t = a > 0 && e > 0 && i > 0;
		if(q && w && v && r && t) {
			if(tukar) {
				swap(a,c);
				swap(g,i);
			}
			pf("%d %d %d\n%d %d %d\n%d %d %d\n",a,b,c,d,e,f,g,h,i);
			return 0;
		}
	}
	
	return 0;
}