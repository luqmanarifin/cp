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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	char s[15];
	sf("%s", s);
	int n = strlen(s), i;
	FORM(i, n) {
		switch(s[i]) {
			case '0' : puts("O-|-OOOO"); break;
			case '1' : puts("O-|O-OOO"); break;
			case '2' : puts("O-|OO-OO"); break;
			case '3' : puts("O-|OOO-O"); break;
			case '4' : puts("O-|OOOO-"); break;
			case '5' : puts("-O|-OOOO"); break;
			case '6' : puts("-O|O-OOO"); break;
			case '7' : puts("-O|OO-OO"); break;
			case '8' : puts("-O|OOO-O"); break;
			case '9' : puts("-O|OOOO-"); break;
		}
	}
	
	return 0;
}
