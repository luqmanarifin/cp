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

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		unsigned long long x, y;
		cin >> x >> y;
		if(x % 2 == y % 2) {
			if(x > y) puts("Tere");
			else if(x < y) puts("Toni");
			else puts("Voting Ulang");
		} else {
			if(x && y) {
				if(x-1 > y) puts("Tere");
				else if(x < y-1) puts("Toni");
				else puts("Voting Ulang");
			} else if(x) {
				if(x > 1) puts("Tere");
				else puts("Voting Ulang");
			} else if(y) {
				if(y > 1) puts("Toni");
				else puts("Voting Ulang");
			} else
				puts("Voting Ulang");
		}
	}
	
	return 0;
}