#include <bits/stdc++.h>

/**
 * Codeforces Round #270
 * Problem : A
 * Luqman A. Siswanto (kadalbonek)
 */

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
const int N = 1e6 + 6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool is[N];

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	FOR(i, 2, N-1) {
		if(!is[i]) {
			if(1LL*i*i < N)
			for(j = 1LL*i*i; j < N; j += i) {
				is[j] = 1;
			}
		}
	}
	FOR(i, 2, n-1) {
		if(is[i] && is[n-i]) {
			pf("%d %d\n", i, n-i);
			return 0;
		}
	}
	
	return 0;
}
