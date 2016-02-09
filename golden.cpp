#include <bits/stdc++.h>

/**
 * MemSQL Start[c]UP 2.0 - Round 2 - Online Round
 * Problem : A
 * Luqman Arifin (kadalbonek)
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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 20;
const int lim = 1e5;
const double q = (DB) (sqrt(5) + 1)/2;
const double eps = 1e-12;

char a[N], b[N];
LL aa[N], bb[N];

int main(void)
{
	int i, j;
	sf("%s %s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b);
	reverse(a, a + lena);
	reverse(b, b + lenb);
	FORS(i, max(lena, lenb)) {
		if(i >= lena) a[i] = '0';
		if(i >= lenb) b[i] = '0';
		aa[i] = a[i] - '0';
		bb[i] = b[i] - '0';
	}
	lena = max(lena, lenb);

	FORD(i, lena + 5, 2) {
		if(aa[i] > bb[i] + lim) {
			puts(">");
			return 0;
		}
		if(aa[i] + lim < bb[i]) {
			puts("<");
			return 0;
		}
		int eli = min(aa[i], bb[i]);
		aa[i-1] += aa[i] - eli;
		aa[i-2] += aa[i] - eli;
		bb[i-1] += bb[i] - eli;
		bb[i-2] += bb[i] - eli;
	}
	double ans = q*(aa[1] - bb[1]) + 1.0*(aa[0] - bb[0]);
	if(abs(ans) < eps) puts("=");
	else if(ans > 0) puts(">");
	else puts("<");
	return 0;
}