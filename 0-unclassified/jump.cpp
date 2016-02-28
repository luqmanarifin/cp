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
const double eps = 1e-13;
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

map<int, bool> ada;
int a[N];
bool adax, aday;

int main(void)
{
	int i, j, n, l, x, y;
	sf("%d %d %d %d", &n, &l, &x, &y);
	FORS(i, n) {
		sf("%d", &a[i]);
		ada[a[i]] = 1; 
	}
	FORS(i, n) {
		if(!adax) if(ada[a[i] + x]) adax = 1;
		if(!aday) if(ada[a[i] + y]) aday = 1;
	}
	if(adax && aday) puts("0");
	else if(!adax && aday) pf("1\n%d\n", x);
	else if(adax && !aday) pf("1\n%d\n", y);
	else {
		bool yes = 0;
		FORS(i, n) {
			if(ada[a[i] + x + y]) {
				pf("1\n%d\n", a[i] + x);
				return 0;
			}
			if(ada[a[i] + x - y] && a[i] + x <= l) {
				pf("1\n%d\n", a[i] + x);
				return 0;
			}
			if(ada[a[i] + x - y] && a[i] - y >= 0) {
				pf("1\n%d\n", a[i] - y);
				return 0;
			}
			if(ada[a[i] - x + y] && a[i] - x >= 0) {
				pf("1\n%d\n", a[i] - x);
				return 0;
			}
			if(ada[a[i] - x + y] && a[i] + y <= l) {
				pf("1\n%d\n", a[i] + y);
				return 0;
			}
		}
		pf("2\n%d %d\n", x, y);
	}
	
	return 0;
}
