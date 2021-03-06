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

int power(int a, int b) {
	if(!b) return 1;
	int temp = power(a, b/2);
	temp *= temp;
	if(temp > 1000) return -1000;
	if(b & 1) temp *= a;
	return temp;
}

int main(void)
{
	int a, b, n, x;
	sf("%d %d %d", &a, &b, &n);
	FORD(x, 1000, -1000)
		if(a*power(x, n) == b) {
			cout << x << endl;
			return 0;
		}
	puts("No solution");
	return 0;
}
