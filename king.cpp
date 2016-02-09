#include <bits/stdc++.h>

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
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	char A, C;
	int a, b, c, d, i;
	sf("%c%d %c%d", &A, &b, &C, &d);
	a = A - 'a' + 1;
	c = C - 'a' + 1;
	pf("%d\n", max(abs(a - c), abs(b - d)));
	if(a != c && b != d) {
		int ping = min(abs(a - c), abs(b - d));
		if(a > c && b > d) {
			FORS(i, ping) puts("LD");
			a -= ping;
			b -= ping;
		} else if(a < c && b > d) {
			FORS(i, ping) puts("RD");
			a += ping;
			b -= ping;
		} else if(a < c && b < d) {
			FORS(i, ping) puts("RU");
			a += ping;
			b += ping;
		} else {
			FORS(i, ping) puts("LU");
			a -= ping;
			b += ping;
		}
	}
	if(a == c) {
		int ping = abs(b - d);
		if(b > d) {
			FORS(i, ping) puts("D");
		} else {
			FORS(i, ping) puts("U");
		}
	} else if(b == d) {
		int ping = abs(a - c);
		if(a > c) {
			FORS(i, ping) puts("L");
		} else {
			FORS(i, ping) puts("R");
		}
	}
	
	return 0;
}
