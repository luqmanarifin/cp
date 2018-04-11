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
	char s[205]; bool next = 0;
	while(cin >> s) {
		int n = strlen(s), i, cuk = 1;
		FORS(i, n)
			if(s[i] != s[n-1-i]) {
				cuk = 0;
				break;
			}
		if(cuk) {
			if(next) pf(" ");
			pf("%s", s);
			next = 1;
		}
	}	
	nl; return 0;
}
