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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	int a, i, j, n;
	cin >> n;
	while(n--) {
		cin >> a;
		int fak = 0;
		for(i = 1; i*i <= a; i++) {
			if(a % i == 0) {
				fak++;
				if(a != 1 && i*i != a)
					fak++;
			}
		}
		if(fak > 4) puts("TIDAK");
		else puts("YA");
	}
	
	return 0;
}
