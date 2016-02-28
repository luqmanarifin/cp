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
#define open freopen("42.in","r",stdin); freopen("42.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	open;
	int t;
	sf("%d", &t);
	while(t--) {
		char s[10];
		sf("%s", s);
		int n = strlen(s), i;
		bool ongko = 0;
		FORM(i, n) {
			if(s[i] != '0') ongko = 1;
			if(!ongko && s[i] == '0') continue;
			putchar(s[i]);
		}
		nl;
	}
	close;
	return 0;
}
