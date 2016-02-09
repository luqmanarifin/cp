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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int cur[N];
bool prime[N];

void masuk(int a) {
	if(prime[a]) cur[a]++;
	int i, j;
	for(i = 2; i*i <= a; i++)
		if(a % i == 0) {
			masuk(i);
			masuk(a/i);
			break;
		}
}

int main(void)
{
	int i, n, j;
	sf("%d", &n);
	reset(prime, 1);
	prime[0] = prime[1] = 0;
	for(i = 2; i*i <= n; ++i)
		if(prime[i]) {
			for(j = i*i; j <= n; j += i)
				prime[j] = 0;
		}
	if(n == 1 || prime[n]) {
		pf("%d\n", n);
		return 0;
	}
	masuk(n);
	bool next = 0;
	for(i = 2; i <= n; i++) if(cur[i]) {
		if(next) pf(" x ");
		pf("%d", i);
		if(cur[i] > 1) pf("^%d", cur[i]);
		if(!next) next = 1;
	}
	nl; return 0;
}
