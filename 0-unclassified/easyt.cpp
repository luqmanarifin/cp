#include <bits/stdc++.h>

/**
 * Codeforces Round #263 (Div. 2)
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[105][105]; 

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FOR(i, 1, n) sf("%s", &s[i][1]);
	FOR(i, 1, n) FOR(j, 1, n) {
		//pf("%d %d %c\n", i, j, s[i][j]);
		int sum = 0;
		if(s[i-1][j] == 'o') sum++;
		if(s[i+1][j] == 'o') sum++;
		if(s[i][j+1] == 'o') sum++;
		if(s[i][j-1] == 'o') sum++;
		//pf("%d\n", sum);
		if(sum & 1) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
