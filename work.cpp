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

int tot[3];

int main(void)
{
	int n, i, max = -1, pos;
	sf("%d", &n);
	FORS(i, n) {
		int a;
		sf("%d", &a);
		tot[i%3] += a;
	}
	FORS(i, 3) {
		if(tot[i] > max) {
			max = tot[i];
			pos = i;
		}
	}
	switch (pos) {
		case 0 : puts("chest"); break;
		case 1 : puts("biceps"); break;
		case 2 : puts("back"); break;
	}
	return 0;
}
