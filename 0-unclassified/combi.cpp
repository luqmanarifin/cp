#include <bits/stdc++.h>

/**
 * Codeforces Round #283 (Div. 2)
 * Problem : B
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
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

using namespace std;

const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[1005];
int n;

bool kurang(int a, int b) {
	int i;
	int ca = (10 - s[a]) % 10;
	int cb = (10 - s[b]) % 10;
	FORS(i, n) {
		if((s[(i + a)%n] + ca) % 10 < (s[(i + b)%n] + cb) % 10)
			return 1;
		if((s[(i + a)%n] + ca) % 10 > (s[(i + b)%n] + cb) % 10)
			return 0;
	}	
	return 0;
}

int main(void)
{
	int i, j;
	sf("%d %s", &n, s);
	//n = strlen(s);
	FORS(i, n) s[i] -= '0';
	int pos = 0;
	FOR(i, 1, n-1) {
		if(kurang(i, pos))
			pos = i;
	}
	int c = (10 - s[pos]) % 10;
	FORS(i, n) pf("%d", (s[(i + pos)%n] + c) % 10); nl;
	return 0;
}
