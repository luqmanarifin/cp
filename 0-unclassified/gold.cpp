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
const int N = 1e5 + 5;

char a[N], b[N];

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
	}
	FORD(i, max(lena, lenb), 0) {
		if(a[i] == '1' && b[i] == '1') continue;
		if(i > 1 && a[i] == '1' && b[i-1] == '1' && b[i-2] == '1') {
			b[i-1] = '0';
			b[i-2] = '0';
			continue;
		}
		if(i > 1 && b[i] == '1' && a[i-1] == '1' && a[i-2] == '1') {
			a[i-1] = '0';
			a[i-2] = '0';
			continue;
		}
		if(a[i] == '1') {
			puts(">");
			return 0;
		}
		if(b[i] == '1') {
			puts("<");
			return 0;
		}
	}
	puts("=");
	return 0;
}