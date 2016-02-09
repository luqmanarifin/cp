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

int n, m, k, node[305];
bool marked[305];

int main(void)
{
	int n, m, k, i, j;
	sf("%d %d %d", &n, &m, &k);
	int t = 0;
	FORS(i, k) {
		int x;
		sf("%d", &x);
		marked[x] = 1;
		node[t++] = x;
	}
	FOR(i, 1, n) if(!marked[i]) node[t++] = i;
	int magic = n*(n - 1)/2 - k + 1;
	if(n == k || m > magic) {
		puts("-1");
		return 0;
	}
	FOR(i, 1, n-1) {
		pf("%d %d\n", node[i], node[(i+1) % n]);
	}
	m -= n - 1;
	FOR(i, 1, n-1) {
		FOR(j, i+2, n-1) {
			if(m == 0) return 0;
			pf("%d %d\n", node[i], node[j]);
			m--;
		}
	}
	FOR(i, k, n-1)  {
		if(m == 0) return 0;
		pf("%d %d\n", node[i], node[0]);
		m--;
	}
	return 0;
}
