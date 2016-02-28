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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool ada[105];

int main(void)
{
	int p, n, i, j;
	sf("%d", &n);
	sf("%d", &p);
	FORS(i, p) {
		int a;
		sf("%d", &a);
		ada[a] = 1;
	}
	sf("%d", &p);
	FORS(i, p) {
		int a;
		sf("%d", &a);
		ada[a] = 1;
	}
	bool valid = 1;
	FOR(i, 1, n) if(!ada[i]) valid = 0;
	puts(valid? "I become the guy." : "Oh, my keyboard!");
	return 0;
}
