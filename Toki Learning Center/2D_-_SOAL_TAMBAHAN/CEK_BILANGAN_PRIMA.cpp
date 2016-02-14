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

bool prime[33000];

int main(void)
{
	int a, i, j;
	reset(prime, 1);
	prime[1] = 0;
	FOR(i, 2, 32000) {
		if(prime[i])
			for(j = i*i; j <= 32000; j += i)
				prime[j] = 0;
	}
	while(cin >> a) {
		if(a <= 0) {
			puts("TIDAK");
			continue;
		}
		puts(prime[a]? "YA" : "TIDAK");
	}
	
	return 0;
}
