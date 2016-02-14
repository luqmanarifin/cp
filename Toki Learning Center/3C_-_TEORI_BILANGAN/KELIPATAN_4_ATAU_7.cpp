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
	int t;
	sf("%d", &t);
	while(t--) {
		int n; sf("%d", &n);
		int dua = n / 28;
		int empat = n / 4;
		int tujuh = n / 7;
		LL Dua = 1LL*dua*(28 + dua*28)/2;
		LL Empat = 1LL*empat*(4 + empat*4)/2;
		LL Tujuh = 1LL*tujuh*(7 + tujuh*7)/2;
		cout << Empat + Tujuh - Dua << endl;
	}
	
	return 0;
}
