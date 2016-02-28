#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

bool done[1005];

int main(void)
{
	int t, tt, i, j, n;
	sf("%d", &t);
	while(t--) {
		reset(done, 0);
		bool valid = 1;
		sf("%d", &n);
		while(n--) {
			int a;
			sf("%d", &a);
			if(done[a]) valid = 0;
			else done[a] = 1;
		}
		puts(valid? "YES" : "NO");
	}
	
	return 0;
}
