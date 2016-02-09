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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char a[10];

int main(void)
{
	int i, n;
	int ans = -1;
	sf("%s", a);
	n = strlen(a);
	FORS(i, n) a[i] -= '0';
	int fact = 1;
	FOR(i, 1, n) fact *= i;
	while(fact--) {
		int num = 0;
		FORS(i, n) num = num *10 + a[i];
		if(num % 30 == 0) ans = max(ans, num);
		next_permutation(a, a + n);
	}
	cout << ans << endl;
	return 0;
}
